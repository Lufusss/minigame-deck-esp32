#ifndef HARDWARE_CONFIG_HPP
#define HARDWARE_CONFIG_HPP

class Controller {                  //defines Object Controller, defining game important variables
    private:
        int value;
        int mappedValue;
        int pin;
    public:
        Controller(int pinNumber);
        int getValue();

}; 

#endif
