#include <msp430.h>
#include <stdio.h>
#include "libTimer.h"
#include "header.h"
#include <string.h>
#include <stdlib.h>

static int i = 0;
static char *song = 0;
static char note = 'z';


void buzzerInit(){//initialize the buzzer, this method is only called once, in main()

  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7); 
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
  buzzerSetPeriod(0); //start silent
  
}

void buzzerSetPeriod(int cycles){//this method sets the actual note in the buzzer.

  CCR0 = cycles;
  CCR1 = cycles >> 1;

}

void setMelody(){//this method installs the melodies in memory.
  song = (char*)malloc(50);
  strcpy(song, "gcDfgcDfdhAcdhAcdhfADdfADdc");//game of thrones.
}


void buzzerUpdate(){//this method takes the melody code and translates it into periods.

  int period;
  
  if(down){

    if(*(song + i) != '\0'){
      note = *(song + i);
      i++;
    }else{
      i = 0;
      note = *(song + i);
    }
  switch(note){ //find out what note was read from file.
    //lowercase:natural , uppercase: sharp.

  case 'h': period = 5044;//5044 is G3
    break;
  case 'H': period = 4761;//4761 is G#3
    break;
  case 'a': period = 4494;//4494 is A3
    break;
  case 'A': period = 4242;//4242 is A#3
    break;
  case 'b': period = 4004;//4004 is B3
    break;
  case 'c': period = 3779;//3779 is C4
    break;
  case 'C': period = 3567;//3567 is C#4
    break;
  case 'd': period = 3367;//3367 is D4
    break;
  case 'D': period = 3178;//3178 is D#4
    break;
  case 'e': period = 2999;//2999 is E4
    break;
  case 'f': period = 2831;//2831 is F4
    break;
  case 'F': period = 2672;//2672 is F#4
    break;
  case 'g': period = 2522;//2522 is G4
    break;
  case 'G': period = 2381;//2381 is G#4
    break;
  case 'p':
    break;
  
  default:
    break;

  }
  buzzerSetPeriod(period);
  }
}

