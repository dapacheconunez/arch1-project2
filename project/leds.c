#include <msp430.h>
#include "header.h"

int changed;
int Bdown;

void ledInit(){//this method is only called once, in main()

  P1DIR |= LEDS;
  changed = 1;
  ledToggle();
}

void ledToggle(){//this method toggles the led into green when a button is pressed.

  if(changed){
    char ledFlags = 0;

    ledFlags |= Bdown ? LED_GREEN : 0;
    ledFlags |= Bdown ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  changed = 0;
}
