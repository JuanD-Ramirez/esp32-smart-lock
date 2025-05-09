/**
 * @file LockController.cpp
 * @brief Implementation of the lcok controller class for controlling a servo motor.
 */

#include "LockController.h"

/**
 * @brief Constructs a LockController object and stores the GPIO pins to be used for the servo signal.
 * Initially it has been set to lock.
 */
LockController::LockController (int servoPin) {
    pin = servoPin;
    locked = true;
}

/**
 * @brief Attahces the servo to the specified pin and initializes it.
 */
void LockController::begin() {
    servo.attach(pin);
    lock();
}

/**
 * @brief roates the servo to the locked position.
 */
void LockController::lock() {
    servo.write(0);
    locked = true;
}

/**
 * Rotates teh servo to the unlocked position.
 */
void LockController::unlock() {
    servo.write(90);
    locked = false;
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