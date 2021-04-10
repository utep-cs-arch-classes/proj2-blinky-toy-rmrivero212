#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void
switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  led_switch_update();
}

void
switch_interrupt_handler()
{
  char val = switch_update_interrupt_sense();

  
  switch_state_down = (val & SW0) ? 0 : 1;
  switch_state_changed = 1;
  led_switch_update();
  
}
