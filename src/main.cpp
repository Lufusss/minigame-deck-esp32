#include <Arduino.h>
#include <Wire.h>

// including header files
#include "controller.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "display.hpp" 
#include "pong.hpp"
#include "conf.hpp"


void setup() {
    Serial.begin(9600);
    Serial.println("MiniGame Deck - Version 0.99");
    millis();
    pongBegin();
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
    if (!digitalRead(BUTTON)) {
        pongUpdate();    
        pongDrawScreen();
    }
}
