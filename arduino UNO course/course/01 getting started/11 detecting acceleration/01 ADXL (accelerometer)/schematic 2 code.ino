int x_axis = A3;
int y_axis = A2;
int z_axis = A1;

// analog input pin 0 -- ground
// analog pins can be treated as digital pins
// analog pin 0 corresponds to digital pin 14
const int groundPin = A0;

// analog input pin 4 -- voltage
// analog pin 4 corresponds to digital pin 18
const int powerPin = A4;

// these variables will hold the raw sensor values
int x, y, z;

void setup()
{
  pinMode(groundPin, OUTPUT);
  pinMode(powerPin, OUTPUT);
  digitalWrite(groundPin, LOW);
  digitalWrite(powerPin, HIGH);

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

  if ((x > 325 && x < 335) && (y > 320 && y < 350) && (z > 390 && z < 410))
  {
    Serial.println("I am horizontal");
  }
  else if ((x > 325 && x < 335) && (y > 320 && y < 350) && (z > 255 && z < 275))
  {
    Serial.println("I am flipped");
  }
  else
  {
    Serial.println(" I don't know which way I'm sitting!");
  }
  delay(100);
}
