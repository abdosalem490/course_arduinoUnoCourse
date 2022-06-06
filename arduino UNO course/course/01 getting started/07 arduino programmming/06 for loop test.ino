int c = 0;
void setup(){
  Serial.begin(9600);
}
void loop(){
  for(int c = 1; c <= 20 ; c++)
  {
    if(c < 10)
    {
      Serial.print(c);
      Serial.print(", ");
      Serial.println("Counter is smaller than 10");
    }
    else
    {
      Serial.print(c);
      Serial.print(", ");
      Serial.println("Counter is not smaller than 10");
    }
    delay(500);
  }
}
