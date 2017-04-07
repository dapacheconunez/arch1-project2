#include "header.h"

//this method listens for interrupts generated only by the switches.

void __interrupt_vec(WDT_VECTOR) WDT(){//250 interrupts per second.

  chooseState();//call the state machine.
  
}

