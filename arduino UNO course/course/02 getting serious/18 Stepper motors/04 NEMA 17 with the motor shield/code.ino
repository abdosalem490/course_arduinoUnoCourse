//this code is made to use stepper motor with easy driver
// connections:
// connect the wire pairs from each of the motor's coils to the screw terminals marked M1 and M2 on the shield
// didin't have same shield so couldn't run same code
#include <AccelStepper.h>
#include <AFMotor.h>

#define MICROSTEPS  8 // the default setting for MICROSTEPS is 16

// 1 -> as motor is connected to M1 and M2
// 200 -> steps per revolution
AF_Stepper motor(200,1);

void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  
  motor.setSpeed(10);  // 10 rpm 
}

void loop()
{
  Serial.println("Single coil steps");
  motor.step(100, FORWARD, SINGLE); 
  motor.step(100, BACKWARD, SINGLE); 

  Serial.println("Double coil steps");
  motor.step(100, FORWARD, DOUBLE); 
  motor.step(100, BACKWARD, DOUBLE);

  Serial.println("Interleave coil steps");
  motor.step(100, FORWARD, INTERLEAVE); 
  motor.step(100, BACKWARD, INTERLEAVE); 

  Serial.println("Micrsostep steps");
  motor.step(100, FORWARD, MICROSTEP); 
  motor.step(100, BACKWARD, MICROSTEP); 
}
