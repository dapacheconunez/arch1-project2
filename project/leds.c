#include <msp430.h>
#include "header.h"

int changed;
int count = 0;

void ledInit(){//this method is only called once, in main()

  P1DIR |= LEDS;
  changed = 1;
  ledToggle();
}

void ledToggle(){//this method toggles the led into green when a button is pressed.

  //if(changed){
  char ledFlags = 0;

  count++;

  if(count > 10)  count = 0;
  
  ledFlags |= (count%(period/1000)) ? (LED_GREEN | LED_RED) : 0;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
    
  //}
  //changed = 0;
}
