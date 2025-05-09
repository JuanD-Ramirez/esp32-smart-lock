/**
 * @file LockController.h
 * @brief declaration of the LockController clas to control a servo.
 * 
 * This class provides a simple abstraction over a servo motor,
 * enabling locking and unlocking behavior for use in keypad-based smart locks.
 * 
 */

#ifndef LOCK_CONTROLLER_H
#define LOCK_CONTROLLER_H

#include <Arduino.h>
#include <ESP32Servo.h>

/**
 * @class LockController
 * @brief A class that manages the servo motor
 */
class LockController {
public:

    /**
     * @brief Constructor for the LockController class
     */
    LockController(int servoPin);

    /**
     * @brief Initializes the servo motor
     */
    void begin();

    /**
     * @brief Moves the servo to locked position
     */
    void lock();

    /**
     * @brief Moves the servo to unlocked position
     */
    void unlock();

    /**
     * @brief Automatically relocks the servo after a specified delay.
     * 
     * @param ms The delay time in milliseconds before relocking.
     */
    void autoRelockAfter(unsigned long ms);

    /**
     * @brief Returns whether the lock is currently in the locked state.
     * 
     * @return true if locked, false if unlocked.
     */
    bool isLocked();

private:
    Servo servo; // The servo object managing hardware control
    int pin;     // The GPIO pin connected to the servo
    bool locked; // Tracks whether the servo is currently locked
};

#endif
