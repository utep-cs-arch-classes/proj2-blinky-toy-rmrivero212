#include <msp430.h>
#include "led.h"
#include "switches.h"

//unsigned char toggle = 0;
//unsigned char led_on = 0;

//static char redVal[] = {0, LED_RED};

void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update(0);
}
void led_update(char val){
  if(val){
    P1OUT |= LED_RED;
  }
  else{
    P1OUT &= (0xff^LEDS) | 0;
  }
}

void led_switch_update(){
  if(switch_state_changed){
    char ledFlags = 0;

    ledFlags |= switch_state_down ? LED_RED : 0;

    P2OUT &= (0xff - LEDS) | ledFlags;
    P2OUT |= ledFlags;
  }
  switch_state_changed = 0;
}
/*
void led_update(){
  if(led_on){
    char ledFlags = redVal[red_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;
  }
*/


