const int buzzer = 8;

void setup()
{
  pinMode(buzzer,OUTPUT);
}
void loop()
{
  tone(buzzer,1000);  // send 1KHZ sound signal
  delay(1000);        // for 1 second
  noTone(buzzer);     // Stop sound
  delay(1000);        // ... for 1 sec
}
