#include <Arduino.h>
#include "Button.h"
#include "LED.h"

// LED connected to pin 8
LED statusLed(8);    
// Button connected to pin 2
Button button1(2);   

void setup() {
    Serial.begin(9600);    // just for checking in Serial Monitor
    statusLed.init();      // make pin 8 output
    button1.init();        // make pin 2 input
    Serial.println("Setup done. Press button to toggle LED.");
}

void loop() {
    if (button1.justPressed()) {  // button pressed once
        statusLed.toggle();       // switch LED on/off
        Serial.print("LED is now ");
        Serial.println(statusLed.isOn() ? "ON" : "OFF");
    }
}

