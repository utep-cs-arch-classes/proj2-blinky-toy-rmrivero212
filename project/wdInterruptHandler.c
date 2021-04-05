#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  
  static char blink_count = 0;
  static char state_count = 0;
  if(++blink_count == 250){
    state_advance();
    state_count = 0;
  }
  if (++state_count == 300) {
    dimming();
    state_count = 0;
  }
}
