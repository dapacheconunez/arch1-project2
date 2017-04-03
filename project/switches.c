#include <msp430.h>
#include "header.h"

char down, changed;

static char switchUpdateInterruptSense(){

  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
  
}

void switchInit(){

  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switchUpdateInterruptSense();
  switchInterruptHandler();
}

void switchInterruptHandler(){

  char p2val = switchUpdateInterruptSense();
  down = (p2val & SW1) ? 0: 1;
  changed = 1;
  ledToggle();
  buzzerUpdate(down);
}
