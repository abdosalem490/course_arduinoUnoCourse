// this code is to use only LCD with potentiometer in 4 bit mode0

#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN  7 // what pin we are connected to
#define DHTTYPE DHT22 // DHT22 (AM2302)
DHT dht(DHTPIN,DHTTYPE);

//initialize the library with the numbers of the interface pins
//LiquidCrystal(rs,enable,d4,d5,d6,d7);
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);
  // print a message to the LCD
  lcd.print("DHT test");
  dht.begin();
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // check if returns are valid , if they are NAN (not a number) then something went wrong
  if(isnan(t) || isnan(h))
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("can't get reading");
    lcd.setCursor(0,1);
    lcd.print("from DHT");
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hum: ");
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" *C"); 
  }
  delay(1000);
}
