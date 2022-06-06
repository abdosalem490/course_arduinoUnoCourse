//this code is made to use stepper motor with easy driver
// connections: Red is the common wire
// connect the wire pairs from each of the motor's coils to the screw terminals marked M1 and M2 on the shield

#include <AccelStepper.h>
#include <AFMotor.h>

#define MICROSTEPS  8 // the default setting for MICROSTEPS is 16

// 1 -> as motor is connected to M1 and M2
// 64*64 -> steps per revolution
AF_Stepper motor((64),1);

void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  
  motor.setSpeed(100);  // 10 rpm 
}

void loop()
{
  Serial.println("Single coil steps");
//  motor.step(100, FORWARD, SINGLE); 
//  motor.step(100, BACKWARD, SINGLE); 

  Serial.println("Double coil steps");
  motor.step(1000, FORWARD, DOUBLE); 
  motor.step(1000, BACKWARD, DOUBLE); 
}
