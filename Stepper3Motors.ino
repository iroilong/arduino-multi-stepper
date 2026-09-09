#include "config.h"
#include "commands.h"
#include "motion_plan.h"
#include "StepperMotor.h"

struct MotionProgramState {
  StepperMotor *motor;
  const MotionStep *steps;
  int stepCount;
  int currentStep;
  bool stepActive;
  bool stepIsMove;
  unsigned long stepStartMs;
};

StepperMotor motor1("Motor 1", M1_IN1_PIN, M1_IN2_PIN, M1_IN3_PIN, M1_IN4_PIN);
StepperMotor motor2("Motor 2", M2_IN1_PIN, M2_IN2_PIN, M2_IN3_PIN, M2_IN4_PIN);
StepperMotor motor3("Motor 3", M3_IN1_PIN, M3_IN2_PIN, M3_IN3_PIN, M3_IN4_PIN);

MotionProgramState motor1Program = {&motor1, MOTOR_1_PLAN, MOTOR_1_PLAN_COUNT, 0, false, false, 0};
MotionProgramState motor2Program = {&motor2, MOTOR_2_PLAN, MOTOR_2_PLAN_COUNT, 0, false, false, 0};
MotionProgramState motor3Program = {&motor3, MOTOR_3_PLAN, MOTOR_3_PLAN_COUNT, 0, false, false, 0};

bool programsRunning = false;
bool heartbeatLedOn = false;
unsigned long lastHeartbeatToggleMs = 0;

void setupHeartbeatLed() {
  pinMode(HEARTBEAT_LED_PIN, OUTPUT);
  digitalWrite(HEARTBEAT_LED_PIN, LOW);
}

void updateHeartbeatLed() {
  unsigned long now = millis();

  if (now - lastHeartbeatToggleMs < HEARTBEAT_BLINK_INTERVAL_MS) {
    return;
  }

  lastHeartbeatToggleMs = now;
  heartbeatLedOn = !heartbeatLedOn;
  digitalWrite(HEARTBEAT_LED_PIN, heartbeatLedOn ? HIGH : LOW);
}

long degreesToHalfSteps(float degrees) {  float positiveDegrees = degrees < 0 ? -degrees : degrees;
  long halfSteps = (long)((positiveDegrees * HALF_STEPS_PER_REVOLUTION / 360.0) + 0.5);
  return halfSteps < 1 ? 1 : halfSteps;
}

unsigned long durationToStepIntervalMicros(unsigned long durationMs, long halfSteps) {
  unsigned long interval = (durationMs * 1000UL) / halfSteps;
  return interval < MIN_STEP_INTERVAL_MICROS ? MIN_STEP_INTERVAL_MICROS : interval;
}

void printHelp() {
  Serial.println();
  Serial.println("Stepper3Motors 指令:");
  Serial.println("  ? = 顯示說明");
  Serial.println("  r = 開始或重新開始三顆馬達動作");
  Serial.println("  上電後會自動開始；沒有接 USB 也會動作");
  Serial.println("  PB7/D13 板上 LED 會持續閃爍，表示 MCU 還在運作");
  Serial.println("  s = 停止並釋放三顆馬達");
  Serial.println();
}

void resetProgram(MotionProgramState &program) {
  program.currentStep = 0;
  program.stepActive = false;
  program.stepIsMove = false;
  program.stepStartMs = 0;
  program.motor->stop();
}

void startProgramStep(MotionProgramState &program) {
  const MotionStep &step = program.steps[program.currentStep];

  program.stepActive = true;
  program.stepStartMs = millis();
  program.stepIsMove = step.action == MOTION_MOVE;

  Serial.print(program.motor->name());
  Serial.print(" 動作 ");
  Serial.print(program.currentStep + 1);
  Serial.print("/");
  Serial.print(program.stepCount);

  if (step.action == MOTION_PAUSE) {
    program.motor->release();
    Serial.print(": 停 ");
    Serial.print(step.durationMs / 1000.0);
    Serial.println(" 秒");
    return;
  }

  long halfSteps = degreesToHalfSteps(step.degrees);
  unsigned long intervalMicros = durationToStepIntervalMicros(step.durationMs, halfSteps);

  if (step.degrees < 0) {
    halfSteps = -halfSteps;
  }

  program.motor->setStepIntervalMicros(intervalMicros);
  program.motor->moveSteps(halfSteps);

  Serial.print(": 轉 ");
  Serial.print(step.degrees);
  Serial.print(" 度，約 ");
  Serial.print(step.durationMs / 1000.0);
  Serial.println(" 秒");
}

void advanceProgram(MotionProgramState &program) {
  program.currentStep++;
  if (program.currentStep >= program.stepCount) {
    program.currentStep = 0;
  }
  program.stepActive = false;
}

void updateProgram(MotionProgramState &program) {
  if (!program.stepActive) {
    startProgramStep(program);
    return;
  }

  const MotionStep &step = program.steps[program.currentStep];

  if (program.stepIsMove) {
    program.motor->run();
    if (!program.motor->isRunning()) {
      advanceProgram(program);
    }
    return;
  }

  if (millis() - program.stepStartMs >= step.durationMs) {
    advanceProgram(program);
  }
}

void startAllPrograms() {
  resetProgram(motor1Program);
  resetProgram(motor2Program);
  resetProgram(motor3Program);
  programsRunning = true;
  Serial.println("三顆馬達動作開始。");
}

void stopAllPrograms() {
  programsRunning = false;
  resetProgram(motor1Program);
  resetProgram(motor2Program);
  resetProgram(motor3Program);
  Serial.println("三顆馬達已停止並釋放。");
}

void handleCommand(char command) {
  switch (command) {
    case COMMAND_HELP:
      printHelp();
      break;
    case COMMAND_START:
      startAllPrograms();
      break;
    case COMMAND_STOP:
      stopAllPrograms();
      break;
    case '\n':
    case '\r':
      break;
    default:
      Serial.println("未知指令，請輸入 ? 查看說明。");
      break;
  }
}

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  setupHeartbeatLed();

  motor1.begin();
  motor2.begin();
  motor3.begin();

  Serial.println("Stepper3Motors 已準備好。");
  printHelp();

  if (START_PROGRAMS_ON_POWER) {
    if (START_DELAY_MS > 0) {
      delay(START_DELAY_MS);
    }
    startAllPrograms();
  } else {
    stopAllPrograms();
  }
}

void loop() {
  updateHeartbeatLed();
  while (Serial.available() > 0) {
    handleCommand(Serial.read());
  }

  if (!programsRunning) {
    return;
  }

  updateProgram(motor1Program);
  updateProgram(motor2Program);
  updateProgram(motor3Program);
}
