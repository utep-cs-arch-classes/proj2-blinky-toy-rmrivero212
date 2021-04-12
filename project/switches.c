#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

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

  if(!(val & SW0)){
    switch_state_down = (val & SW0) ? 0 : 1;
    switch_state_changed = 1;
    buzzer_set_period(d1 * 200);
    led_switch_update();
  }
  else if(!(val & SW1)){
    switch_state_down = (val & SW1) ? 0: 1;
    switch_state_changed = 1;
    buzzer_set_period(c1 * 200);
    led_switch_update();
  }
  else if(!(val & (SW2 | SW3))){
    switch_state_down = (val & (SW2 | SW3)) ? 0 : 1;
    switch_state_changed = 1;
    buzzer_set_period(e2 * 200);
    led_switch_update();
  }
}
