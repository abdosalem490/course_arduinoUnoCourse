#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello world!");
  lcd.setCursor(0,1);
  lcd.print("Row number: ");
  lcd.setCursor(12,1);
  lcd.print("2");
}
void loop()
{
  
}
