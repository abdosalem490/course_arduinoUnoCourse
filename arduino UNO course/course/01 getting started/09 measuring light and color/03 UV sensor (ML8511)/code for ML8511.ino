// this code is for GYML8511 , because i couldn't find the GUVA-S12SD sensor
// also pin configuration as follow :
// vin => vin on arduino (i think it's optional pin for sensor)
// 3V3 => A1 on arduino
// GND => GND on arduino
// OUT => A0 on arduino
// En => 3V3 on arduino so that it's always enabled

// Hardware pin definitions
int UVOUT = A0; //Output from the sensor
int REF_3V3 = A1; //3.3V power on the Arduino board

void setup()
{
  Serial.begin(9600);

  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);

  Serial.println("example");
}

void loop()
{
  int uvLevel = averageAnalogRead(UVOUT);
  int refLevel = averageAnalogRead(REF_3V3);

  // Use the 3.3V power pin as a reference to get a very accurate output value from the sensor
  float outputVoltage = 3.3 / refLevel * uvLevel;
  float uvIntensity = mapfloat(outputVoltage,0.99,2.9,0.0,15.0);

  Serial.print("ML8511 output: ");
  Serial.print(uvLevel);

  Serial.print(" ML8511 voltage: ");
  Serial.print(uvIntensity);

  Serial.println();

  delay(100);
}

// Takes an average of readings on a given pin
// Returns the average
int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0;

  for (int x = 0; x < numberOfReadings; x++)
    runningValue += analogRead(pinToRead);

  runningValue /= numberOfReadings;
  return runningValue;
}

// The Arduino Map function but for floats
// From: http://forum.arduino.cc/index.php?topic=3922.0
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
