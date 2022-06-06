// connections of the shield : 4 bit mode
//  D4  |   4
//  D5  |   5
//  D6  |   6
//  D7  |   7
//  E   |   9
//  RS  |   8
// for the buttons : they all give readings at A0 where
// Select | 722
// Left   | 481
// Up     | 132
// down   | 307
// Right  | 0
// RST : it resets the microController

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);        // select the pins used on the LCD panel

unsigned long tepTimer ;

void setup(){
  Serial.begin(9600);
  
  
    lcd.begin(16, 2);                       // start the library
    lcd.print("gosdfsdfasdfasdfas");
}

void loop(){
   int a = analogRead(A0);
   Serial.println(a);
   delay(50);
    
    
}
