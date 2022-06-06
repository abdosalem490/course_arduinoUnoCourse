#include "touchScreen.h"
#include <TimerOne.h>


currentStatus state;
void updateStatus()
{
  updateInfo();
}
void setup(){
    state.status = "making tea
    ";
    state.timeInSeconds = 90;
    touchScreenInit();
    initStatusInfo(state);
    
    interrupts();   // to enble interrupts
    Timer1.initialize(10000);
    Timer1.attachInterrupt(updateStatus);
}

void loop(){
  
}
