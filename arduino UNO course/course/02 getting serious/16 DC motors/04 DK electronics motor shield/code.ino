// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

//TEST ALL WHEELS AT ONCE TO TEST ALL FOUR WHEELS

#include <AFMotor.h>

AF_DCMotor motor4(4);
AF_DCMotor motor3(3);
AF_DCMotor motor2(2);
AF_DCMotor motor1(1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor

}

void loop() {

   
  Serial.print("tick");
  
  motor4.run(FORWARD);
   motor4.setSpeed(200);
    motor3.run(FORWARD);
   motor3.setSpeed(200);
   motor2.run(FORWARD);
   motor2.setSpeed(200);
   motor1.run(FORWARD);
   motor1.setSpeed(200);
   
    delay(1000);
 
  


  motor4.run(RELEASE);
    motor3.run(RELEASE);
    motor2.run(RELEASE);
    motor1.run(RELEASE);
     
  delay(1000);
  Serial.print("tick");
  
  motor4.run(BACKWARD);
   motor4.setSpeed(200);
    motor3.run(BACKWARD);
   motor3.setSpeed(200);
   motor2.run(BACKWARD);
   motor2.setSpeed(200);
   motor1.run(BACKWARD);
   motor1.setSpeed(200);
   
    delay(1000);
 
  


  motor4.run(RELEASE);
    motor3.run(RELEASE);
    motor2.run(RELEASE);
    motor1.run(RELEASE);
    delay(1000);
}
