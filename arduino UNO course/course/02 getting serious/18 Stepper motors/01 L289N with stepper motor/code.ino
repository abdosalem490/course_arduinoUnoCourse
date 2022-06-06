//this code is made to use stepper motor with L298N driver
// connections:
// Arduino    |   L298N
//-------------------------
// 8          |   IN1
// 9          |   IN2
// 10         |   IN3
// 11         |   IN4
// GND        |   GND
//            |   GND to power supply GND
//            |   12V to power supply 12V

#include <Stepper.h>

const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution,8,9,10,11);

 void setup()
 {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
 }

 void loop()
 {
  // step one revolution in one direction:
  Serial.println("clockwise");
  myStepper.step(100);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-100);
  delay(500);
 }
