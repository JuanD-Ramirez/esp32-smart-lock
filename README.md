Project Name: ESP32 Keypad-Controlled Smart Lock
Author: JD Ramirez
Version: 1.0
Date: May 6, 2025

1. Overview
This project is a secure, standalone smart lock system designed for personal use (e.g., bedroom door). The system requires a user to input a 4-digit PIN on a matrix keypad. Upon correct entry, the system will unlock using a servo motor for a configurable duration, display status on an I2C LCD screen, and provide optional buzzer feedback. Future enhancements will include EEPROM-based PIN storage and physical mounting.

2. Objectives
Create a reliable and tamper-resistant digital lock

Provide clear user feedback through LCD display and optional buzzer

Ensure logic is modular and extensible (admin mode, wireless override, etc.)

Build with portability and eventual physical mounting in mind

3. Functional Requirements
3.1 Core Features
Feature	Description
PIN Entry	    Accept a 4-digit PIN using a 3x4 or 4x4 matrix keypad
PIN Validation	Compare entered PIN to stored value in memory (hardcoded initially)
Unlock Action	Trigger servo motor to unlock door for 3–5 seconds
Auto-Lock	    Automatically relock after timeout period
Display Output	Show system state on I2C LCD1602 (e.g., "Enter PIN", "Access Granted")
Attempt Lockout	Optional: disable input after 3 failed attempts for N seconds
UART Debugging	Print logs to serial terminal (attempts, status, etc.)

3.2 Optional Features (Phase 2)
Feature	            Description
Admin Mode	        Long-press or UART menu to set new PIN
EEPROM Support	    Store and load PIN from EEPROM
Buzzer Feedback	    Short/long beeps for correct or incorrect PIN
Timestamp Logging	Add RTC module to timestamp unlock attempts

4. Non-Functional Requirements
Requirement	    Description
Power Supply	Must operate from USB (5V) or 12V wall adapter (with buck converter)
Microcontroller	Must use ESP32 for scalability and built-in UART/I2C support
Modular Code	Code should be split into modules (keypad, LCD, lock logic)
Safety	        Servo should not overdrive, and system must fail locked on reset
Upgradability	Should be easy to mount in enclosure and adapt for real door installation

5. System Components
Component	            Purpose
ESP32 Dev Board	Main controller (UART, I2C, logic)
3x4 Matrix Keypad	    User input
LCD1602 I2C Display	    Text feedback to user
MG90S Servo	Physical    actuator for locking
Buzzer (optional)	    Feedback tones
Resistors	            Pull-downs for keypad stability
Breadboard + wires	    Prototyping
(Future) EEPROM	Persistent PIN storage
(Future) DS3231	RTC for timestamps

6. User Interaction Flow
System powers on, displays Welcome - Enter PIN

User types 4-digit PIN on keypad

Each keypress is shown as * on LCD

If correct PIN:

Display Access Granted

Unlock servo

After delay, relock and show welcome message

If incorrect:

Display Access Denied

Optional: track attempts and initiate lockout

7. Hardware Interfaces
Peripheral	Interface	ESP32 Pins (default)
Keypad	GPIO (digital read)	Configurable (e.g., 4 rows + 3 columns)
LCD1602 I2C	I2C	SDA: GPIO 21, SCL: GPIO 22
Servo	PWM (GPIO)	e.g., GPIO 25
UART Debug	UART over USB	USB Serial Monitor

8. Development Milestones
Date	Milestone
Week 1	Keypad input, PIN matching logic working
Week 2	Servo unlock + LCD feedback integrated
Week 3	Lockout logic, UART logs, buzzer + cleanup.



