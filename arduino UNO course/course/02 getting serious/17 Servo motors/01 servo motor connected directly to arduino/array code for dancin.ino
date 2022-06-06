#include <Servo.h>

Servo myservo1, myservo2;   // Create servo object to control a servo
// a maximum of 8 servo objects can be created

int posIndex = 0;  // variable to store the servo position
int const total_positions = 10;
int servo_positions[total_positions] = 
      {156,79,88,152,34,144,28,174,117,27};

void setup()
{
  myservo1.attach(3); // attaches the servo on pin 3 to the servo object
  myservo2.attach(10);
}

void loop()
{
  // if you are using a normal 180-degree servo, try the following
  // The code below sweeps the servo from 0 to 180 degrees
  // If you notice that your servo is "trashing" when it reaches the ends of its travel
  // path, increase the low end by a little (say, make it 10 degrees) and decrease the
  // top end by a little (say, make it 170 degrees);
  for (posIndex = 0; posIndex <= total_positions; posIndex += 1) // goes from 0 degrees to 180 degrees
  {
    // in steps of 1 degree
    myservo1.write(servo_positions[posIndex]);  // tell servo 1 to go to new position
    delay(100);                                 // insert small delay to give servo 1 a head start
    myservo2.write(servo_positions[posIndex]);  // tell servo 2 to go to new position
    delay(400);                                 // wait for servo 2 to reach the position
    
  }

}
