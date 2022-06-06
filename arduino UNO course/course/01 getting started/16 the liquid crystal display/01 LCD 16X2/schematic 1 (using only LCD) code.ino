// this code is to use only LCD with potentiometer in 4 bit mode0

#include <LiquidCrystal.h>

//initialize the library with the numbers of the interface pins
//LiquidCrystal(rs,enable,d4,d5,d6,d7);
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);
  // print a message to the LCD
  lcd.print("hello,world!");
}

void loop()
{
  // set the cursor to column 0,line 1
  // (note that : 1Line 1 is the second row where counting begins with 0)
  lcd.setCursor(0,1);
  // print the number of seconds since reset
  lcd.print(millis()/1000);  
}
