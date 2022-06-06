int soundDetectedPin  = 10; // use Pin 10 as our Input
int soundDetectedVal  = HIGH; // this is where we record our sound measurement
boolean bAlarm  = false;
unsigned long lastSoundDetectTime;  // Record the time that we measured a sound
int soundAlarmTime = 500; // number of milli seconds to keep the sound alarm high
int ledPin = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(soundDetectedPin,INPUT);  
}

void loop()
{
  soundDetectedVal = digitalRead(soundDetectedPin);  // read the sound alarm time

  // if we hear a sound
  if(soundDetectedVal == HIGH)  
  {
    digitalWrite(ledPin,HIGH);  // tuen on the led to show thers is a loud noise
    lastSoundDetectTime = millis(); // record time of sound alarm

    // if signal alarm remains at HIGH , it will output the LOUD message
    if(!bAlarm)
    {
      Serial.println("LOUD!");
      bAlarm = true;
    }
  }
  if((millis()-lastSoundDetectTime) > soundAlarmTime && bAlarm)
  {
    Serial.println("quiet");
    digitalWrite(ledPin,LOW);
    bAlarm = false;
  }

  
}
