//this code is made to use stepper motor with easy driver
// connections:
// Arduino    |   Easydriver
//-------------------------
// 9          |   STEP
// 8          |   DIR
// GND        |   GND (adjucent to STEP and DIR)
//            |   GND (OWR IN) to power supply GND
//            |   M+ (PWR IN) to power supply 12V
//            |   MOTOR A pair to motor coil 1
//            |   MOTOR B pair to motor coil 2

int direction_pin = 8;
int step_pin      = 9;

void setup()
{
  pinMode(direction_pin, OUTPUT);
  pinMode(step_pin, OUTPUT);
}

void loop()
{
  digitalWrite(direction_pin, LOW); // spin direction (lets say "clockwise" , it depends on how you connected the coils)
  // move the shaft 1600 microsteps towards one direction
  // By default , the Easydrivers uses 1/8th microsteps . this means that it generats 8
  // microsteps for each actual stepper step. Because the 17HS8401S requires 200 steps
  // for each full rotation (1.8" per step), 200 * 8 = 1600 microsteps per rotation.
  // this is why i have selected 1600 as the value in the "for" loop  below
  for (int i = 0; i < 1600; i++)
  {
    // To execute a step (or in this case , a microstep), toggle the step_pin HIGH/LOW
    // you can control the speed by the amount of delay you insert in the toggle
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(100);     // use delayMicroseconds instead of "delay" in order to make motor move faster

    // there is processing and mechanical limit on the value of the delay
    digitalWrite(step_pin, LOW);
    delayMicroseconds(100);
  }

  digitalWrite(direction_pin, HIGH); // spin in the opposite direction

  // Move the shaft 1600 microsteps towards the opposite direction.
  for (int i = 0; i < 1600; i++)
  {
    // To execute a step (or in this case , a microstep), toggle the step_pin HIGH/LOW
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(500);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(500);
  }
}
