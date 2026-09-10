## Current Work Checkpoint
- Current objective: 建立 Arduino Mega 2560 專案，控制三顆 28BYJ-48 12V 步進馬達，並讓非程式使用者只看 motion_plan.h 即可了解 pin 對接與 motion plan
- Current step: 已將 Motor 1/2/3 IN1-IN4 pin 定義移到 motion_plan.h，並同步更新 Arduino IDE 2 左上角 Board/Port 選單的燒錄說明；尚未 commit
- Last updated: 2026-09-10 16:34:16 Asia/Taipei
- Last agent: Codex

## Confirmed Facts
- 專案路徑：C:\BruceTsao\06_MCU\Arduino\Project\MEGA2560\20260909_Stepper3Motors\Stepper3Motors
- 控制板：Arduino Mega 2560 相容板
- 馬達與驅動：三套 28BYJ-48 12V DC 步進馬達與 ULN2003 類型驅動板
- Pin mapping now lives in motion_plan.h: Motor 1 IN1/IN2/IN3/IN4 to D22/D24/D26/D28; Motor 2 to D30/D32/D34/D36; Motor 3 to D38/D40/D42/D44
- config.h no longer contains Motor 1/2/3 IN1-IN4 pin assignments; it keeps system settings such as serial baud rate, motor constants, auto-start, and heartbeat LED
- motion_plan.h 同時包含「使用者設定區 1：硬體接線」與「使用者設定區 2：馬達動作」
- Arduino IDE 2 燒錄說明已改為優先使用左上角 Board/Port 選單；Tools 選單只保留為備用方式
- 程式已改成上電自動開始馬達動作；Serial Monitor 仍保留資訊輸出與 r/s/? 指令
- PB7/D13 heartbeat LED 已加入；使用者已用 Arduino IDE 上傳成功並確認板上 L LED blink
- docs/使用說明.md、docs/使用說明.txt、docs/使用說明.pdf 已同步說明同一個檔案包含 pin 對接與 motion plan
- Codex 執行 git 指令時需加單次 safe.directory，原因是資料夾擁有者與 sandbox 使用者不同

## Assumptions
- 既有未提交的 Motor 3 時間調整是使用者測試需要，已保留：MOVE_DEGREES(15, 1)、PAUSE_SECONDS(2)、MOVE_DEGREES(-15, 5)
- ULN2003 馬達電源會使用外部 12V 電源，Arduino GND 會和外部 12V 電源負極共地

## Open Issues / Blockers
- Upload attempt: Arduino CLI upload to COM7 failed with Access is denied; 使用者改用 Arduino IDE 上傳成功
- 外部 12V 電源電流規格尚未確認
- 馬達 2 描述包含「半圈」與「70 度」兩種資訊；需確認到底是 70 度還是 180 度
- docs/photos/ 與 docs/ArduinoDatasheet/ 目前為未追蹤資料；未經使用者要求不要加入 commit
- 長軸可能撞牆；後續若要防撞，需要限位開關或絕對角度感測方案

## Files Changed or Reviewed
- motion_plan.h: 新增「使用者設定區 1：硬體接線」，保存 Motor 1/2/3 IN1-IN4 pin 對接；原 motion plan 移為「使用者設定區 2」
- config.h: 移除 Motor 1/2/3 IN1-IN4 pin 定義，避免使用者需要同時看兩個檔案
- README.md: 更新一般使用者說明，指出 motion_plan.h 同時包含硬體接線與動作設定，並優先使用 Arduino IDE 左上角 Board/Port 選單
- docs/how_to_edit_motion_plan.md: 更新為接線與馬達動作修改說明
- docs/wiring.md: 補充 pin 對接也在 motion_plan.h
- docs/使用說明.md: 同步更新使用說明，包含 Arduino IDE 左上角 Board/Port 選單流程
- docs/使用說明.txt: 由更新後 docs/使用說明.md 重新產生
- docs/使用說明.pdf: 由更新後 docs/使用說明.md 重新產生
- docs/AI_HANDOFF.md: 更新目前交接狀態與驗證結果
- docs/DEVELOPMENT_LOG.md: 補充本次設定檔整合的歷史紀錄

## Validation
- Tested: C:\Users\btsao\AppData\Local\Programs\Arduino IDE\resources\app\lib\backend\resources\arduino-cli.exe compile --clean --fqbn arduino:avr:mega C:\BruceTsao\06_MCU\Arduino\Project\MEGA2560\20260909_Stepper3Motors\Stepper3Motors - passed; sketch uses 6944 bytes flash and 930 bytes RAM
- Tested: Regenerated docs/使用說明.txt from docs/使用說明.md; file size checked as 5615 bytes
- Tested: Regenerated docs/使用說明.pdf from docs/使用說明.md; file size checked as 140265 bytes and PDF header checked as %PDF-
- Tested: pypdf opened docs/使用說明.pdf, counted 4 pages, and extracted readable Traditional Chinese text from page 1 with PYTHONIOENCODING=utf-8
- Not run: Arduino upload not run because COM7 may be in use and user previously uploads through Arduino IDE
- Failed due to existing issue: N/A

## Next Safest Action
- Review git diff/status with Bruce, then ask for explicit approval before committing this one logical change

## If Interrupted, Resume By
- Run git status with safe.directory, review motion_plan.h/config.h/docs changes, confirm Arduino compile and PDF regeneration results, then continue with the commit approval flow if Bruce asks to commit
