#ifndef DIMMER_HPP
#define DIMMER_HPP
#include <mbed.h>

enum led_state{
    BLUE_LED_ON,
    RED_LED_ON,
    ALL_LEDS_OFF,
};

class Dimmer{
 public:
    Dimmer(PinName blue_led_pin, PinName red_led_pin);
    void turnOnBlueLed();
    void turnOnRedLed();
    void turnOnYellowLed();
    void turnOffBlueLed();
    void turnOffRedLed();
    void turnOffYellowLed();
    void turnOffAllLeds();    
    void incrementLuminosity();
    void decrementLuminosity();
    led_state led_on; 
    void changeLed();
    int whatIsLedOn();
    
    DigitalOut blue_led;
    DigitalOut red_led;
    //float increment;
    //DigitalOut yellow_led;    
};


#endif