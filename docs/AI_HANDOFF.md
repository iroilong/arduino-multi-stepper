## Current Work Checkpoint
- Current objective: 使用 main branch 的純馬達轉動功能；使用者改變裝置擺放方式，不再需要限位開關
- Current step: 已從 feature/limit-switches 切換回 main branch；工作樹乾淨
- Last updated: 2026-09-30 02:15:00 Asia/Taipei
- Last agent: Claude Code

## Confirmed Facts
- 專案路徑：C:\BruceTsao\06_MCU\Arduino\Project\MEGA2560\20260909_Stepper3Motors\Stepper3Motors
- 控制板：Arduino Mega 2560 相容板
- 馬達與驅動：三套 28BYJ-48 12V DC 步進馬達與 ULN2003 類型驅動板（目前只有馬達 1 接線）
- Pin mapping: Motor 1 IN1/IN2/IN3/IN4 to D22/D24/D26/D28; Motor 2 to D30/D32/D34/D36; Motor 3 to D38/D40/D42/D44
- motion_plan.h 同時包含「使用者設定區 1：硬體接線」與「使用者設定區 2：馬達動作」
- 程式已改成上電自動開始馬達動作；Serial Monitor 仍保留資訊輸出與 r/s/? 指令
- PB7/D13 heartbeat LED 持續閃爍表示 MCU 運作中
- 目前在 main branch (2c53700)：純馬達轉動功能，無限位開關
- feature/limit-switches branch 已保留但不使用：包含 D23/D25 限位開關測試功能（commit 70cb4bb + e57f4b0）

## Assumptions
- 使用者改變裝置擺放方式後，馬達可以持續轉動而不會撞到障礙物
- ULN2003 馬達電源使用外部 12V 電源，Arduino GND 和外部 12V 電源負極共地
- 馬達 2 和 3 的 motion plan 會繼續執行，但因為未接線所以只有訊號輸出沒有實際馬達動作

## Open Issues / Blockers
- 馬達 2 和 3 尚未接線測試
- 外部 12V 電源電流規格尚未確認
- 馬達 2 描述包含「半圈」與「70 度」兩種資訊；需確認到底是 70 度還是 180 度

## Files Changed or Reviewed
- 無（切換 branch 操作不涉及檔案修改）

## Validation
- Tested: git checkout main 成功，工作樹乾淨
- Tested: git branch -a 確認 main 和 feature/limit-switches 都存在
- Tested: grep 確認 main branch 無 limit 相關程式碼
- Not run: 程式編譯與上傳（main branch 之前已驗證通過）
- Failed due to existing issue: N/A

## Next Safest Action
- main branch 已就緒，可以繼續使用或根據 Bruce 的需求進行新的開發
- 如果未來需要限位開關功能，可以用 `git checkout feature/limit-switches` 切換回去

## If Interrupted, Resume By
- Run git status, confirm on main branch, review README.md for current feature set
