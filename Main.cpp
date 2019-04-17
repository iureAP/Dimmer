#include <mbed.h>
#include <dimmer.hpp>

DigitalIn button(PA_0);
Timer press_button;
Dimmer dimmer(PD_15, PD_14);
Ticker timer_event;
PwmOut led(PA_9);

int main() {

  led.period_ms(10); 
  dimmer.turnOffAllLeds();  
  dimmer.turnOnBlueLed();
  bool button_pressed = false;
  float increment = 0;
  

  while(1) {
    led.pulsewidth_ms(increment);
    if(button){
      if(button_pressed == false){
        button_pressed = true;
        press_button.start();
      }        
      if(press_button.read() > 1){
        switch(dimmer.whatIsLedOn()){
          case BLUE_LED_ON:
            while((button) && (button_pressed == true)){
              increment = increment + 2;
              led.pulsewidth_ms(increment);
              wait(1);
               if(increment == 10){
                dimmer.changeLed();
                button_pressed = false;
              }  
            }
            press_button.stop();
            press_button.reset();
            break;
          case RED_LED_ON:
             while(button && (button_pressed == true)){
              increment = increment - 2;
              led.pulsewidth_ms(increment);
              wait(1);
              if(increment == 0){
                dimmer.changeLed();
                button_pressed = false;
              }  
             } 
            press_button.stop();
            press_button.reset();
            break;   
        }
      }  
      else{
        if(button_pressed == true){
          if((button == 0) && (press_button.read() < 1)){
            dimmer.changeLed();            
            press_button.stop();
            press_button.reset();
            button_pressed = false;
          }
        }
      }
    }
  }
}