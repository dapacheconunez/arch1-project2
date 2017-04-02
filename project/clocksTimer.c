#include <msp430.h>
#include "libTimer.h"

void configureClocks(){

  WDTCTL = WDTPW + WDTHOLD;//DISABLE WATCHDOG TIMER
  BCSCTL1 = CALBC1_16MHZ;
  DCOCTL = CALDCO_16MHZ;

  BCSCTL2 &= ~(SELS);//SMCLK SOURCE = DCO
  BCSCTL2 |= DIVS_3;//SMCLK = DCO/8

}

void timerAUpmode(){

  TA0CCR0 = 0;
  TA0CCR1 = 0;
  TA0CCTL1 = OUTMOD_3;  //toggle p1.6 when timer=count1

  //timer A control:
  //timer clock source 2: system clock (SMCLK)
  //Mode control 1: continuosly 0...CCR0
  TACTL = TASSEL_2 + MC_1;
}

