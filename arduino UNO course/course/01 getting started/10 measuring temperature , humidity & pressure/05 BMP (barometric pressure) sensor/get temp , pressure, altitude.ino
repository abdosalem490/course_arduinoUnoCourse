#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

// creating bmp180 objects
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

// display basic informations from the sensor
void displaySensorDetails(void)
{
  sensor_t sensor;
  bmp.getSensor(&sensor);
  Serial.println("-------------------------------------------");
  Serial.print("Sensor:       "); Serial.println(sensor.name);
  Serial.print("Driver ver:   "); Serial.println(sensor.version);
  Serial.print("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print("max value:    "); Serial.print(sensor.max_value); Serial.println(" hpa");
  Serial.print("min Value:    "); Serial.print(sensor.min_value); Serial.println(" hPa");
  Serial.print("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" hPa");
  Serial.println("-------------------------------------------");
  Serial.println("");
  delay(500);
}

void setup(void)
{
  Serial.begin(9600);
  Serial.println("pressure sensor test");  Serial.println("");
  Serial.println("Starting");

  bmp.begin();

  //initialize the sensor
  if(!bmp.begin())
  {
    // thers is a problem with initializing bmp180
    Serial.print("Oooops, no BMP180 detected ... check your wiring or I2C ADDR!");
    while(1);
  }
  Serial.println("Started");

  //display the basic informations
  displaySensorDetails();
}

void loop(void)
{
  // get a new sensor event
  sensors_event_t event;
  bmp.getEvent(&event);

  // display the results ( pressures is messure in hPa)
  if(event.pressure)
  {
    // display the pressure in hPa
    Serial.print("pressure: ");
    Serial.print(event.pressure);
    Serial.println(" hPa");

    // get current temperature
    float temperature;
    bmp.getTemperature(&temperature);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    // from atmosperic pressure and SLP to alitude
    float seaLevelPressure  = 1013;
    Serial.print("Altitude: ");
    Serial.print(bmp.pressureToAltitude(seaLevelPressure,event.pressure));

    Serial.println(" m");
    Serial.println("");
  }
  else
  {
    Serial.println("Sensor error");
  }
  delay(1000);
}
