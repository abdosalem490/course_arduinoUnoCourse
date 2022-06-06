#include <Adafruit_MotorShield.h>

// Create the motor shield with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// you can create it with different I2C address for example:
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which port (M1 or M2 or M3 or M4) 
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);  // Get handle for motor 1
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);  // Get handle for motor 2

void setup()
{
  AFMS.begin();
}

void loop()
{
  motor1->run(FORWARD); // run forward for half a second
  motor1->setSpeed(50);

  motor2->run(FORWARD); // run forward for half a second
  motor2->setSpeed(150);

  delay(500);

  motor1->run(RELEASE); // run in idle for half a second
  motor2->run(RELEASE); // run in idle for half a second
  delay(500);

  motor1->run(BACKWARD);// run backward for half a second
  motor1->setSpeed(50);

  motor2->run(BACKWARD);// run backward for half a second
  motor2->setSpeed(150);

   delay(500);

   motor1->run(RELEASE);// run in idle for half a second
   motor2->run(RELEASE);// run in idle for half a second

   delay(500);
}
