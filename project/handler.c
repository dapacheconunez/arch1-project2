#include <msp430.h>
#include "switches.h"

//this method listens for interrupts generated only by the switches.

void __interrupt_vec(PORT1_VECTOR) Port_1(){

  if(P1IFG & SWITCHES){
    P1IFG &= ~SWITCHES;
    switchInterruptHandler();//when an interrupt is thrown, advance the note on buzzer and change leds.
    //senseDir();
  }
}


