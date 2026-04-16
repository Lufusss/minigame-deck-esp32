#ifndef HARDWARE_CONFIG_HPP
#define HARDWARE_CONFIG_HPP

class Controller {
    private:
        int value;
        int mappedValue;
        int pin;
        int screenHeight;
    public:
        Controller(int pinNumber);
        int getMappedValue();

}; 

#endif