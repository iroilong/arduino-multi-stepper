## Current Work Checkpoint
- Current objective: 建立 Arduino Mega 2560 專案，控制三顆 28BYJ-48 12V 步進馬達各自執行可調整動作
- Current step: Mega 2560 同側偶數 header 腳位規劃已 commit，commit hash: 5d5fecb
- Last updated: 2026-09-09 21:15:09 Asia/Taipei
- Last agent: Codex

## Confirmed Facts
- Datasheet/pinout check: D22/D24/D26/D28, D30/D32/D34/D36, and D38/D40/D42/D44 are digital I/O capable pins on the Mega 2560 header.
- 專案路徑：C:\BruceTsao\06_MCU\Arduino\Project\MEGA2560\20260909_Stepper3Motors\Stepper3Motors
- 控制板：Arduino Mega 2560 相容板
- Arduino IDE 2 已安裝
- Arduino IDE 先前偵測到 Arduino Mega 2560 在 COM7
- 使用者先前回報 Blink 上傳成功
- 使用者確認有三套馬達與驅動板
- 照片確認為 28BYJ-48 12V DC 步進馬達與 ULN2003 類型驅動板
- Git repository 已初始化
- 初始架構 commit 已完成
- Pin mapping commit completed: 5d5fecb
- 目前程式使用 Motor 1/2/3 命名，不使用 X/Y/Z 軸命名
- motion_plan.h 是主要使用者可編輯動作設定檔
- 目前程式可用 Arduino CLI 以 FQBN arduino:avr:mega clean compile 通過

## Assumptions
- 馬達 1：停 3 秒，正轉 45 度約 10 秒，停 3 秒，接著反轉/正轉/反轉各 45 度約 10 秒
- 馬達 2：正轉 70 度約 15 秒，停 10 秒，接著反轉 70 度約 10 秒，再正轉 70 度約 10 秒；目前先照 70 度，不是 180 度
- 馬達 3：正轉 15 度約 5 秒，停 20 秒，反轉 15 度約 5 秒
- 正角度與負角度代表相反方向；若實體方向相反，可在 motion_plan.h 對調正負號
- 初始訊號腳位：馬達 1 使用 D22/D24/D26/D28，馬達 2 使用 D30/D32/D34/D36，馬達 3 使用 D38/D40/D42/D44
- ULN2003 馬達電源會使用外部 12V 電源
- Arduino GND 會和外部 12V 電源負極共地

## Open Issues / Blockers
- 外部 12V 電源電流規格尚未確認
- 馬達 2 描述包含「半圈」與「70 度」兩種資訊；需確認到底是 70 度還是 180 度
- 實體接線尚未驗證
- 修改後的動作程式尚未 upload 到板子
- Codex 執行 git 指令時需加單次 safe.directory，原因是資料夾擁有者與 sandbox 使用者不同

## Files Changed or Reviewed
- Stepper3Motors.ino: 三顆獨立馬達依 motion_plan.h 執行動作，透過 Serial start/stop 控制
- config.h: Motor 1/2/3 ULN2003 腳位與馬達常數；已改成同側偶數 header pin
- StepperMotor.h: 28BYJ-48/ULN2003 馬達類別介面
- StepperMotor.cpp: 非阻塞半步進控制實作
- commands.h: Serial help/start/stop 指令常數
- motion_plan.h: 一般使用者直接編輯的三馬達動作表
- README.md: 繁中使用流程與安全注意事項
- docs/how_to_edit_motion_plan.md: 給一般使用者的 motion_plan.h 修改說明
- docs/wiring.md: Motor 1/2/3 ULN2003 接線規劃
- docs/motor_settings.md: 目前角度、時間與待確認項目
- docs/test_notes.md: 測試與硬體確認紀錄
- docs/photos/: 使用者提供的硬體照片已檢視但未 commit
- docs/AI_HANDOFF.md: 目前交接狀態
- docs/DEVELOPMENT_LOG.md: 專案歷史紀錄

## Validation
- Tested: C:\Users\btsao\AppData\Local\Programs\Arduino IDE\resources\app\lib\backend\resources\arduino-cli.exe compile --clean --fqbn arduino:avr:mega C:\BruceTsao\06_MCU\Arduino\Project\MEGA2560\20260909_Stepper3Motors\Stepper3Motors - passed before commit
- Not run: 尚未 upload 到板子；尚未接線實測；amend 僅更新交接文字，未重新編譯
- Failed due to existing issue: N/A

## Next Safest Action
- 檢查並 commit pin 定義變更；接著確認馬達 2 是 70 度或 180 度，然後只接馬達 1 測試上傳與實體動作

## If Interrupted, Resume By
- Run git status, review motion_plan.h, confirm Motor 2 angle intent, then continue with Motor 1 wiring test
