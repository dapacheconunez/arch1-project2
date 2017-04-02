#include <msp430.h>
#include "leds.h"
#include "switches.h"

void ledInit(){

  P1DIR |= LEDS;
  changed = 1;
  ledToggle();
}

void ledToggle(){

  if(changed){
    char ledFlags = 0;

    ledFlags |= down ? LED_GREEN : 0;
    ledFlags |= down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  changed = 0;
}
