#include "header.h"
#include <string.h>
#include <stdlib.h>


void chooseState(){

  if(!(P2IN & BIT0)){state = 1; start = 1;} //keep it simple, each button triggers a state.
  if(!(P2IN & BIT1)){state = 2; start = 1;}
  if(!(P2IN & BIT2)){state = 3; start = 1;}
  if(!(P2IN & BIT3)){state = 0;}            //state 0 will mute buzzer, use for peace.
  
  stateHandler(state);

}


void stateHandler(int state){//this method makes it so the state keeps running the buzzer in time. 
  
  static char blink_count = 0;//initialize the counter to be zero only once

 if(start){//this condition is only for when the machine is turned on for the first time.
 if(state == prev){
   
    if(++blink_count == time){
      buzzerUpdate(prev);//the buzzer is updated based on state.
      blink_count = 0;
    }
 }else{
   prev = state;
 }
 }
 
}
