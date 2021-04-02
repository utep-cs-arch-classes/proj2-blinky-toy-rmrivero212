#include <msp430.h>
#include "led.h"

unsigned char red_on = 0;

static char redVal[] = {0, LED_RED};


void led_init()
{
  P1DIR |= LED_RED;
  led_update();
}

void led_update(){
    char ledFlags = redVal[red_on];
    
    P1OUT &= (0xff^LED_RED) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;
}


