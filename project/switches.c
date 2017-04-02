#include <msp430.h>
#include "switches.h"
#include "leds.h"
#include "buzzer.h"

char down, changed;

static char switchUpdateInterruptSense(){

  char p1val = P1IN;
  P1IES |= (p1val & SWITCHES);
  P1IES &= (p1val | ~SWITCHES);
  return p1val;
  
}

void switchInit(){

  P1REN |= SWITCHES;
  P1IE = SWITCHES;
  P1OUT |= SWITCHES;
  P1DIR &= ~SWITCHES;
  switchUpdateInterruptSense();
  switchInterruptHandler();
}

void switchInterruptHandler(){

  char p1val = switchUpdateInterruptSense();
  down = (p1val & SW1) ? 0: 1;
  changed = 1;
  ledToggle();
  buzzerUpdate(down);
}
