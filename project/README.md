# UTEP Arch1 - Project2 - Blinky Buzzy Toys

This project consists of programming the MSP430 to act as a music box.

## Functionalities: 

- Play one of two songs continuosly.
- The songs can be programmed in on the buzzer.c file.
- The note durations of any song can be programmed.
- Songs can be changed any time, not need to wait for one song to finish to play the other.
- LEDS react to the note frequency, dimming with lower frequencies.

## Files: 

**main.c**: contains the main method only, it initiallizes the global variables and IO.

**switches.c**: contains the method for switch initialization.

**handler.c**: contains the exception subroutine for the WDT.

**stateMachine.c**: contains the methods that deal with maintaining the achine in a desired state and behaving as expected sets states according to input being received, and previous state.

**leds.c**: contains the method to initialize the LEDS and also the method that serves as the "lightshow"

**buzzer.c**: contains the piano and the method that reads the melody note by note.

## HOWTO:  

1. To start song 1: Press switch 1.
2. To start song 2: Press switch 2.
3. To stop melody: Press switch 3.

###### Piano: 

 'j' = E3
 'i' = F3
 'I' = F#3
 'h' = G3
 'H' = G#3
 'a' = A3
 'A' = A#3
 'b' = B3
 'c' = C4
 'C' = C#4
 'd' = D4
 'D' = D#4
 'e' = E4
 'f' = F4
 'F' = F#4
 'g' = G4
 'G' = G#4
 'p' = A4
 'P' = A#4
 'q' = B4
 'r' = C5
 'R' = C#5
 's' = D5
 'S' = D#5


