// Arduino    |   ULN2003 breakout
//---------------------------------
// 3          |   IN1
// 4          |   IN2
// 5          |   IN3
// 6          |   IN4
// GND        |   ___
//            |   - to power supply GND
//            |   + to power supply 5v

#include <AccelStepper.h>

// Motor pin definitions
#define   motorPin1   3   // IN1 on the ULN2003 driver 1
#define   motorPin2   4   // IN2 on the ULN2003 driver 1
#define   motorPin3   5   // IN3 on the ULN2003 driver 1
#define   motorPin4   6   // IN4 on the ULN2003 driver 1

int position_to_go = 4000;  // An arbitrary position for the motor to go to

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(AccelStepper::FULL4WIRE,motorPin1,motorPin3,motorPin2,motorPin4);

void setup()
{
  stepper1.setMaxSpeed(500);  // you can work out these values for your stepper motor via trial and error
  stepper1.setSpeed(500);     // this speed seems to work well for the 28BYJ-48 stepper
  stepper1.setAcceleration(400.0);  // This value gives quick acceleration to set speed
  stepper1.setCurrentPosition(0);   // This is the position where the motor happens to find itself when the sketch starts
  stepper1.moveTo(position_to_go);  // The first position for the motor to move to
}

void loop()
{
  if(stepper1.distanceToGo() == 0)  // if position reached...
  {
    stepper1.moveTo(-stepper1.currentPosition()); // Go back to the opposite position
  }
  stepper1.run();
} 
