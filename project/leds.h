#ifndef leds_included
#define leds_included

#include <msp430.h>

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

void ledInit();
void ledToggle();

extern char ledsChanged, greenLedState, redLedState;

#endif
