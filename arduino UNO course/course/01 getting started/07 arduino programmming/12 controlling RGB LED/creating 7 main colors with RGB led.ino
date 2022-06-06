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
  digitalWrite(RedLedPin,HIGH);
  digitalWrite(GreenLedPin,LOW);
  digitalWrite(BlueLedPin,LOW);
  delay(1000);

  //only green
  digitalWrite(RedLedPin,LOW);
  digitalWrite(GreenLedPin,HIGH);
  digitalWrite(BlueLedPin,LOW);
  delay(1000);

  //only blue
  digitalWrite(RedLedPin,LOW);
  digitalWrite(GreenLedPin,LOW);
  digitalWrite(BlueLedPin,HIGH);
  delay(1000);
  
  //red with green
  digitalWrite(RedLedPin,HIGH);
  digitalWrite(GreenLedPin,HIGH);
  digitalWrite(BlueLedPin,LOW);
  delay(1000);

  //red with blue
  digitalWrite(RedLedPin,HIGH);
  digitalWrite(GreenLedPin,LOW);
  digitalWrite(BlueLedPin,HIGH);
  delay(1000);

  //green with blue
  digitalWrite(RedLedPin,LOW);
  digitalWrite(GreenLedPin,HIGH);
  digitalWrite(BlueLedPin,HIGH);
  delay(1000);

  //all together
  digitalWrite(RedLedPin,HIGH);
  digitalWrite(GreenLedPin,HIGH);
  digitalWrite(BlueLedPin,HIGH);
  delay(1000);
}
