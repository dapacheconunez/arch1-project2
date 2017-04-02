#ifndef buzzer_included
#define buzzer_included

void buzzerInit();
void buzzerSetPeriod(int period);
void buzzerUpdate();
void setMelody();

extern int period;

#endif
