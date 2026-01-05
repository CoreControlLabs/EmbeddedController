#include <Arduino.h>
#include "Button.h"
#include "LED.h"

LED statusLed(13);
Button button1(2); // button connected to pin 2

void setup() {
    statusLed.init();
    button1.init();
}

void loop() {
    if (button1.justPressed()) {
        statusLed.toggle(); // toggle LED when button pressed
    }
}

