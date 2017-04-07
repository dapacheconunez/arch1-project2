#ifndef header_included
#define header_included

#include <msp430.h>

// Buzzer methods and variables
void buzzerInit();
void buzzerSetPeriod(int period);
void buzzerUpdate(int song);


// leds methods and variables
#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)
void ledInit();
void ledToggle();


// switches methods and variables
#define SW1 BIT0 //IN P2
#define SW2 BIT1 //IN P2
#define SW3 BIT2 //IN P2
#define SW4 BIT3 //IN P2
#define SWITCHES (SW1 | SW2 | SW3 | SW4)
void switchInit();

//statemachine methods and variables

void chooseState();
void stateHandler(int status);

extern int state;
extern int time;//initially.
extern int prev;
extern int time;
extern int i1;
extern int t1;
extern int i2;
extern int t2;
extern int start;

#endif
