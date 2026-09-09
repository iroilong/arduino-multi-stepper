#pragma once

const unsigned long SERIAL_BAUD_RATE = 115200;

const int M1_IN1_PIN = 22;
const int M1_IN2_PIN = 24;
const int M1_IN3_PIN = 26;
const int M1_IN4_PIN = 28;

const int M2_IN1_PIN = 30;
const int M2_IN2_PIN = 32;
const int M2_IN3_PIN = 34;
const int M2_IN4_PIN = 36;

const int M3_IN1_PIN = 38;
const int M3_IN2_PIN = 40;
const int M3_IN3_PIN = 42;
const int M3_IN4_PIN = 44;

const long HALF_STEPS_PER_REVOLUTION = 4096;
const unsigned long MIN_STEP_INTERVAL_MICROS = 1500;

const float MOTOR_1_MOVE_DEGREES = 45.0;
const float MOTOR_2_MOVE_DEGREES = 70.0;
const float MOTOR_3_MOVE_DEGREES = 15.0;

const bool RELEASE_MOTOR_WHEN_IDLE = true;
