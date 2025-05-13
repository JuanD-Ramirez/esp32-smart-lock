/**
 * @file PinStorage.cpp
 * @brief implementation of the PinStorage class for persistent EEPROM-based pin
 * 
 * This file defines a method for reading, writting, and accesing a stored pin in EEPROM.
 */

#include "PinStorage.h"

#define EEPROM_SIZE 64 //Total size for EEPROM to reseve in bytes

/**
 * @brief Constructor for the PinStorage class.
 *
 * Initializes internal variables and allocates memory for the stored PIN
 *
 * @param pinLength The number of characters in the Pin code 
 * @param startAddress The starting EEPROM address where the Pin will be stored
 */
PinStorage::PinStorage(int pinLength, int startAddress) {
    this->pinLength = pinLength;
    this->address = startAddress;
    storedPin = new char[pinLength + 1]; //+1 for null terminator
}

/**
 * @brief Initializes the EEPROM and loads the saved PIN into memory.
 */
void PinStorage::begin() {
    EEPROM.begin(EEPROM_SIZE);
    for (int i = 0; i < pinLength; i++) {
        storedPin[i] = EEPROM.read(address + i);
    }
    storedPin[pinLength] = '\0';
}

/**
 * @brief Saves a new PIN to EEPROM and updates the internal buffer.
 *
 * The new PIN is written byte-by-byte to EEPROM starting from the configured address,
 * and the in-memory buffer is updated to reflect the change.
 *
 * @param newPin A null-terminated string containing the new PIN to save.
 */
void PinStorage::savePin(const char* newPin) {
    for (int i = 0; i < pinLength; i++) {
        EEPROM.write(address + i, newPin[i]);
        storedPin[i] = newPin[i];
    }
    EEPROM.commit();
    storedPin[pinLength] = '\0';
}

/**
 * @brief Retrieves the currently stored PIN from memory.
 *
 * @return A pointer to the internal null-terminated PIN string.
 */
const char* PinStorage::getPin() {
    return storedPin;
}