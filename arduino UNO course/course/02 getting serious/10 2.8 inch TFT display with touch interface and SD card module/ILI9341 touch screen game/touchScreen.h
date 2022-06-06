#ifndef TOUCH_SCREEN
#define TOUCH_SCREEN

#include "WString.h"  // this inclusion is important to include the string

  // ======================== DEFINITION OF PINS ========================/

  // for thermistor pins
  #define HEATER_THERM_PIN  A0
  #define ELECTRIC_COOKER_PIN A1  
  
  // For the Adafruit shield, these are the default.
  #define TFT_DC 9
  #define TFT_RST 8
  
  // chip select
  #define Touch_CS 7
  #define TFT_CS 10
  #define SD_CS 6
  
  // hardware SPI are connected as
  // MOSI=11, MISO=12, SCK=13

  // ======================== DEFINITION OF PINS ========================/
  
  // used theme in touch screen
  # define BACKGROUND_COLOR ILI9341_DARKCYAN
  #define TEXT_COLOR  ILI9341_WHITE
  

  //------------------------- PROPERTIES OF ELEMENTS -------------------------//
  
  // data used by the title position
  #define TITLE_POS_X_START 60
  #define TITLE_POS_X_END 190
  #define TITLE_UNDERLINE_Y 20
  #define TITLE_FONT_SIZE 2
  #define TITLE_TEXT "Info Status"

  // data needed for game cirlce
  #define GAME_CIRCLE_COLOR ILI9341_MAGENTA
  #define GAME_TEXT "game"
  #define GAME_FONT_SIZE  1
  #define GAME_X_POS_TEXT 13
  #define GAME_Y_POS_TEXT 290
  #define GAME_RADIUS 40
  #define GAME_X_POS_CIRCLE 5
  #define GAME_Y_POS_CIRCLE 275
  
  // data needed for paint circle
  #define PAINT_CIRCLE_COLOR ILI9341_BLUE
  #define PAINT_TEXT "paint"
  #define PAINT_FONT_SIZE  1
  #define PAINT_X_POS_TEXT 200
  #define PAINT_Y_POS_TEXT 290
  #define PAINT_RADIUS 40
  #define PAINT_X_POS_CIRCLE 195
  #define PAINT_Y_POS_CIRCLE 275

  // data need for string status
  #define STATUS_COLOR ILI9341_YELLOW
  #define STATUS_TITLE_SIZE 2
  #define STATUS_STATUS_SIZE  1
  #define STATUS_TITLE_X_POS  0
  #define STATUS_TITLE_Y_POS  50
  #define STATUS_TITLE_TEXT "Status:"

  // data needed for remaining time
  #define RT_TITLE_TEXT "remaining time: "

  // data needed for kettle temperature
  #define KETTLE_TEXT "kettle tempertatre: "

  // data needed for kettle temperature
  #define HEATER_TEXT "heater tempertatre: "

  // data needed by the paint page
  #define PAINT_PAGE_BOX_Y 280
  #define PAINT_PAGE_TEXT "go back"
  #define PAINT_PAGE_TEXT_X 60
  #define PAINT_PAGE_TEXT_Y 290
  #define PAINT_FONT_SIZE 3
  #define PAINT_PAGE_RAD  20
  #define PAINT_BACK_COLOR  ILI9341_PURPLE
  

  // data needee for current status : string to be printed
  
  
  //------------------------- PROPERTIES OF ELEMENTS -------------------------//

  #define STATE_PAGE  0
  #define PAINT_PAGE  1
  #define GAME_PAGE   2

   
  // this struct is current status : needed to update the status on the screen
  struct currentStatus{
    String status;
    int timeInSeconds;
  };

  struct gameRectangle{
    int xPos;
    int yPos;
    int width;
    int height;
    int radius;
    int color; 
    bool isRemoved; 
  };

  struct ballInGame{
    int xPos;
    int yPos;
    int color;
    int radius;
    int angleOfDirection;
  };

  // This is calibration data for the raw touch data to the screen coordinates
  #define TS_MINX 150
  #define TS_MINY 130
  #define TS_MAXX 3800
  #define TS_MAXY 4000
  
  // function to be used when first initialization
  void touchScreenInit();
  void initStatusInfo(currentStatus state);
  void showPaintPage();
  double getTempReading(int pinNumber);
  int checkUserClick();
  void touchScreenServiceRoutine();
  void updateInfo();
  void showGamePage();
  void userGameEvent();
  void updateGamePage();
  void resetGamePos();
#endif
