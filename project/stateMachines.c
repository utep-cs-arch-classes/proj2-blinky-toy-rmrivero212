#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char state = 0;

void state_advance(){
  static char toggle = 0;
  
  switch(state){
  case 0:
    if(toggle){
      led_update(toggle);
      toggle = 0;
      break;
    }
    else{
      led_update(toggle);
      toggle = 1;
      break;
    }
  case 1:
    led_update(1);
    break;
  }
}

void change_dimming(){
  if(state){
    state = 0;
  }
  else{
    state = 1;
  }
}

