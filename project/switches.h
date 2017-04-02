#ifndef switches_included
#define switches_included

#define SW1 BIT3 //NEEDS CHANGE
#define SWITCHES SW1 //NEEDS CHANGE

void switchInit();
void switchInterruptHandler();

extern char down, changed;
extern int period;

#endif 
