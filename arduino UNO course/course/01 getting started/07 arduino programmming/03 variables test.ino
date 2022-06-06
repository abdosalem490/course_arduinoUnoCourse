const int first_num = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("simple calculations using functions : ");
  
  int second_num = 12;
  Serial.println(do_a_clac(second_num));
}

void loop() {
  // put your main code here, to run repeatedly:
}

int do_a_clac(int val_2){
  //first_num = 3;
  int result = first_num+val_2;
  return result;
}
