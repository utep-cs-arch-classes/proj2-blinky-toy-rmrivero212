#include <msp430.h>
#include "led.h"

unsigned char toggle = 0;
//unsigned char led_on = 0;

//static char redVal[] = {0, LED_RED};

void led_init()
{
  P1DIR |= LED_RED;
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
/*
void led_update(){
  if(led_on){
    char ledFlags = redVal[red_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;
  }
*/


