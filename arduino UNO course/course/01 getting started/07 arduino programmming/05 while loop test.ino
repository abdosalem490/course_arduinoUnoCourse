int c = 0;
void setup(){
  Serial.begin(9600);
}
void loop(){
  while(c < 10)
  {
    Serial.print(c);
    Serial.print(", ");
    Serial.println("Counter is smaller than 10");
    c++;
  }
  delay(500);
  c++;
}
