# **ESP32 Smart Lock**

A modular, password-protected locking system using a 4x4 keypad, servo, and 1602 LCD display. Designed for embedded environments and expandable with EEPROM storage and lockout security.

---

## Quickstart

This project is built using [PlatformIO](https://platformio.org/) for use with VS Code. Experience with embedded development and serial debugging is expected.

> NOTE: You must have PlatformIO and a supported toolchain for ESP32 installed on your system. Learn how to get started with PlatformIO [here](https://docs.platformio.org/en/latest/integration/ide/vscode.html).

---

###  Install dependencies

Ensure you have PlatformIO installed.

#### On Linux/macOS:

```bash
pip install platformio
```
---
### Features
 Features
 4-digit PIN entry using 4x4 matrix keypad

 LCD feedback for PIN progress and system messages

 Servo motor control for real-time locking

 EEPROM-backed PIN storage

 PIN change functionality with confirmation

 Lockout security after multiple failed attempts