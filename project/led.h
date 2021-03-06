#ifndef led_included
#define led_included

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

extern unsigned char toggle;

void led_init();
void led_update(char val);
void led_switch_update();

#endif
