#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

int main(void) {
  configureClocks();
  
  switch_init();
  led_init();
  buzzer_init();
  buzzer_set_period(0);
  enableWDTInterrupts();

  or_sr(0x18);
}
