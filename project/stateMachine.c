#include "header.h"
#include <string.h>
#include <stdlib.h>

void stateHandler(int state){
  
static char blink_count = 0;

 if(start){
 if(state == prev){
   
    if(++blink_count == time){
      buzzerUpdate(prev);
      blink_count = 0;
    }
 }else{
   prev = state;
 }
 }
 
}
