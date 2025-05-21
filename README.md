# **ESP32 Smart Lock**

A modular, password-protected locking system using a 4x4 keypad, LCD display, and an electric strike lock. Designed for embedded environments, this project supports EEPROM-based PIN storage, lockout protection, and real-time visual feedback. It can be powered by a 12V external supply and controlled via an NPN transistor with a flyback diode for safe inductive switching.

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

 ---

 ### Hardware Requirements

 ESP32 Dev Board

 4x4 Matrix Keypad

 1602 LCD Display

 NPN Transistor (e.g., 2N3904 or S8050)

 Flyback diode (e.g., 1N4007)

 Electric Strike Lock (12V)

 External 12V Power Supply (≥ 1A recommended)

 Common-ground connection between ESP32 and 12V supply

 ---

 ### Wiring Notes

 Keypad: Connect 8 wires (R1–R4 and C1–C4) to digital GPIOs.

 LCD (Parallel): RS, E, D4–D7 to GPIOs; VSS to GND, VDD to 5V or 3.3V (if supported).

 Lock Control:

    Transistor Base: Connect to ESP32 GPIO 21 via 1kΩ resistor

    Collector: Connect to lock's negative terminal

    Emitter: Connect to GND

    Lock + terminal: Connect to +12V

    Flyback Diode: Cathode (|>) to +12V, Anode to collector

### Circuit
![Image](https://github.com/user-attachments/assets/89624457-38a7-4417-8327-589315cad442)