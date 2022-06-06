int x_axis = A3;
int y_axis = A2;
int z_axis = A1;

// analog input pin 4 -- ground
// analog pins can be treated as digital pins
// analog pin 4 corresponds to digital pin 18
const int groundPin = 18;

// analog input pin 5 -- voltage
// analog pin 5 corresponds to digital pin 19
const int powerPin = 19;

// these variables will hold the raw sensor values
int x, y, z;

void setup()
{
  // use AREF to make 3.3V the reference used by ADC
  analogReference(EXTERNAL);

  pinMode(groundPin,OUTPUT);
  pinMode(powerPin,OUTPUT);
  digitalWrite(groundPin,LOW);
  digitalWrite(powerPin,HIGH);

  Serial.begin(9600);
  delay(1000);
}

void loop()
{
  x = analogRead(x_axis);
  y = analogRead(y_axis);
  z = analogRead(z_axis);

  // print the raw value in the X axis
  Serial.print(x);
  // prints a tab between the numbers
  Serial.print("\t");
  // print the raw value in the Y axis
  Serial.print(y);
  // prints a tab between the numbers
  Serial.print("\t");
  // print the raw value in the Z axis
  Serial.print(z);
  Serial.println();

  delay(100);
}
