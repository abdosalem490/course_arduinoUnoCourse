#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

void setup()
{
  Serial.begin(9600);
  Serial.println("MCP9808 demo");

  // make sure the sensor is found, you can also pass in a different i2c
  // address with temperature.begin(0X19) for example
  if(!tempsensor.begin(0x18))
  {
    Serial.println("Couldn't find MCP9808!");
    while(1);
  }
}

void loop()
{
  // Read and print out the temperature, then convert to *F
  float c = tempsensor.readTempC();
  float f = c * 9.0 / 5.0 + 32;
  Serial.print("Temp: "); Serial.print(c);  Serial.print("*C\t");
  delay(250);

  // shutdown MSP9808 - power consumption ~0.1 mikro ampere
  Serial.println("Shutdown MCP9808.... "); 
  tempsensor.shutdown_wake(1);
  
  delay(2000);

  // wake up MSP9808 - power consumption ~200 mikro ampere 
  Serial.println("wake up MCP9808.... ");
  tempsensor.shutdown_wake(0);
}
