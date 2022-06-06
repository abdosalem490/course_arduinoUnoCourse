#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <XPT2046_Touchscreen.h>

#define NUM_OF_MEALS 8

// For the Adafruit shield, these are the default.
#define TFT_DC 9

#define TFT_RST 8

// chip select
#define Touch_CS 7
#define TFT_CS 10
#define SD_CS 6


// MOSI=11, MISO=12, SCK=13

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_RST);
XPT2046_Touchscreen ts(Touch_CS, 255);



typedef struct{
  int16_t x;
  int16_t y;
  const int16_t w = 100;
  const int16_t h = 100;
  const int16_t radius = 20;
  const int16_t color = ILI9341_WHITE;
  String title;
}rect;

rect mealsBox[NUM_OF_MEALS];


void mealPage()
{
  // chaning background
  tft.fillScreen(ILI9341_DARKCYAN);
  yield();

  // needed for the title
  int startTitlePos = 40;
  int endTitlePos = 192;
  int titleUnderLineY = 20;

  // writing title with underline
  tft.setTextSize(2);
  tft.setCursor(startTitlePos,0);
  tft.println("select a meal");
  tft.setTextColor(ILI9341_WHITE);
  yield();
  tft.drawLine(startTitlePos,titleUnderLineY,endTitlePos,titleUnderLineY,ILI9341_WHITE);
  yield();

  // making round rectangles for meals
  tft.setTextSize(2);
  for(int i = 0; i < 4;i++){
    tft.drawRoundRect(mealsBox[i].x,mealsBox[i].y,mealsBox[i].w,mealsBox[i].h,mealsBox[i].radius,mealsBox[i].color );
    tft.setCursor(mealsBox[i].x,mealsBox[i].y + mealsBox[i].h);
    tft.println(mealsBox[i].title);
  }

  // make a rectangle that points downwards
  // 120,320 -> peak <> other numbers are for other legs
  tft.fillTriangle(120,310,70,290,170,290,ILI9341_WHITE);

  // draw circle for paint and game
  tft.fillRoundRect(6,275,40,40,40,ILI9341_MAGENTA);
  tft.setTextSize(1);
  tft.setCursor(11,290);
  tft.println("paint");
  tft.setTextColor(ILI9341_WHITE);

  tft.fillRoundRect(195,275,40,40,40,ILI9341_BLUE);
  tft.setTextSize(1);
  tft.setCursor(203,290);
  tft.println("game");
  tft.setTextColor(ILI9341_WHITE);

}

void setup(){
   Serial.begin(9600);
   pinMode(Touch_CS,OUTPUT);
   pinMode(TFT_CS,OUTPUT);
   pinMode(SD_CS,OUTPUT);
   digitalWrite(TFT_CS,HIGH);
   digitalWrite(Touch_CS,HIGH);
   digitalWrite(SD_CS,HIGH);
   
   tft.begin();
   ts.begin(); 

   
   // initialize the positions of rounded rectangels
    
    // tea
    mealsBox[0].x = 15;
    mealsBox[0].y = 30;
    mealsBox[0].title = "   tea";
    
    // pop corn
    mealsBox[1].x = 125;
    mealsBox[1].y = 30;
    mealsBox[1].title = "pop corn";
    
    // rice
    mealsBox[2].x = 15;
    mealsBox[2].y = 160;
    mealsBox[2].title = "  rice";
    
    // macaroni
    mealsBox[3].x = 125;
    mealsBox[3].y = 160;
    mealsBox[3].title = "macaroni";

  //mealPage();
}



void loop(){
  // go to meal page
  mealPage();
  //digitalWrite(TFT_CS,HIGH);
  delay(5000);
  
  
  while(1){
    // check if there any touch
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.print(p.y);
    Serial.println();
  }
  }
  
  
}
