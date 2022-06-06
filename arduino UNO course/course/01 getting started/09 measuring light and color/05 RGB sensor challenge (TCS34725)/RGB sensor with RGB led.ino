#include <Wire.h>
#include "Adafruit_TCS34725.h"

// creating the sensor object
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

#define redPin 3
#define greenPin 5
#define bluePin 6

#define commonAnode false

//to convert RGB value to value that human eye can understand
byte gammatable[256];

void setup()
{
  Serial.begin(9600);
  Serial.println("Color View test");

  if (tcs.begin())
  {
    Serial.println("Found sensor");
  }
  else
  {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); //halt!
  }

  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

  //this code helps to convert RGB colors to what humans see
  for(int i=0; i < 256;i++)
  {
    float x = i;
    x /= 255;
    x = pow(x,2.5);
    x *= 255;

    if(commonAnode){
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;
    }
  }
}

void loop()
{
  uint16_t clear, red , green , blue;

  tcs.setInterrupt(false); // turn on LED

  delay(60);  // takes 50ms to read

  tcs.getRawData(&red, &green, &blue, &clear);
  
  Serial.print("C:\t");   Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.println(blue);

  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r,g,b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;

  r *= 256; g *= 256; b *= 256;
  Serial.print("\t");
  Serial.print((int)r,HEX); Serial.print((int)g,HEX); Serial.print((int)b,HEX);

  analogWrite(redPin,gammatable[(int)r]);
  analogWrite(greenPin,gammatable[(int)g]);
  analogWrite(bluePin,gammatable[(int)b]);
}
