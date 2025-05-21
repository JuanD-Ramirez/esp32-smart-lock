/**
 * @file LockController.cpp
 * @brief Implementation of the lockController class for controlling an electrical strike.
 */

#include "LockController.h"

/**
 * @brief Constructs a LockController object and stores the GPIO pins to be used for the lock signal.
 * Initially it has been set to lock.
 */
LockController::LockController (int controlPin) {
    pin = controlPin;
    locked = true;
}

/**
 * @brief Attahces the lock to the specified pin and initializes it.
 */
void LockController::begin() {
    pinMode(pin, OUTPUT); 
    lock();
}

/**
 * @brief roates the servo to the locked position.
 */
void LockController::lock() {
    digitalWrite(pin, LOW); //Locked when no voltage is applied
    locked = true;
}

/**
 * Rotates the servo to the unlocked position.
 */
void LockController::unlock() {
    digitalWrite(pin, HIGH); //unlocked when voltage is applied
    locked = true;
}

/**
 * @brief Keeps the servo in the unlocked position for a specified delay,
 *        then relocks it automatically.
 * 
 * @param ms The number of milliseconds to wait before locking again.
 */
void LockController::autoRelockAfter(unsigned long ms) {
    delay(ms);
    lock();
}

/**
 * @brief Returns whether the servo is currently in the locked position.
 * 
 * @return true if the lock is engaged, false if it is unlocked.
 */
bool LockController::isLocked() {
    return locked;
}