#include <msp430.h>
#include "header.h"

void switchInit(){

  P2REN |= SWITCHES;    //enable the switches on board P2
  //P2IE = SWITCHES;    //diable interrupts, this makes changes "instantaneous". doesn't re-run main.
  //P2OUT |= SWITCHES;  //switches won't be used as output.
  P2DIR &= ~SWITCHES;   //switches will be read as input.
  
}
