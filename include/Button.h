#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    // Constructor: pin number
    explicit Button(uint8_t pin);

    // Initialize the pin
    void init();

    // Read button state
    bool isPressed();

    // Detect rising edge (button just pressed)
    bool justPressed();

    // Detect falling edge (button just released)
    bool justReleased();

private:
    uint8_t _pin;
    bool _lastState;
    bool _currentState;
};

#endif

