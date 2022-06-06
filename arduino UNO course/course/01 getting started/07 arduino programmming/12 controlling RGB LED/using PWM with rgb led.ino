#define RedLedPin 3
#define GreenLedPin 5
#define BlueLedPin  6
  
void setup(){
  pinMode(RedLedPin,OUTPUT);
  pinMode(GreenLedPin,OUTPUT);
  pinMode(BlueLedPin,OUTPUT);
  
}
void loop(){
  
  //only red
  for(int i = 0; i < 255;i++)
  {
    analogWrite(RedLedPin,i);
    analogWrite(GreenLedPin,255-i);
    analogWrite(BlueLedPin,255-i);
    delay(20);
  }
  

  //only green
  for(int i = 0; i < 255;i++)
  {
    analogWrite(RedLedPin,255-i);
    analogWrite(GreenLedPin,i);
    analogWrite(BlueLedPin,255-i);
    delay(20);
  }

  //only blue
  for(int i = 0; i < 255;i++)
  {
    analogWrite(RedLedPin,255-i);
    analogWrite(GreenLedPin,255-i);
    analogWrite(BlueLedPin,i);
    delay(20);
  }
  
  //red with green
  for(int i = 0; i < 255;i++)
  {
    analogWrite(RedLedPin,i);
    analogWrite(GreenLedPin,i);
    analogWrite(BlueLedPin,255-i);
    delay(20);
  }

  //red with blue
  for(int i = 0; i < 255;i++)
  {
    analogWrite(RedLedPin,i);
    analogWrite(GreenLedPin,255-i);
    analogWrite(BlueLedPin,i);
    delay(20);
  }

  //green with blue
  for(int i = 0; i < 255;i++)
  {
    analogWrite(RedLedPin,255-i);
    analogWrite(GreenLedPin,i);
    analogWrite(BlueLedPin,i);
    delay(20);
  }

  //all together
  for(int i = 0; i < 255;i++)
  {
    analogWrite(RedLedPin,i);
    analogWrite(GreenLedPin,i);
    analogWrite(BlueLedPin,i);
    delay(20);
  }
}
