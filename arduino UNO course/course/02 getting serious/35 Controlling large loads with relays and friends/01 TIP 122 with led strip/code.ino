/*
Pushbutton interrupt sketch
a switch connected to interrupt pin 2 lights the LED on pin 13
*/
const int ledPin = 13; 
long randOn = 0;
long randOff = 0;
void setup() { 
  pinMode(ledPin, OUTPUT);
  randomSeed(analogRead(0));
}

void loop()
{
   randOn = random(50,500);
   randOff = random(50,500);
   digitalWrite(ledPin,HIGH);
   delay(randOn);
   digitalWrite(ledPin,LOW);
   delay(randOff);
} 
