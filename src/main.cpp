/**
 * @file main.cpp
 * @brief Entry point for ESP32 Smart Lock Project
 *
 * Initializes the serial interface and keypad system
 * and continuously reads key presses from keypad.
 */
#include <Arduino.h>
#include "KeypadManager.h"
#include "DisplayManager.h"
#include "LockController.h"
#include "PinStorage.h"

// KeypadManager instance used to access keypad functionality
KeypadManager keypadMgr;

// DisplayManager instance used to display messages
DisplayManager display;

// servo instance used to control lock
LockController lockMotor(22);

/// Password Lenght
const int PIN_LENGTH = 4;

/// the currently configured pin
char correctPin[PIN_LENGTH + 1] = "1234";

/// Buffer for the users input as they type
char enteredPin[PIN_LENGTH + 1];

/// Current index within the entered pin
int pinIndex = 0;

/// Tracks whether the lock is currently engaged
bool locked = true;

/// pinstore instance to save pin to EEPROM
PinStorage pinStore(PIN_LENGTH, 0);

// -----------------------------------------------------------------------------
// Lockout Security Configuration
// -----------------------------------------------------------------------------

/// current number of failed attempts
int failedAttempts = 0;

/// Timestamp in milliseconds when the lockout period started.
/// Used to calculate how long the system should remain locked out.
unsigned long lockoutStart = 0;

/// Maximum number of allowed attempts before triggering a lockout.
const int MAX_FAILED_ATEMPTS = 3;

/// Duration of the lockout period
const unsigned long LOCKOUT_DURATION_MS = 30000;

/**
 * @brief Unlocks the lock, displays success, and relocks after a delay.
 */
void unlockLock()
{
  lockMotor.unlock();
  display.showMessage("Access Granted");
  delay(3000);
  lockMotor.lock();
}

/**
 * @brief Checks if the number of failed attemps exceeds the number of maximum test.
 * If exceceded Lockout the user from being able to input new pin momentarily.
 */
void CheckIfLockOut()
{
  if (failedAttempts >= MAX_FAILED_ATEMPTS)
  {
    unsigned long now = millis();

    // First entry into lockout: initialize timestamp and show message
    if (lockoutStart == 0)
    {
      lockoutStart = now;
      display.showMessage("LOCKED OUT");
    }

    // While still within the lockout window, do nothing
    if (now - lockoutStart < LOCKOUT_DURATION_MS)
    {
      return;
    }
    else
    {
      // Lockout duration finished — reset state
      failedAttempts = 0;
      lockoutStart = 0;
      display.clear();
    }
  }
}

/**
 * @brief helper method to handle users pin entry until the user enters a complete pin.
 */
void handlePinEntry(char key)
{
  if (pinIndex < PIN_LENGTH)
  {
    enteredPin[pinIndex] = key;
    pinIndex++;
    enteredPin[pinIndex] = '\0'; // Null-terminate after adding
    display.showPinProgress(enteredPin);
  }
}

/**
 * @brief helper method to handle pin validation, updating to new pin, and verification of the new pin.
 */
void handlePinValidation()
{
  enteredPin[PIN_LENGTH] = '\0'; // null terminate string

  // Compare if entered pin is the correct pin
  if (strcmp(enteredPin, pinStore.getPin()) == 0)
  {
    display.showMessage("Access Granted");
    unlockLock();
    locked = false;
  }

  // pin overide option
  else if (strcmp(enteredPin, "0101") == 0)
  {
    display.showMessage("Enter a new pin to be saved");
    pinIndex = 0;

    // Enter new Pin
    while (pinIndex < PIN_LENGTH)
    {
      char tempKey = keypadMgr.getKey();
      if (tempKey >= '0' && tempKey <= '9')
      {
        enteredPin[pinIndex] = tempKey;
        pinIndex++;
        enteredPin[pinIndex] = '\0';
        display.showPinProgress(enteredPin);
      }
      delay(50);
    }

    delay(500);
    pinIndex = 0;
    display.showMessage("Confirm pin");

    //temp pin to double check the new pin to be stored
    char tempPin[PIN_LENGTH + 1];

    // Confirm New Pin
    while (pinIndex < PIN_LENGTH)
    {
      char tempKey = keypadMgr.getKey();
      if (tempKey >= '0' && tempKey <= '9')
      {
        tempPin[pinIndex++] = tempKey;
        tempPin[pinIndex] = '\0';
        display.showPinProgress(tempPin);
      }
      delay(50);
    }

    // Compare to see if Pins are the same
    if (strcmp(tempPin, enteredPin) == 0)
    {
      pinStore.savePin(enteredPin);
      display.showMessage("Pin Updated");
    }
    else
    {
      display.showMessage("Mismatch, please try again");
    }

    delay(2000);
    display.clear();
    pinIndex = 0;
  }

  else
  {
    display.showMessage("Access Denied");
    failedAttempts++;
  }

  // Reset for next atempt
  pinIndex = 0;
  delay(1000);
  display.clear();
}

/**
 * @brief Arduino setup function.
 *
 * Initializes serial communication and the keypad hardware.
 */
void setup()
{
  Serial.begin(115200);
  keypadMgr.begin();
  display.begin();
  lockMotor.begin();
  pinStore.begin();
}

/**
 * @brief Arduino main loop function.
 *
 * Continuously polls the keypad for key presses and logs them to the serial monitor.
 */
void loop()
{

  // check to see if user
  CheckIfLockOut();

  char key = keypadMgr.getKey();

  // if key is pressed
  if (key != '\0')
  {

    if (key >= '0' && key <= '9')
    {

      handlePinEntry(key);

      // when 4 digits are entered
      if (pinIndex == PIN_LENGTH)
      {
        handlePinValidation();
      }

      else if (key == '*')
      {
        // Reset user input on *
        display.clear();
        pinIndex = 0;
      }

    }

    delay(50);
  }
}