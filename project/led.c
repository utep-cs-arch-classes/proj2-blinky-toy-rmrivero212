#include <msp430.h>
#include "led.h"
#include "switches.h"


void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_switch_update();
}

void led_switch_update(){
  if(switch_state_changed){
    char ledFlags = 0;

    ledFlags |= switch_state_down ? LED_GREEN:0;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}

void led_update(char val){
  if(val){
    P1OUT |= LED_RED;
  }
  else{
    P1OUT &= (0xff^LEDS) | 0;
  }
}



