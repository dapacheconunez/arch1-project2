#include <msp430.h>
#include "header.h"

void switchInit(){

  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  //P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  
}
