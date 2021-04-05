#ifndef switches_included
#define switches_included

#define SW1 0x08
#define SW2 0x04
#define SW3 0x02
#define SW4 0x01

#define SWITCHES 0x0f

void switch_init();
void switch_interrupt_handler();


#endif
