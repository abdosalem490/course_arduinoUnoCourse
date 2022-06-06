int led_pin = 9;

void setup()
{
  pinMode(led_pin,OUTPUT);
}
void loop()
{
  digitalWrite(led_pin,HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                // wait for a second
  digitalWrite(led_pin,LOW);  // turn the LED off by makiung the voltage LOW
  delay(1000);                // wait for a second
}
