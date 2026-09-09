## Quick Start
用 Arduino IDE 2 開啟 C:\BruceTsao\06_MCU\Arduino\Project\MEGA2560\20260909_Stepper3Motors\Stepper3Motors。狀態：Git 已初始化、硬體照片已確認、程式已改成三顆 Motor 1/2/3 各自執行動作，且 Arduino Mega 2560 clean compile 通過。一般使用者只需要修改 motion_plan.h 的「使用者設定區」。下一步：使用者核准後做第一次 commit，接著確認馬達 2 應為 70 度或 180 度，再只接馬達 1 測試。關鍵檔案：motion_plan.h、Stepper3Motors.ino、config.h、StepperMotor.cpp、docs/wiring.md。

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
