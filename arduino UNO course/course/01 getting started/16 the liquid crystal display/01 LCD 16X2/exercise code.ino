#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("DHT");
  dht.begin();
}
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

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
