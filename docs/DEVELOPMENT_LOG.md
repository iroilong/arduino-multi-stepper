## Quick Start
用 Arduino IDE 2 開啟 C:\BruceTsao\06_MCU\Arduino\Project\MEGA2560\20260909_Stepper3Motors\Stepper3Motors。狀態：Git 已初始化、硬體照片已確認、程式已改成三顆 Motor 1/2/3 各自執行動作，且 Arduino Mega 2560 clean compile 通過。一般使用者只需要打開 motion_plan.h；該檔同時包含「使用者設定區 1：硬體接線」與「使用者設定區 2：馬達動作」。目前已有繁中使用說明 docs/使用說明.md、docs/使用說明.txt、docs/使用說明.pdf。下一步：檢查本次 diff 後，依 Bruce 的 full approval flow 取得核准再 commit。關鍵檔案：motion_plan.h、Stepper3Motors.ino、config.h、docs/使用說明.md、docs/使用說明.txt、docs/使用說明.pdf。

## Timeline
- ✅ Confirmed - 2026-09-09: Arduino IDE 2 installed; user reported Blink upload success on Arduino Mega 2560.
- ✅ Confirmed - 2026-09-09: Initialized Git repository and created beginner-friendly three-stepper project skeleton.
- ✅ Confirmed - 2026-09-09: Starter skeleton compiled successfully with Arduino CLI FQBN arduino:avr:mega.
- ✅ Confirmed - 2026-09-09: User provided photos and confirmed three motor/driver sets; hardware identified as 28BYJ-48 12V motors with ULN2003-style driver boards.
- ✅ Confirmed - 2026-09-09: Updated project from STEP/DIR assumptions to ULN2003 IN1-IN4 half-step control; compile passed.
- ✅ Confirmed - 2026-09-09: User clarified this is not XYZ axis control; updated code and docs to Motor 1/2/3 independent timed back-and-forth programs; clean compile passed.
- ✅ Confirmed - 2026-09-09: Replaced the CSV-to-generated-header idea with a simpler direct-edit motion_plan.h workflow for non-programmer users; clean compile passed.
- ⚠️ Open Issue - 2026-09-09: Motor 2 wording includes both half-turn and 70 degrees; current code uses 70 degrees until confirmed otherwise.
- ⚠️ Open Issue - 2026-09-09: External 12V power supply current rating, physical wiring, and real movement direction are not confirmed yet.
- ✅ Confirmed - 2026-09-09: Changed motor wiring pin plan to same-side even-numbered Mega header pins: Motor 1 D22/D24/D26/D28, Motor 2 D30/D32/D34/D36, Motor 3 D38/D40/D42/D44.
- ✅ Confirmed - 2026-09-09: Changed startup behavior to auto-start motor programs on power-up while keeping Serial Monitor output and r/s/? commands available.
- ✅ Confirmed - 2026-09-09: Added PB7/D13 heartbeat LED blink so users can see the MCU is alive after power-up.
- ✅ Confirmed - 2026-09-09: User uploaded heartbeat LED build successfully from Arduino IDE and confirmed PB7/D13 onboard L LED blink.
- ✅ Confirmed - 2026-09-09: Added standalone Traditional Chinese user guide for wiring, editing motion_plan.h, and uploading with Arduino IDE.
- ✅ Confirmed - 2026-09-09: Renamed the standalone user guide to docs/使用說明.md so non-programmer users can identify it more easily.
- ✅ Confirmed - 2026-09-09: Generated docs/使用說明.txt and docs/使用說明.pdf from the same Traditional Chinese guide content for users who may not be able to open Markdown files.
- ✅ Confirmed - 2026-09-10: Moved Motor 1/2/3 ULN2003 IN1-IN4 pin assignments into motion_plan.h so users can see wiring and motion plan in one file; Arduino Mega 2560 clean compile passed.
- ✅ Confirmed - 2026-09-10: Updated user guide upload instructions to prioritize the Arduino IDE 2 top-left Board/Port selector, with Tools menu only as a fallback.
