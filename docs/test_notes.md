# 測試紀錄

## 2026-09-09

- Arduino IDE 已安裝。
- Arduino IDE 曾偵測到 Arduino Mega 2560 在 COM7。
- 使用者回報 Blink 上傳成功。
- 照片確認硬體為三顆 28BYJ-48 12V DC 步進馬達與 ULN2003 類型驅動板。
- 專案已從 STEP/DIR 架構改成 ULN2003 IN1-IN4 控制。
- 使用者澄清不是 XYZ 軸控制，而是三顆馬達各自執行不同角度、停頓與來回動作。
- 架構調整為直接修改 `motion_plan.h`，不需要 Codex 轉換 CSV。
