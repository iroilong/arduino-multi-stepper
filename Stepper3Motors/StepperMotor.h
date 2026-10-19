#pragma once

#include <Arduino.h>

class StepperMotor {
public:
  StepperMotor(const char *motorName, int in1Pin, int in2Pin, int in3Pin, int in4Pin);

  void begin();
  void setStepIntervalMicros(unsigned long intervalMicros);
  void moveSteps(long halfSteps);
  void run();
  void stop();
  void release();
  bool isRunning() const;
  const char *name() const;

private:
  const char *motorName;
  int pins[4];
  int stepIndex;
  int direction;
  long stepsRemaining;
  unsigned long stepIntervalMicros;
  unsigned long lastStepMicros;

  void writeStep(int sequenceIndex);
};
