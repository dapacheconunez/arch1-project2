#include <msp430.h>
#include <stdio.h>
#include "libTimer.h"
#include "header.h"
#include <stdlib.h>

char note = 'z';

//static constants will be stored in flash, not in RAM.
int period = 0;
static const char s1[100] = "PdgdPdgdPdgdPdgdPegePegePegePegeSgrgSgrgSgrgSgrgrgpgrgpgrgpgrgpg";//aerodynamic
static const char s2[50] = "gcDfgcDfdhAcdhAcfADdfADdc";//game of thrones
static const char s3[50] = "ADdc";

static const int time1[100] = {25};
static const int time2[50] = {100};
static const int time3[50] = {100};

void buzzerInit(){//initialize the buzzer, this method is only called once, in main()

  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7); 
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
  buzzerSetPeriod(0); //start silent
  
}

void buzzerSetPeriod(int period){//this method sets the actual note in the buzzer.

  CCR0 = period;
  CCR1 = period >> 1;

}

void buzzerUpdate(int prev){//this method takes the melody code and translates it into periods.

 
  switch(prev){
    
  case 1:
    if(*(s1 + i1) != '\0'){
      note = *(s1 + i1);
      i1++;
    }else{
      i1 = 0;
      note = *(s1 + i1);
    }
 
    if(*(time1 + t1) != '\0'){
       time = *(time1 + t1);
       t1++;
    }else{
       t1 = 0;
       time = *(time1 + t1);
    }
    
    break;

  case 2:
    if(*(s2 + i2) != '\0'){
      note = *(s2 + i2);
      i2++;
    }else{
      i2 = 0;
      note = *(s2 + i2);
    }
    
    if(*(time2 + t2) != '\0'){
      time = *(time2 + t2);
      t2++;
    }else{
      t2 = 0;
      time = *(time2 + t2);
    }
    break;
  case 3: buzzerSetPeriod(0);//missing song
    break;
    
  case 0://turn off buzzing, reset machine.

    buzzerSetPeriod(0);
    time = 0;
    prev = 5;
    i1 = 0;
    i2 = 0;
    t1 = 0;
    t2 = 0;
    P1OUT = LED_RED;
    return;
    break;//im paranoid.
  }
  switch(note){ //find out what note was read from file.
    //lowercase:natural , uppercase: sharp.
    
  case 'j': period = 5999;//5999 is E3
    break;
  case 'i': period = 5662;//5662 is F3
    break;
  case 'I': period = 5344;//5344 is F#3
    break;
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
  case 'p': period = 2247;//2471 is A4
    break;
  case 'P': period = 2121;//2121 is A#4
    break;
  case 'q': period = 2002;//B4
    break;
  case 'r': period = 1889;//C5
    break;
  case 'R': period = 1783;//C#5
    break;
  case 's': period = 1683;//D5
    break;
  case 'S': period = 1589;//D#5
    break;
  
  default:
    break;

  }
  buzzerSetPeriod(period);
  
}

