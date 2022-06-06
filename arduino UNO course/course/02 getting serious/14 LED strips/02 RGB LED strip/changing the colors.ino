int ledPin1 = 9;  // LED connected to digital pin 9  (PWM capable)
int ledPin2 = 10; // LED connected to digital pin 10 (PWM capable)
int ledPin3 = 11; // LED connected to digital pin 11 (PWM capable)

void setup()
{
  // if analog input pin 0 is unconnected , random analog 
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function
  randomSeed(analogRead(0));
}
void loop()
{
  analogWrite(ledPin1,random(255)); // Write a radnom PWM value to the first color of the RGB LED strip
  analogWrite(ledPin2,random(255)); // Write a radnom PWM value to the sceond color of the RGB LED strip
  analogWrite(ledPin3,random(255)); // Write a radnom PWM value to the third color of the RGB LED strip
  delay(100);
}
