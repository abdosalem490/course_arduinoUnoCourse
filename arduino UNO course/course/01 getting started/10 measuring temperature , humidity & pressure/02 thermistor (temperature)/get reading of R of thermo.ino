// the value of the other resistor conected in series with NTC , i am using 10 Kohm resistor
#define SERIES_RESISTOR 9950

//the pin that is we will obtain readings from
#define THERMISTOR_PIN  A0

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  float reading;
  reading = analogRead(THERMISTOR_PIN);

  Serial.print("Analog reading ");
  Serial.println(reading);

  //the idea of theses conversion is written in the notes or you can serach for voltage divider
  //convert the value to resistance
  reading = (1023 / reading) - 1;
  reading = SERIES_RESISTOR / reading;
  Serial.print("Thermistor resistance ");
  Serial.println(reading);

  delay(1000);
  
}
