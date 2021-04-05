#include <msp430.h>
#include "led.h"

unsigned char red_on = 0;
unsigned char led_on = 0;

static char redVal[] = {0, LED_RED};

void led_init()
{
  P1DIR |= LED_RED;
  led_on = 1;
  led_update();
}

void led_update(){
  if(led_on){
    char ledFlags = redVal[red_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;
    led_on = 0;
  }
}


