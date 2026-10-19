#pragma once

#include <Arduino.h>

// ============================================================
// 使用者設定區 1：硬體接線
// ============================================================
// 這裡記錄每片 ULN2003 驅動板的 IN1、IN2、IN3、IN4 要接到 Arduino Mega 2560 哪些 pin。
// 如果未來改接線，請只改下面這些 pin 數字，並確認實際線路也一起更改。
//
// 馬達 1：IN1 -> D22, IN2 -> D24, IN3 -> D26, IN4 -> D28
// 馬達 2：IN1 -> D30, IN2 -> D32, IN3 -> D34, IN4 -> D36
// 馬達 3：IN1 -> D38, IN2 -> D40, IN3 -> D42, IN4 -> D44

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

// ============================================================
// 系統區：一般使用者不要修改
// ============================================================
// 請往下找到「使用者設定區 2」，調整 MOTOR_1_PLAN、MOTOR_2_PLAN、MOTOR_3_PLAN。

enum MotionAction {
  MOTION_PAUSE,
  MOTION_MOVE,
};

struct MotionStep {
  MotionAction action;
  float degrees;
  unsigned long durationMs;
};

#define SECONDS_TO_MS(seconds) ((unsigned long)((seconds) * 1000.0))
#define PAUSE_SECONDS(seconds) { MOTION_PAUSE, 0.0, SECONDS_TO_MS(seconds) }
#define MOVE_DEGREES(degrees, seconds) { MOTION_MOVE, (degrees), SECONDS_TO_MS(seconds) }

// ============================================================
// 使用者設定區 2：馬達動作
// ============================================================
//
// 可用格式：
//   PAUSE_SECONDS(秒數),
//   MOVE_DEGREES(角度, 秒數),
//
// 例子：
//   PAUSE_SECONDS(3),       代表停 3 秒
//   MOVE_DEGREES(45, 10),   代表正轉 45 度，約 10 秒完成
//   MOVE_DEGREES(-45, 10),  代表反轉 45 度，約 10 秒完成
//
// 注意：
// - 每一行最後都要有逗號。
// - 角度用正數代表一個方向，負數代表反方向。
// - 這三個清單會一直重複執行，直到使用者送出停止指令。
// - 如果馬達方向和預期相反，把角度正負號對調即可。

const MotionStep MOTOR_1_PLAN[] = {
  PAUSE_SECONDS(3),
  MOVE_DEGREES(45, 10),
  PAUSE_SECONDS(3),
  MOVE_DEGREES(-45, 10),
  MOVE_DEGREES(45, 10),
  MOVE_DEGREES(-45, 10),
};

const MotionStep MOTOR_2_PLAN[] = {
  MOVE_DEGREES(70, 15),
  PAUSE_SECONDS(10),
  MOVE_DEGREES(-70, 10),
  MOVE_DEGREES(70, 10),
};

const MotionStep MOTOR_3_PLAN[] = {
  MOVE_DEGREES(15, 1),
  PAUSE_SECONDS(2),
  MOVE_DEGREES(-15, 5),
};

// ============================================================
// 自動計算區：一般使用者不要修改
// ============================================================

const int MOTOR_1_PLAN_COUNT = sizeof(MOTOR_1_PLAN) / sizeof(MOTOR_1_PLAN[0]);
const int MOTOR_2_PLAN_COUNT = sizeof(MOTOR_2_PLAN) / sizeof(MOTOR_2_PLAN[0]);
const int MOTOR_3_PLAN_COUNT = sizeof(MOTOR_3_PLAN) / sizeof(MOTOR_3_PLAN[0]);
