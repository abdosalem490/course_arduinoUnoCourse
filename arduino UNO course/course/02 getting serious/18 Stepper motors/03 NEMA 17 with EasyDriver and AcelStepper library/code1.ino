//this code is made to use stepper motor with easy driver
// connections:
// Arduino    |   L298N
//-------------------------
// 9          |   STEP
// 8          |   DIR
// GND        |   GND (adjucent to STEP and DIR)
//            |   GND (OWR IN) to power supply GND
//            |   M+ (PWR IN) to power supply 12V
//            |   MOTOR A pair to motor coil 1
//            |   MOTOR B pair to motor coil 2

#include <AccelStepper.h>

int direction_pin = 8;
int step_pin      = 9;

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER,step_pin,direction_pin);

int pos = 5000;

void setup()
{
  stepper.setMaxSpeed(5000);
  stepper.setAcceleration(1000);
  stepper.setSpeed(5000);  
}

void loop()
{
  if(stepper.distanceToGo() == 0)
  {
    delay(500);
    pos = -pos;
    stepper.moveTo(pos);
  }
  stepper.run();
}
