int led_pin = 9; // LED connected to digital pin 9 (PWM capable)

void setup()
{
  pinMode(led_pin,OUTPUT);
}
void loop()
{
  // fade in from min to max in increments of  5 points
  for(int fadeValue = 0; fadeValue <= 255; fadeValue += 5)
  {
    // sets the value (range from 0 to 255):
    analogWrite(led_pin,fadeValue);
    // wait for 50 milliseconds to see the dimming effect
    delay(50);
  }

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255; fadeValue >= 0;fadeValue -=5)
  {
    // sets the value (range from 0 to 255)
    analogWrite(led_pin,fadeValue);
    // wait for 50 milliseconds to see the dimming effect
       delay(50);
  }
  
}
