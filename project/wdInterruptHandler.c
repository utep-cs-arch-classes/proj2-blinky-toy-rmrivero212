#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
    
  static char blink_count = 0;
  static char state_count = 0;
  
  if(++blink_count == 2){
    state_advance();
    blink_count = 0;
  }
  if (++state_count == 250) {
    change_dimming();
    buzzer_set_period(0);
    state_count = 0;
  }
}

