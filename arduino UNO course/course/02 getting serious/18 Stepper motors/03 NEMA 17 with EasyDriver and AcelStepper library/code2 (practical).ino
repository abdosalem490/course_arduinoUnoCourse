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

int current_position = 0; // we will use this variable to keep track of the current position
int total_positions = 6;  // Total positions in the positions_to_go array
int positions_to_go[6] = { 1000,
                           -1000,
                           2000,
                           -1500,
                           1500,
                           500}; // An arbitrary set of positions for the motor to go to

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER,step_pin,direction_pin);

void setup()
{
  Serial.begin(9600);
  // play with the number 5000 to optimize the motor as it depends on youe motor
  stepper.setMaxSpeed(5000);
  stepper.setAcceleration(5000);  
}

void loop()
{
  if(stepper.distanceToGo() == 0) // if position reached...
  {
    Serial.println(current_position);
    stepper.moveTo(positions_to_go[current_position++]);
  }
  stepper.run();
  if(current_position == total_positions)   // if the motor has visited all positions , reset the counter
  {
    current_position = 0;
    delay(1000);    // wait for 1 sec before restarting
  }
}
