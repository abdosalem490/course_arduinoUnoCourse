// connections 
// Arduino    |   L298N
//------------------------
// GND        |   GND
// 5          |   IN1
// 4          |   IN2
// 3          |   IN3
// 2          |   IN4
//            |   OUT1  --> Motor 1 Wire 1
//            |   OUT2  --> Motor 1 Wire 2
//            |   OUT3  --> Motor 2 Wire 1
//            |   OUT4  --> Motor 2 Wire 2
//            |   +12V  --> 5V power supply
//            |   GND   --> GND power supply

int speed1_pin      = 5;     // Controls speed (PWM) for motor 1
int direction1_pin  = 4;     // Controls direction for motor 1
int speed2_pin      = 3;     // Controls speed (PWM) for motor 2
int direction2_pin  = 2;     // Controls direction for motor 2

bool direction = HIGH;  // start the motor by moving it towards one direction. whether it is
                        // clockwise o anticlockwise depends on how you have connected the 
                        // motor's coil

void setup()
{
  pinMode(direction1_pin,OUTPUT);
  pinMode(speed1_pin,OUTPUT);
  pinMode(direction2_pin,OUTPUT);
  pinMode(speed2_pin,OUTPUT);
}

void loop()
{
  digitalWrite(direction1_pin,direction);   // Direction control motor 1
  digitalWrite(direction2_pin,direction);   // Direction control motor 2
  
  analogWrite(speed1_pin,50);               // PWM speed control motor 1
  analogWrite(speed2_pin,150);              // PWM speed control motor 2
  delay(1000);

  analogWrite(speed1_pin,100);              // PWM speed control motor 1
  analogWrite(speed2_pin,200);              // PWM speed control motor 2
  delay(1000);

  analogWrite(speed1_pin,255);              // PWM speed control motor 1
  analogWrite(speed2_pin,255);              // PWM speed control motor 2
  delay(1000);

  direction = !direction;                   // Switch direction
  analogWrite(speed1_pin,0);                // Stop motor 1 before starting again in the opposite direction
  analogWrite(speed2_pin,0);                // Stop motor 2 before starting again in the opposite direction
}
