#include <Arduino.h>
#include "input_conf.hpp"
#include "display.hpp"
#include "conf.hpp"

Controller::Controller(int pinNumber){
    pin = pinNumber;
}

int Controller::getMappedValue() {
    value = analogRead(pin);
    mappedValue = map(value, 0, value, 0, SCREEN_HEIGHT);
    return mappedValue;
}