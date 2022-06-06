int ledPin = 4; // choose the pin for the LED
int inputPin = 3;  // PIR sensor input pin
int pirState  = true;  // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int minSecAfterPIRLow = 5000; // Led remains high after the sensor reports Low for 5 seconds

long unsigned int timeTurnedLow;
boolean takeLowTime;  // to record event where the sensor turns off

// the time we give the sensor to calibrate (10-60 sec according to the datasheet)
int calibrationTime = 30; // this time is in milliseconds

void setup()
{
  pinMode(ledPin, OUTPUT); // LED is output
  pinMode(inputPin, INPUT); // sensor is input

  takeLowTime = LOW;

  Serial.begin(9600);
  Serial.println("Waiting for the sensor to warm up");
  delay(calibrationTime * 1000);
  Serial.println("SENSOR ACTIVE");
}

void loop()
{
  val =  digitalRead(inputPin); // read input value

  // check if the input is HIGH
  if (val == HIGH)
  {
    // turn on the led
    digitalWrite(ledPin, HIGH);
    if (pirState == LOW)
    {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  }
  else
  {
    if (pirState == HIGH)
    {
      Serial.println("Motion ended!");
      pirState = LOW;
      timeTurnedLow = millis();  // take the millis at the moment the sensor went low
    }
  }

// check if enough time has passed since PIR went low
if (!pirState && (millis() - timeTurnedLow) > minSecAfterPIRLow)
{
  Serial.println("Extended time HIGH ended!");
  digitalWrite(ledPin,LOW);
}

delay(1000);
}
