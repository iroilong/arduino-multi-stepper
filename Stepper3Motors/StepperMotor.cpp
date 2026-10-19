#include "StepperMotor.h"
#include "config.h"

static const byte HALF_STEP_SEQUENCE[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1},
};

StepperMotor::StepperMotor(const char *motorName, int in1Pin, int in2Pin, int in3Pin, int in4Pin)
  : motorName(motorName),
    pins{in1Pin, in2Pin, in3Pin, in4Pin},
    stepIndex(0),
    direction(1),
    stepsRemaining(0),
    stepIntervalMicros(MIN_STEP_INTERVAL_MICROS),
    lastStepMicros(0) {
}

void StepperMotor::begin() {
  for (int index = 0; index < 4; index++) {
    pinMode(pins[index], OUTPUT);
  }

  release();
}

void StepperMotor::setStepIntervalMicros(unsigned long intervalMicros) {
  stepIntervalMicros = intervalMicros;
}

void StepperMotor::moveSteps(long halfSteps) {
  if (halfSteps == 0) {
    return;
  }

  direction = halfSteps > 0 ? 1 : -1;
  stepsRemaining = halfSteps > 0 ? halfSteps : -halfSteps;
  lastStepMicros = 0;
}

void StepperMotor::run() {
  if (stepsRemaining <= 0) {
    return;
  }

  unsigned long now = micros();
  if (lastStepMicros != 0 && now - lastStepMicros < stepIntervalMicros) {
    return;
  }

  lastStepMicros = now;
  stepIndex += direction;

  if (stepIndex > 7) {
    stepIndex = 0;
  } else if (stepIndex < 0) {
    stepIndex = 7;
  }

  writeStep(stepIndex);
  stepsRemaining--;

  if (stepsRemaining == 0 && RELEASE_MOTOR_WHEN_IDLE) {
    release();
  }
}

void StepperMotor::stop() {
  stepsRemaining = 0;
  release();
}

void StepperMotor::release() {
  for (int index = 0; index < 4; index++) {
    digitalWrite(pins[index], LOW);
  }
}

bool StepperMotor::isRunning() const {
  return stepsRemaining > 0;
}

const char *StepperMotor::name() const {
  return motorName;
}

void StepperMotor::writeStep(int sequenceIndex) {
  for (int index = 0; index < 4; index++) {
    digitalWrite(pins[index], HALF_STEP_SEQUENCE[sequenceIndex][index]);
  }
}
