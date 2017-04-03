#include <msp430.h>
#include "header.h"

void ledInit(){//this method is only called once, in main()

  P1DIR |= LEDS;
  changed = 1;
  ledToggle();
}

void ledToggle(){//this method toggles the led into green when a button is pressed.

  if(changed){
    char ledFlags = 0;

    ledFlags |= down ? LED_GREEN : 0;
    ledFlags |= down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  changed = 0;
}
