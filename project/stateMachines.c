#include <msp430.h>
#include "stateMachines.h"
#include "led.h"


void dimming_state(){
  led_update(1);
}
void state_advance(){
  static char on = 0;
  
  if(on){
    led_update(on);
    on = 0;
  }
  else{
    led_update(on);
    on = 1;
  }
}

void change_dimming(){
  static char change = 0;

  if(change){
    dimming_state();
    change = 0;
  }
  else{
    state_advance();
    change = 1;
  }
}
