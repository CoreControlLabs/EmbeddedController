#include "Button.h"

Button::Button(uint8_t pin) : _pin(pin), _lastState(false), _currentState(false) {}

void Button::init() {
    pinMode(_pin, INPUT_PULLUP); // assuming active-low button
    _lastState = digitalRead(_pin);
    _currentState = _lastState;
}

bool Button::isPressed() {
    _currentState = digitalRead(_pin);
    _lastState = _currentState;
    return !_currentState; // active-low: pressed = LOW
}

bool Button::justPressed() {
    _currentState = digitalRead(_pin);
    bool pressedNow = (!_currentState && _lastState);
    _lastState = _currentState;
    return pressedNow;
}

bool Button::justReleased() {
    _currentState = digitalRead(_pin);
    bool releasedNow = (_currentState && !_lastState);
    _lastState = _currentState;
    return releasedNow;
}

