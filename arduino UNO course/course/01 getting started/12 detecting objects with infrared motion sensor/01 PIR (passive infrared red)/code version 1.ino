int ledPin = 4; // choose the pin for the LED
int inputPin = 3;  // PIR sensor input pin
int pirState  = LOW;  // we start, assuming no motion detected
int val = 0; // variable for reading the pin status

// the time we give the sensor to calibrate (10-60 sec according to the datasheet)
int calibrationTime = 30; // this time is in seconds

void setup()
{
  pinMode(ledPin,OUTPUT); // LED is output
  pinMode(inputPin,INPUT);  // sensor is input

  Serial.begin(9600);
  Serial.println("Waiting for the sensor to warm up");
  Serial.println("SENSOR ACTIVE");
}

void loop()
{
  val =  digitalRead(inputPin); // read input value

  // check if the input is HIGH
  if(val == HIGH)
  {
    // turn on the led
    digitalWrite(ledPin,HIGH);
    if(pirState == LOW)
    {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  }
  else
  {
    // turn LED OFF
    digitalWrite(ledPin,LOW);
    if(pirState == HIGH)
    {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
  
  delay(1000);
}
