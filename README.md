# Stepper3Motors

這是 Arduino Mega 2560 專案，用來控制三顆 `28BYJ-48 12V` 步進馬達，每顆馬達搭配一片 `ULN2003` 驅動板。

## 給一般使用者

如果只是要調整馬達動作，通常只需要修改這個檔案：

```text
motion_plan.h
```

請在 `motion_plan.h` 裡找到「使用者設定區」，修改三個清單：

- `MOTOR_1_PLAN`：馬達 1 的動作
- `MOTOR_2_PLAN`：馬達 2 的動作
- `MOTOR_3_PLAN`：馬達 3 的動作

常用格式：

```cpp
PAUSE_SECONDS(3),       // 停 3 秒
MOVE_DEGREES(45, 10),   // 正轉 45 度，約 10 秒完成
MOVE_DEGREES(-45, 10),  // 反轉 45 度，約 10 秒完成
```

## 硬體

- 控制板：Arduino Mega 2560 相容板
- 馬達：三顆 28BYJ-48 12V DC 步進馬達
- 驅動板：三片 ULN2003 步進馬達驅動板
- 電源：需要外部 12V 馬達電源

## 開發工具

- Arduino IDE 2
- Board：Arduino Mega or Mega 2560
- Processor：ATmega2560 (Mega 2560)

## 接線規劃

| 馬達 | IN1 | IN2 | IN3 | IN4 |
| --- | ---: | ---: | ---: | ---: |
| 馬達 1 | 22 | 24 | 26 | 28 |
| 馬達 2 | 30 | 32 | 34 | 36 |
| 馬達 3 | 38 | 40 | 42 | 44 |

## 操作方式

1. 用 Arduino IDE 開啟 `Stepper3Motors.ino`。
2. 選擇 `Arduino Mega or Mega 2560` 與正確的 COM port。
3. 上傳程式到 Arduino。
4. 打開 Serial Monitor，baud rate 選 `115200`。
5. 輸入 `r` 開始動作，輸入 `s` 停止。

## Serial Monitor 指令

| 指令 | 功能 |
| --- | --- |
| `?` | 顯示說明 |
| `r` | 開始或重新開始三顆馬達動作 |
| `s` | 停止並釋放三顆馬達 |

## 安全注意事項

- 不要把步進馬達直接接到 Arduino 腳位。
- 不要用 Arduino 的 `5V` 腳供應這顆 `12V` 馬達。
- ULN2003 驅動板的馬達電源請接外部 `12V` 電源。
- Arduino `GND` 要和外部 12V 電源負極共地。
- 改接線前請先拔掉馬達電源。
