## Quick Start
用 Arduino IDE 2 開啟 `Stepper3Motors/Stepper3Motors.ino`。Repo 與 Arduino Sketch 已分層；全部程式原始碼位於 `Stepper3Motors/`，一般使用者主要修改 `Stepper3Motors/motion_plan.h`。目前程式會讓三顆 Motor 1/2/3 各自執行動作；資料夾搬移後已使用 Arduino CLI 與 Mega 2560 目標重新編譯成功，並已發布至 GitHub。使用說明位於 `docs/使用說明.md`、`docs/使用說明.txt`、`docs/使用說明.pdf`。

## Timeline
- ✅ Confirmed - 2026-10-19: Committed the verified sketch-folder reorganization and published `main` to `https://github.com/iroilong/arduino-multi-stepper.git`.
- ✅ Confirmed - 2026-10-19: Verified the relocated `Stepper3Motors/Stepper3Motors.ino` with portable Arduino CLI 1.5.2-rc.1, Arduino AVR Boards 1.8.8, and FQBN `arduino:avr:mega`; compile passed using 6,944 bytes of flash and 930 bytes of dynamic memory.
- ✅ Confirmed - 2026-10-19: Separated the repository root from the Arduino Sketch root by moving all six source files into `Stepper3Motors/`; this preserves the required `Stepper3Motors/Stepper3Motors.ino` folder/file name match when the GitHub repository uses a different name.
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
