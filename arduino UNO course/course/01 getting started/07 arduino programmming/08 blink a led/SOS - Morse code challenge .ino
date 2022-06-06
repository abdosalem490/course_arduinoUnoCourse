//the code is "...---..." where "." is a short flash of the LED and "-" is a long flash. note : you can choose your flash durations.
void setup(){
  pinMode(8,OUTPUT);
}
void loop(){
  for(int i = 0 ; i < 3; i++){
    digitalWrite(8,HIGH);
    delay(250);
    digitalWrite(8,LOW);
    delay(250);
  }
  for(int i = 0 ; i < 3; i++){
    digitalWrite(8,HIGH);
    delay(750);
    digitalWrite(8,LOW);
    delay(750);
  }
  for(int i = 0 ; i < 3; i++){
    digitalWrite(8,HIGH);
    delay(250);
    digitalWrite(8,LOW);
    delay(250);
  }

  delay(1000);
}
