/**
 * @file DisplayManager.h
 * @brief declaration of the DisplayManager class for handling lcd output
 * 
 * this class provides a simple interface to an i2c connected 16 x 2 lcd display.
 * for use in a keyboard- controlled smart lock project
 * it allows displaying PIN entry progress and messages.
 */

#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>

/**
 * @class DisplayManager
 * @brief a class that manages the LCD display.
 */
class DisplayManager {
public: 

    /**
     * @brief Constructor for the DisplayManage class
     */
    DisplayManager();

    /**
     * @brief Initializes the LCD screen 
     */
    void begin();

    /**
     * @brief Displays input as the user types
     */
    void showPinProgress(const char* input); 

    /**
     * @brief Displays a custom message 
     * 
     * @param msg a null-terminated c-string to print on LCD display
     */
    void showMessage(const char* msg);

    /**
     * clears the display and resets it to default message
     */
    void clear();
}; 

#endif