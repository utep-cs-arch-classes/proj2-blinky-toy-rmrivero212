#ifndef led_included
#define led_included

#define LED_RED BIT0

extern unsigned char red_on;

void led_init();
void led_update();

#endif
