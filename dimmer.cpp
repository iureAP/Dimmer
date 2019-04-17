#include <dimmer.hpp>

Dimmer::Dimmer(PinName blue_led_pin, PinName red_led_pin)
    : blue_led(blue_led_pin)
    , red_led(red_led_pin) 
    /*, increment(5)*/ {}

void Dimmer::turnOnBlueLed(){
    blue_led.write(1);
}

void Dimmer::turnOnRedLed(){
    red_led.write(1);
}

void Dimmer::turnOffBlueLed(){
    blue_led.write(0);
}

void Dimmer::turnOffRedLed(){
    red_led.write(0);
}

void Dimmer::turnOffAllLeds(){
    blue_led.write(0);
    red_led.write(0);
}

/*void Dimmer::incrementLuminosity(){
    increment = increment + 0.5;
}

void Dimmer::decrementLuminosity(){
    increment = increment - 0.5;
}*/
void Dimmer::changeLed(){
    if(blue_led){
        blue_led.write(0);
        red_led.write(1);
    }
    else{
        blue_led.write(1);
        red_led.write(0);
    }       
}

int Dimmer::whatIsLedOn(){
    if(blue_led.read())
        return BLUE_LED_ON;    
    else{
        if(red_led.read())
            return RED_LED_ON;
        else{
            return ALL_LEDS_OFF;     
        }
    }    
}