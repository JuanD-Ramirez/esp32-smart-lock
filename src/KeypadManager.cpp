/**
 * @file KeypadManager.cpp
 * @brief Implementation of the KeypadManager class for reading a 4x4 matrix keypad.
 */
#include "KeypadManager.h"
#include <Keypad.h>


// Number of rows in the keypad matrix
const byte Rows = 4;

// Number of columns in the keypad matrix
const byte Cols = 4;

// Keymap layout for a standard 4x4 membrane keypad
char keys[Rows][Cols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

//ESP32 connection pins
byte rowPins[Rows] = {32, 33, 25, 26};
byte colPins[Cols] = {27, 14, 12, 13};

//pass in variable to create Keypad Object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, Rows, Cols);

/**
 * @brief Constructor for KeypadManager.
 */
KeypadManager::KeypadManager() {}


/**
 * @brief Initializes the keypad.
 */
void KeypadManager::begin() {

}

/**
 * @brief Reads the current key pressed on the keypad.
 * 
 * @return char The character corresponding to the pressed key, or '\0' if none.
 */
char KeypadManager::getKey() {
    return keypad.getKey();
}