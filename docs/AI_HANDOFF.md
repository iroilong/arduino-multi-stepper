## Current Work Checkpoint
- Current objective: 維護已完成分層、驗證並發布至 GitHub 的 Arduino 專案
- Current step: 資料夾搬移、文件更新、PDF 驗證、Mega 2560 CLI 編譯、commit 與首次 push 均已完成；main 追蹤 origin/main
- Last updated: 2026-10-19 Asia/Taipei
- Last agent: Codex

## Confirmed Facts
- 目前本機 Repo 路徑：C:\Users\nuc8\Downloads\Stepper3Motors
- GitHub remote origin：https://github.com/iroilong/arduino-multi-stepper.git
- Arduino Sketch 已放在 Repo 內的 Stepper3Motors/ 子目錄，主檔為 Stepper3Motors/Stepper3Motors.ino
- 控制板：Arduino Mega 2560 相容板
- 馬達與驅動：三套 28BYJ-48 12V DC 步進馬達與 ULN2003 類型驅動板（目前只有馬達 1 接線）
- Pin mapping: Motor 1 IN1/IN2/IN3/IN4 to D22/D24/D26/D28; Motor 2 to D30/D32/D34/D36; Motor 3 to D38/D40/D42/D44
- motion_plan.h 同時包含「使用者設定區 1：硬體接線」與「使用者設定區 2：馬達動作」
- 程式已改成上電自動開始馬達動作；Serial Monitor 仍保留資訊輸出與 r/s/? 指令
- PB7/D13 heartbeat LED 持續閃爍表示 MCU 運作中
- 目前在 main branch：純馬達轉動功能，無限位開關；本次資料夾搬遷已 commit 並發布至 origin/main
- feature/limit-switches branch 已保留但不使用：包含 D23/D25 限位開關測試功能（commit 70cb4bb + e57f4b0）

## Assumptions
- 使用者改變裝置擺放方式後，馬達可以持續轉動而不會撞到障礙物
- ULN2003 馬達電源使用外部 12V 電源，Arduino GND 和外部 12V 電源負極共地
- 馬達 2 和 3 的 motion plan 會繼續執行，但因為未接線所以只有訊號輸出沒有實際馬達動作

## Open Issues / Blockers
- 馬達 2 和 3 尚未接線測試
- 外部 12V 電源電流規格尚未確認
- 馬達 2 描述包含「半圈」與「70 度」兩種資訊；需確認到底是 70 度還是 180 度
- 實體 Arduino Mega 2560 上傳與馬達動作尚未在本次搬移後重新測試

## Files Changed or Reviewed
- Renamed: Stepper3Motors.ino、StepperMotor.cpp、StepperMotor.h、commands.h、config.h、motion_plan.h 全部移至 Stepper3Motors/
- Changed: README.md、docs/how_to_edit_motion_plan.md、docs/wiring.md、docs/使用說明.md、docs/使用說明.txt（更新 Sketch 與 motion_plan 路徑）
- Changed: docs/使用說明.pdf（依更新後 Markdown 重新產生）
- Changed: docs/AI_HANDOFF.md、docs/DEVELOPMENT_LOG.md（更新目前狀態、快速開始與架構決策）

## Validation
- Tested: 6 個原始碼均為 100% Git rename，無程式內容增刪
- Tested: Sketch 子目錄包含完整 6 個原始碼，Repo 根目錄已無 .ino/.cpp/.h
- Tested: git diff --check 通過；舊 C:\BruceTsao 絕對路徑及舊開啟方式搜尋結果為零
- Tested: docs/使用說明.pdf 共 5 頁；逐頁渲染確認無缺字、裁切、重疊或表格跨頁；文字抽取確認包含兩個新路徑
- Tested: 使用可攜式 arduino-cli 1.5.2-rc.1、Arduino AVR Boards 1.8.8 與 FQBN arduino:avr:mega 編譯搬遷後的 Sketch 成功；程式空間 6,944 bytes（2%），動態記憶體 930 bytes（11%）
- Not run: 實體 Arduino Mega 2560 上傳與馬達動作測試
- Failed due to existing issue: N/A

## Next Safest Action
- 若要進行硬體驗證，接上 Arduino Mega 2560 後確認 COM port，再於馬達安全斷電的情況下準備上傳

## If Interrupted, Resume By
- Run git status and git remote -v; do not repeat the completed move, CLI compile, commit, or initial push；依 Bruce 下一項明確需求繼續
