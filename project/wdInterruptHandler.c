#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  
  static char blink_count = 0;
  static char state_count = 0;
  
  if(++blink_count == 2){
    dimming_state();
    blink_count = 0;
  }
  
  if (++state_count == 250) {
    change_dimming();
    state_count = 0;
  }
}
