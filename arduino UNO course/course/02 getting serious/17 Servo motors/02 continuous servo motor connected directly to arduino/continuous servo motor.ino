// same connections as that of normal servo

#include <Servo.h>

Servo myservo;    // create servo object to control a servo
                  // a maximum of 8 servo objects can be created

void setup()
{
  myservo.attach(3);               
}

void loop()
{
  // Uncomment the following lines , one at a time , to see the effect that each one
  // has on the speed and direction of a continuous rotation servo

  //myservo.write(90);  // at this position , the servo doesn't move. 90 degrees is the resting value
  //myservo.write(100); // at this position , the servo will move slowly clockwise
  //myservo.write(145); // at this position , the servo will move faster clockwise
  myservo.write(180); // at this position , the servo will move at max speed clockwise
  //myservo.write(80);  // at this position , the servo will move at slowly speed anti-clockwise
  //myservo.write(70);  // at this position , the servo will move at faster anti-clockwise
  //myservo.write(0);   // at this position , the servo will move at a max speed anti-clockwise
}
