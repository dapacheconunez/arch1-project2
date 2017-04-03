#include <msp430.h>
#include "libTimer.h"
#include "header.h"

//the main method serve only to initialize all the files
//once initialization is done, the main method is not read again.
//machine will continue working on interrupts.

void main(void){

  configureClocks();
  ledInit();//set and initialize the leds.
  setMelody();//allocate the memory for the string that represents the notes.
  switchInit();//set and initialize the switches.
  buzzerInit();//set and initialize the buzzer.
  
  or_sr(0x18); //turn off CPU and let GIE be on.
  
}
