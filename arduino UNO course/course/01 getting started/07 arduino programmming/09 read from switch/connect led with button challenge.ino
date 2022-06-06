//this program will turn on a led as long as the button is pressed other wise it will turn off the led
int buttonState = 0;
void setup(){
  pinMode(2,INPUT);
  pinMode(8,OUTPUT);
}
void loop(){
  //led is connected on pin 8 while the button is on pin 2 and it's pulled down
  buttonState = digitalRead(2);
  if(buttonState == HIGH)
  {
    digitalWrite(8,HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
  }
  
}
