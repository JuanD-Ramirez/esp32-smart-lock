/**
 * @file DisplayManager.Cpp
 * @brief Implementation of DisplayManager class for controlling a 1602 lcd display
 * 
 * This class provides an abstraction layer for displaying messages and input progress.
 */

#include "DisplayManager.h"
#include <LiquidCrystal.h>

// LCD pin mapping to ESP32 GPIOs:
// RS = GPIO 32, E = GPIO 33, D4 = GPIO 25, D5 = GPIO 26, D6 = GPIO 27, D7 = GPIO 14
LiquidCrystal lcd(32, 33, 25, 26, 27, 14);

/**
 * @brief Default constructor for DisplayManager.
 */
DisplayManager::DisplayManager() {}


/**
 * @brief Initializes the LCD and displays the default "Enter Pin:" prompt.
 */
void DisplayManager::begin() {
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter Pin: ");
}

/**
 * @brief Displays the current user-entered PIN digits on the second row of the LCD.
 * 
 * @param input Null-terminated character array representing digits entered so far.
 */
void DisplayManager::showPinProgress(const char* input) {
    lcd.setCursor(0,1);
    lcd.print(input);

     // Overwrite leftover characters from previous input
    int len = strlen(input);
    for(int i = len; i < 4; i++) {
        lcd.print(' ');
    }
}

/**
 * @brief Displays a message on the first line of the LCD.
 * 
 * @param msg A null-terminated message string (e.g., "Access Granted").
 */
void DisplayManager::showMessage(const char* msg) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(msg);
}

/**
 * @brief Clears the screen and resets to the "Enter Pin:" prompt.
 */
void DisplayManager::clear() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter Pin: ");
}