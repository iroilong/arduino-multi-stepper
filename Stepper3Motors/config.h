#pragma once

const unsigned long SERIAL_BAUD_RATE = 115200;

// Motor IN1-IN4 pin assignments live in motion_plan.h so users only edit one file.

const long HALF_STEPS_PER_REVOLUTION = 4096;
const unsigned long MIN_STEP_INTERVAL_MICROS = 1500;

const float MOTOR_1_MOVE_DEGREES = 45.0;
const float MOTOR_2_MOVE_DEGREES = 70.0;
const float MOTOR_3_MOVE_DEGREES = 15.0;

const bool RELEASE_MOTOR_WHEN_IDLE = true;

// true：Arduino 一上電就自動開始三顆馬達動作。
// false：上電後等待 Serial Monitor 輸入 r 才開始。
const bool START_PROGRAMS_ON_POWER = true;
const unsigned long START_DELAY_MS = 0;

// Arduino Mega 2560 的板上 L LED 是 D13，也就是 ATmega2560 的 PB7。
const int HEARTBEAT_LED_PIN = LED_BUILTIN;
const unsigned long HEARTBEAT_BLINK_INTERVAL_MS = 500;
