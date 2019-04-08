#ifndef DIMMER_HPP
#define DIMMER_HPP

enum led_state{
    BLUE_LED_ON,
    RED_LED_ON,
    ALL_LEDS_OFF,
};

class Dimmer{
 public:
    Dimmer(PinName blue_led_pin, PinName red_led_pin, PinName yellow_led_pin);
    void turnOnBlueLed();
    void turnOnRedLed();
    void turnONYellowLed();
    void turnOffBluLed();
    void turnOffRedLed();
    void turnOffYellowLed();
    void turnOffAllLeds();    
    float increementLight();
    led_state led_on; 
    int increment;
    void changeLed();
    
};


#endif