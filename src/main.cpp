/**
 * @file main.cpp
 * @brief Entry point for ESP32 Smart Lock Project
 * 
 * Initializes the serial interface and keypad system
 * and continuously reads key presses from keypad.
 */
#include <Arduino.h>
#include "KeypadManager.h"

// KeypadManager instance used to access keypad functionality
KeypadManager keypadMgr;

/**
 * @brief Arduino setup function.
 * 
 * Initializes serial communication and the keypad hardware.
 */
void setup() {
  Serial.begin(115200);
  keypadMgr.begin();
  Serial.println("Keypad Test Ready");
}

/**
 * @brief Arduino main loop function.
 * 
 * Continuously polls the keypad for key presses and logs them to the serial monitor.
 */
void loop() {
  char key = keypadMgr.getKey();
  if(key != '\0') {
    Serial.print("key pressed: ");
    Serial.println(key);
  }
  delay(50);
}
