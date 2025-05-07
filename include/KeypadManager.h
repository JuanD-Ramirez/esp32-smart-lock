/**
 * @file KeypadManager.h
 * @brief Declaration of the KeypadManager class for handling a 4 x 4 matrix keypad input.
 * 
 * This class provides an abstraction layer over the keypad library,
 * it allows the main program to easily initialize and read key presses.
 */

#ifndef KEYPAD_MANAGER_H //prevent double-inclusion of the keypadManager file. So it only gets compiled once.
#define KEYPAD_MANAGER_H

#include <Arduino.h>

/**
 * @class KeypadManager
 * @brief a class that manages a 4 x 4 matrix keypad.
 */
class KeypadManager {
public:

    /**
     * @brief KeypadManager constructor
     */
    KeypadManager();

    /**
     * @brief Initializes the keypad hardware
     * 
     * should be called once in the setup function
     */
    void begin();

    /**
     * @brief Reads the currently pressed key
     * 
     * @return char the character corresponding to the pressed key
     * or '\0' if no key is pressed.
     */
    char getKey();
};

#endif