/**
 * @file PinStrage.h
 * @brief Declaration of the EEprom class to store the new pin.
 * 
 * This class provides a simple abstraction for storing, retrieving, and updating a user pin
 * in non-volatile EEPROM memory. 
 */
#ifndef PIN_STORAGE_H
#define PIN_STORAGE_H

#include <Arduino.h>
#include <EEPROM.h>

/**
 * @class PinStorage
 * @brief A class that handles EEPROM-based storage and retrieval of a PIN code.
 */
class PinStorage {
public:

     /**
     * @brief Constructor for the PinStorage class.
     * 
     * @param pinLength     The length of the PIN code 
     * @param startAddress  The starting EEPROM address where the PIN should be stored.
     */
    PinStorage(int pinLength, int startAddress);

    /**
     * @brief initialiazes EEPROM and loads the pin into memory
     */
    void begin();

    /**
     * @brief Saves a new pin to EEPROM and updates the internal buffer
     * 
     * @param newpin a null-terminated string representing the new pin
     */
    void savePin(const char* newPin);

    /**
     * @brief returns the correct pin stored in memory
     * 
     * @return a pointer to the null-terminated stored pin string
     */
    const char* getPin();

private:
     char* storedPin; //internal buffer for the current pin
     int pinLength;   //length of the pin code
     int address;     // EEPROM address where the pin is stored
};

#endif
