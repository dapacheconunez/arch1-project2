#include "header.h"

//this method listens for interrupts generated only by the switches.

void __interrupt_vec(WDT_VECTOR) WDT(){//250 interrupts per second.

  if(!(P2IN & BIT0)){state = 1; start = 1;}//if piano buttons pressed, change state.
  if(!(P2IN & BIT1)){state = 2; start = 1;}//if piano buttons are pushed, change states.
  if(!(P2IN & BIT2)){state = 3; start = 1;}
  if(!(P2IN & BIT3)){start = 0;}
  
  stateHandler(state);
}

