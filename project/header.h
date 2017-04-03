#ifndef header_included
#define header_included

#include <msp430.h>

// Buzzer methods and variables
void buzzerInit();
void buzzerSetPeriod(int period);
void buzzerUpdate();
void setMelody();
extern int period;


// leds methods and variables
#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)
void ledInit();
void ledToggle();
extern char ledsChanged, greenLedState, redLedState;


// switches methods and variables
#define SW1 BIT0 //IN P2
#define SW2 BIT1 //IN P2
#define SWITCHES (BIT0 | BIT1)
void switchInit();
void switchInterruptHandler();
extern char down, changed;

#endif
