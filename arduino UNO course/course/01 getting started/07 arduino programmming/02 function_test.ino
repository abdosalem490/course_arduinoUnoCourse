void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("simple calculations using functions : ");
  Serial.println(do_a_clac(10,12));
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

int do_a_clac(int val1,int val2){
  
  return val1+val2;
}