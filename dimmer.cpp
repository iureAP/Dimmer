#include "dimmer.hpp"

Dimmer::Dimmer(PinName blue_led_pin, PinName red_led_pin, PinName yellow_led_pin)
    :blue_led(blue_led_pin),
     red_led(red_led_pin),
     yellow_led(yellow_led_pin{
     increment = 0;
     
     }


void turnOnBlueLed(){
    blue_led.write(1);
}

void turOnRedLed(){
    red_led.write(1);
}

void turnOffBlueLed(){
    blue_led.write(0);
}

void turnOffRedLed(){
    red_led.write(0);
}

void turnOffYellowLed(){
    yellow_led.write(0)
}

float incrementLight(){
    increment = increment + 0.0005;
    return increment;
}

void changeLed{
    if(blue_led){
        blue_led.write(0);
        red_led.write(1);
    }
    else{
        blue_led.write(1);
        red_led(0);
    }       
}

int Dimer::whatIsLedOn(){
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