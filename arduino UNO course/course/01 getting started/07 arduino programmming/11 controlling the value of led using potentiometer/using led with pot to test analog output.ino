int potValue;
//potentiometer is connected on pin A0
//led is connected on pin 3~
void setup(){
  pinMode(3,OUTPUT);
}
void loop(){
  potValue = analogRead(A0);
  //possible values of analog input (0->1023),possible values of analog output (PWM) (0->255)
  potValue = map(potValue,0,1023,0,255);
  analogWrite(3,potValue);
}
