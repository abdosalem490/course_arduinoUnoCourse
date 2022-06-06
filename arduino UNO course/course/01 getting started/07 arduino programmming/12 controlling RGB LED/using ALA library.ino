#include <AlaLedRgb.h>

#define RedLedPin 3
#define GreenLedPin 5
#define BlueLedPin  6

AlaLedRgb rgbLed;
  
void setup(){
  rgbLed.initPWM(RedLedPin, GreenLedPin, BlueLedPin);                 // initialize output pins
  rgbLed.setBrightness(0x66FF44);                            // calibrate white
  //this is animation of changing colors , to view all kinds of animations visit http://yaab-arduino.blogspot.com/p/ala-animations.html 
  //or go their github link from useful links folder (https://github.com/bportaluri/ALA)
  
  //rgbLed.setAnimation(ALA_FADECOLORSLOOP, 5000, alaPalRgb);  // set the animation
  rgbLed.setAnimation(ALA_GLOW, 5000, alaPalRgb);
}
void loop(){
   rgbLed.runAnimation();
}
