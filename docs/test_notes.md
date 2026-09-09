# 測試紀錄

## 2026-09-09

- Arduino IDE 已安裝。
- Arduino IDE 曾偵測到 Arduino Mega 2560 在 COM7。
- 使用者回報 Blink 上傳成功。
- 照片確認硬體為三顆 28BYJ-48 12V DC 步進馬達與 ULN2003 類型驅動板。
- 專案已從 STEP/DIR 架構改成 ULN2003 IN1-IN4 控制。
- 使用者澄清不是 XYZ 軸控制，而是三顆馬達各自執行不同角度、停頓與來回動作。
- 架構調整為直接修改 `motion_plan.h`，不需要 Codex 轉換 CSV。
- 腳位已改成同側偶數腳位：馬達 1 使用 D22/D24/D26/D28，馬達 2 使用 D30/D32/D34/D36，馬達 3 使用 D38/D40/D42/D44。
- 程式已改成上電自動開始馬達動作；Serial Monitor 仍保留資訊輸出與 `r`/`s`/`?` 指令。
- 嘗試用 Arduino CLI 上傳到 COM7 失敗：COM7 存取被拒，可能被 Arduino IDE Serial Monitor 或其他程式占用。
- 新增 PB7/D13 板上 LED heartbeat；上電後會持續閃爍，Serial Monitor 仍保留輸出與控制指令。
- 使用者回報目前馬達動作正常，下一步新增 PB7/D13 heartbeat LED 觀察 MCU 是否仍在執行。
- heartbeat 版本上傳 COM7 失敗：Access is denied，COM7 可能被 Arduino IDE Serial Monitor/Plotter 或其他程式占用。
- 使用者用 Arduino IDE 上傳 heartbeat 版本成功，並確認 PB7/D13 板上 L LED 有閃爍。
