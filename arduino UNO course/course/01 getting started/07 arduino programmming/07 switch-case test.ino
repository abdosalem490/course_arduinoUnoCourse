int buttonPressed = 1;
void setup(){
  Serial.begin(9600);

  switch(buttonPressed){
    case 1:
      Serial.println("Button 1 pressed");
      break;
    case 2:
      Serial.println("Button 2 pressed");
      break;
    default:
      Serial.println("I don't know which button was pressed");
      //default is optional
      break; 
  }
}
void loop(){
  
}
