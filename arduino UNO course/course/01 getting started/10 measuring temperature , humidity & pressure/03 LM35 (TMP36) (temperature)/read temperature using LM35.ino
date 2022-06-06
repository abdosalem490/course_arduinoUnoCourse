int sensorPin = 0; // reading obtained from analog pin 0 (A0)
float supplyVoltage = 5;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // get the voltage raeding from LM35
  int reading = analogRead(sensorPin);

  // converting that reading to voltage
  float voltage = reading * supplyVoltage / 1024;

  // print the voltage
  Serial.print(voltage);  Serial.println(" volts");

  // now print the temperature , as in datasheet it says 10 mV per degree
  float temperatureC = voltage * 100;

  Serial.print(temperatureC); Serial.println(" degrees C");

  // noe convert it to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");

  delay(1000);
}
