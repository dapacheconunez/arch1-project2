#include <msp430.h>
#include "header.h"

//this method listens for interrupts generated only by the switches.

void __interrupt_vec(PORT2_VECTOR) Port_2(){

  if(P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switchInterruptHandler();//when an interrupt is thrown, advance the note on buzzer and change leds.
    //senseDir();
  }
}


