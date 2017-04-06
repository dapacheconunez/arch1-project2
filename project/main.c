#include "header.h"
#include "libTimer.h"
//the main method serve only to initialize all the files
//once initialization is done, the main method is not read again.
//machine will continue working on interrupts

int state = 2;
int prev = 3;
int time = 0;
int start = 0;
int i1 = 0;
int t1 = 0;
int i2 = 0;
int t2 = 0;

void main(void){

  configureClocks();
  ledInit();//set and initialize the leds.
  switchInit();//set and initialize the switches.
  buzzerInit();//set and initialize the buzzer.
  enableWDTInterrupts();//enable the watchdog timer interrupts.
  
  or_sr(0x18); //turn off CPU and let GIE be on.
  
}
