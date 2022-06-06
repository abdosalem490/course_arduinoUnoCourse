int my_integers[6] = {  1,  //index 0
                        2,  //index 1
                        3,  //index 2
                        4,  //index 3
                        5   //index 4
                     };
                        

void setup(){
  Serial.begin(9600);

  while(!Serial){
      
  }
  
  for(int index = 0; index < 5; index++)  //expriment to test what happens if index goes out of bounds
  {
    Serial.print("index ");
    Serial.print(index);
    Serial.print(" contains value ");
    Serial.println(my_integers[index]);
  }

  Serial.println();
  Serial.println("let's do some calculations");
  for(int index = 0; index < 4; index++)  //expriment to test what happens if index goes out of bounds
  {
    Serial.print(my_integers[index]); 
    Serial.print(" + ");
    Serial.print(my_integers[index+1]);
    Serial.print(" = ");
    Serial.println(my_integers[index] + my_integers[index+1]);
  }
  
    Serial.println();
    Serial.println("let's do some calculations and store the results");
    
  for(int index = 0; index < 4; index++)  //expriment to test what happens if index goes out of bounds
  {
    Serial.print(my_integers[index]); 
    Serial.print(" + ");
    Serial.print(my_integers[index+1]);
    Serial.print(" = ");
    int sum = my_integers[index] + my_integers[index+1];
    my_integers[index] = sum;
    Serial.print(my_integers[index]);
    Serial.print(" -> Index ");
    Serial.print(index);
    Serial.print(" noe contains value ");
    Serial.println(my_integers[index]);
  }
}
void loop(){
  
}
