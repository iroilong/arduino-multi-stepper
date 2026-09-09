#pragma once

#include <Arduino.h>

// ============================================================
// 系統區：一般使用者不要修改
// ============================================================
// 請往下找到「使用者設定區」，只修改 MOTOR_1_PLAN、MOTOR_2_PLAN、MOTOR_3_PLAN。

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
// 使用者設定區：在這裡調整三顆馬達的動作
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
  MOVE_DEGREES(15, 5),
  PAUSE_SECONDS(20),
  MOVE_DEGREES(-15, 5),
};

// ============================================================
// 自動計算區：一般使用者不要修改
// ============================================================

const int MOTOR_1_PLAN_COUNT = sizeof(MOTOR_1_PLAN) / sizeof(MOTOR_1_PLAN[0]);
const int MOTOR_2_PLAN_COUNT = sizeof(MOTOR_2_PLAN) / sizeof(MOTOR_2_PLAN[0]);
const int MOTOR_3_PLAN_COUNT = sizeof(MOTOR_3_PLAN) / sizeof(MOTOR_3_PLAN[0]);
