#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
/*
void state_advance()	
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}
*/
char toggleOn(){
  static char state = 0;
  switch (state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}
char alwaysOn(){
  red_on = 1;
}
char switchState(){
  char on = 0;
  static char switch_state = 0;

  switch(switch_state){
  case 0:
    on = toggleOn();
    switch_state = 1;
    break;
  case 1:
    on = alwaysOn();
    switch_state = 0;
    break;
  }
  led_on = on;
  led_update();
}

void state_advance(){
  char on = 0;
  on = toggleOn();
  led_on = on;
  led_update();
}
void dimming(){
  char on = 0;
  on = alwaysOn();
  led_on = on;
  led_update();
}

