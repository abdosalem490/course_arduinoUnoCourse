#include "DHT.h"

#define DHTPIN  2 //what digital pin we are connected to

#define DHTTYPE DHT22

//initialize the object
DHT dht(DHTPIN,DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop()
{
  //wait 2 seconds for the measurement
  delay(2000);

  //read the humidity (relative humidity)
  float h = dht.readHumidity();

  //read the temperature as Celsius (default)
  float t = dht.readTemperature();

  //read the temperature as Fahrenheit(isFahrenheit = true)
  float f = dht.readTemperature(true);

  //check if any of the read faied , isnan stands for is not a number
  if(isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Failed to read from the DHT sensor");
    return;
  }

  //compute heat index in fahrenheit(default)
  float hif = dht.computeHeatIndex(f,h);
  //compute heat index in Celesius (isFahrenheit = false)
  float hic = dht.computeHeatIndex(t,h,false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  
}
