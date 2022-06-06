  // important libraries to be included
  #include "touchScreen.h"
  #include "SPI.h"
  #include "Adafruit_GFX.h"
  #include "Adafruit_ILI9341.h"
  #include <XPT2046_Touchscreen.h>
  #include "thermistor.h"
  
  
  // Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
  Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_RST);
  XPT2046_Touchscreen ts(Touch_CS, 255);
    
  int currentPage;
  int heaterTempY;
  int kettleTempY;
  int timePosY;
  currentStatus stat;
  int counter = 0;
  int gameupdateCounter = 0;
  
  ballInGame ballGame;
  gameRectangle rectAngles[9];
  gameRectangle shootRect;
  

void touchScreenInit()
{
   pinMode(Touch_CS,OUTPUT);
   pinMode(TFT_CS,OUTPUT);
   pinMode(SD_CS,OUTPUT);
   // make sure that all of SPI devices doesnot work at same time
   digitalWrite(TFT_CS,HIGH);
   digitalWrite(Touch_CS,HIGH);
   digitalWrite(SD_CS,HIGH);

   currentPage = 0;
   
   tft.begin();
   ts.begin();

   
}

void initStatusInfo(currentStatus state)
{
  stat = state;
  
  // chaning background
  tft.fillScreen(ILI9341_DARKCYAN);
  
  // writing title with underline
  tft.setTextSize(TITLE_FONT_SIZE);
  tft.setCursor(TITLE_POS_X_START,0);
  tft.println(TITLE_TEXT);
  tft.setTextColor(TEXT_COLOR);
  tft.drawLine(TITLE_POS_X_START,TITLE_UNDERLINE_Y,TITLE_POS_X_END,TITLE_UNDERLINE_Y,TEXT_COLOR);
  
  // make the 2 circles : one for paint program and one for game
 
  // draw circle for paint and game
  tft.setTextColor(TEXT_COLOR);
  tft.setTextSize(GAME_FONT_SIZE);
  
  // game circle
  tft.fillRoundRect(GAME_X_POS_CIRCLE,GAME_Y_POS_CIRCLE,GAME_RADIUS,GAME_RADIUS,GAME_RADIUS,GAME_CIRCLE_COLOR);
  tft.setCursor(GAME_X_POS_TEXT,GAME_Y_POS_TEXT);
  tft.println(GAME_TEXT);
  // paint circle
  tft.fillRoundRect(PAINT_X_POS_CIRCLE,PAINT_Y_POS_CIRCLE,PAINT_RADIUS,PAINT_RADIUS,PAINT_RADIUS,PAINT_CIRCLE_COLOR);
  tft.setCursor(PAINT_X_POS_TEXT,PAINT_Y_POS_TEXT);
  tft.println(PAINT_TEXT);

  // print the STATUS
  tft.setCursor(STATUS_TITLE_X_POS,STATUS_TITLE_Y_POS);
  
  // print the status string
  tft.setTextColor(STATUS_COLOR);
  tft.setTextSize(STATUS_TITLE_SIZE);
  tft.print(STATUS_TITLE_TEXT);
  tft.setTextColor(TEXT_COLOR);
  tft.println(state.status+"\n");
  
  // print the remaining time
  tft.setTextColor(STATUS_COLOR);
  tft.println(RT_TITLE_TEXT);
  tft.setTextColor(TEXT_COLOR);
  int minutes = state.timeInSeconds/60;
  int seconds = state.timeInSeconds%60;
  timePosY = tft.getCursorY();
  if(minutes < 10);
    tft.print("0");
  tft.print(minutes);
  tft.print(":");
  if(seconds < 10)
    tft.print("0");
  tft.println(seconds);
  tft.println();
  
  // print the kettle temperature
  tft.setTextColor(STATUS_COLOR);
  tft.println(KETTLE_TEXT);
  tft.setTextColor(TEXT_COLOR);
  kettleTempY = tft.getCursorY();
  tft.print(getTempReading(HEATER_THERM_PIN));
  tft.println();
  tft.println();

  // print the heater temperature
  tft.setTextColor(STATUS_COLOR);
  tft.println(HEATER_TEXT);
  tft.setTextColor(TEXT_COLOR);
  heaterTempY = tft.getCursorY();
  tft.print(getTempReading(ELECTRIC_COOKER_PIN));
  tft.println();
  tft.println();
  
  // from documentation : i understanded that yield() makes a task to execute in background -> looks like a schedular , made for ESP32 but also implemented for arduino
  yield();
}

double getTempReading(int pinNumber)
{
  THERMISTOR thermistor (pinNumber,  // Analog pin
                        100000,           // Nominal resistance at 25 *C (resistance of thermistor)
                        3950,           // thermistor's beta coefficient
                        100000);
  return thermistor.read() / 10.0;
}
int checkUserClick()
{
  return 0;
}

void updateGamePage()
{
   tft.setRotation(0);
  // move the ball one position according to angle of movement  
  tft.fillCircle(ballGame.xPos,ballGame.yPos,ballGame.radius,BACKGROUND_COLOR);
  int angle = ballGame.angleOfDirection;
  ballGame.xPos += cos((angle*0.017f)) * 5;
  ballGame.yPos += sin((angle*0.017f)) * 5;
  tft.fillCircle(ballGame.xPos,ballGame.yPos,ballGame.radius,ballGame.color);
  yield();

  // check if we hit normal game bar then make it disapper
  for(int i = 0; i < 9; i++)
  {
    if(rectAngles[i].isRemoved == false && ballGame.xPos > rectAngles[i].xPos && ballGame.xPos < rectAngles[i].xPos + rectAngles[i].width && ballGame.yPos > rectAngles[i].yPos && ballGame.yPos < rectAngles[i].yPos + rectAngles[i].height)
    {
        tft.fillRoundRect(rectAngles[i].xPos,rectAngles[i].yPos,rectAngles[i].width,rectAngles[i].height,rectAngles[i].radius,BACKGROUND_COLOR);
        ballGame.angleOfDirection *=-1;
        rectAngles[i].isRemoved = true;
    }
  }
  
  // check if it's a wall then make it rebounce
  if(ballGame.xPos > tft.width() || ballGame.yPos > tft.height() || ballGame.xPos < 0 || ballGame.yPos < 0)
    ballGame.angleOfDirection +=random(90,180);

  // check if ball hit the shoot bar
  if(ballGame.xPos > shootRect.xPos && ballGame.xPos < shootRect.xPos + shootRect.width && ballGame.yPos > shootRect.yPos && ballGame.yPos < shootRect.yPos + shootRect.height)
  {
    tft.fillRoundRect(shootRect.xPos,shootRect.yPos,shootRect.width,shootRect.height,shootRect.radius,shootRect.color);
     ballGame.angleOfDirection +=random(90,180);
  }
  else if(ballGame.yPos > shootRect.yPos + 10)
  {
    currentPage = STATE_PAGE;
    tft.setRotation(0);
    initStatusInfo(stat);
  }
  else
  {
    // this rotation is used by the touch
    tft.setRotation(3);
  }
}
void touchScreenServiceRoutine()
{
    gameupdateCounter++;
    // if we are in a game page then move the ball till it either hit the walls or one of the rectangles
    if(currentPage == GAME_PAGE && gameupdateCounter % 10 == 0)
    {
        updateGamePage();
    }
    
    // check for user click
    if (ts.touched()) {
        
      TS_Point p = ts.getPoint();
      
      // Scale from ~0->4000 to tft.width using the calibration #'s
      p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
      p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());

      // what is the page we are on
      if(currentPage == STATE_PAGE)
      {
        if(p.y > 255 && p.y < 255+PAINT_RADIUS && p.x > 0 && p.x < PAINT_RADIUS)
        {
          // go to paint page
          currentPage = PAINT_PAGE;
          showPaintPage();
        }
        else if (p.y > 0 && p.y < 20+PAINT_RADIUS && p.x > 0 && p.x < PAINT_RADIUS)
        {
          // go to game page 
          currentPage = GAME_PAGE;
          showGamePage();
        }

      }
      else if(currentPage == PAINT_PAGE)
      {
       if(p.x > 0 && p.x < 40 && p.y > 50 && p.y < 200)
        {
          currentPage = STATE_PAGE;
          tft.setRotation(0);
          initStatusInfo(stat);
        }
        else
        {
          tft.fillCircle(p.x,p.y,3,TEXT_COLOR);
        }
      }
      else if(currentPage == GAME_PAGE)
      {
        if(p.x > 0 && p.x < 40 && p.y > 50 && p.y < 200)
        {
          currentPage = STATE_PAGE;
          tft.setRotation(0);
          initStatusInfo(stat);
        }
        else if(p.x < 100);
        {
          tft.setRotation(0);
          Serial.begin(115200);
          Serial.println("x = ");
          Serial.println(p.y);
          
          //tft.fillRect(0,260,tft.width(),15,BACKGROUND_COLOR);
          // move the shoot bar
          tft.fillRoundRect(shootRect.xPos,shootRect.yPos,shootRect.width,shootRect.height,shootRect.radius,BACKGROUND_COLOR);
          shootRect.xPos = p.y;
          //tft.fillRoundRect(p.y,p.x,shootRect.width,shootRect.height,shootRect.radius,shootRect.color);
          tft.fillRoundRect(shootRect.xPos,shootRect.yPos,shootRect.width,shootRect.height,shootRect.radius,shootRect.color);
        }
      }
    }
}
void showPaintPage()
{
   // chaning background
  tft.fillScreen(ILI9341_DARKCYAN);

  // TODO : add the buttons to return back
  tft.fillRoundRect(0,PAINT_PAGE_BOX_Y,tft.width(),tft.height()-PAINT_PAGE_BOX_Y,PAINT_PAGE_RAD,PAINT_BACK_COLOR);
  tft.setCursor(PAINT_PAGE_TEXT_X,PAINT_PAGE_TEXT_Y);
  tft.setTextColor(TEXT_COLOR);
  tft.setTextSize(PAINT_FONT_SIZE);
  tft.println(PAINT_PAGE_TEXT);
  // used to check for click event later to be easier to use with the touch module
  tft.setRotation(3);
}

void showGamePage()
{
  resetGamePos();
  
   // chaning background
  tft.fillScreen(ILI9341_DARKCYAN);

  // TODO : add the buttons to return back
  tft.fillRoundRect(0,PAINT_PAGE_BOX_Y,tft.width(),tft.height()-PAINT_PAGE_BOX_Y,PAINT_PAGE_RAD,PAINT_BACK_COLOR);
  tft.setCursor(PAINT_PAGE_TEXT_X,PAINT_PAGE_TEXT_Y);
  tft.setTextColor(TEXT_COLOR);
  tft.setTextSize(PAINT_FONT_SIZE);
  tft.println(PAINT_PAGE_TEXT);
  
  // print out all the rectangles 
  for(int i = 0; i < 9; i++)
    tft.fillRoundRect(rectAngles[i].xPos,rectAngles[i].yPos,rectAngles[i].width,rectAngles[i].height,rectAngles[i].radius,rectAngles[i].color);
    
  tft.fillRoundRect(shootRect.xPos,shootRect.yPos,shootRect.width,shootRect.height,shootRect.radius,shootRect.color);
  tft.fillCircle(ballGame.xPos,ballGame.yPos,ballGame.radius,ballGame.color);
  tft.setRotation(3);
}
void updateInfo()
{
  counter++;
  if(counter % 100 == 0 && stat.timeInSeconds != 0)
  {
    stat.timeInSeconds--;
  }
  if(counter % 100 == 0 && currentPage == STATE_PAGE)
  {
    tft.setCursor(0,heaterTempY);
    tft.fillRect(0,heaterTempY,150,20,ILI9341_DARKCYAN);
    tft.setTextColor(TEXT_COLOR);
    tft.setCursor(0,heaterTempY);
    tft.print(getTempReading(HEATER_THERM_PIN));

    tft.setCursor(0,kettleTempY);
    tft.fillRect(0,kettleTempY,150,20,ILI9341_DARKCYAN);
    tft.setTextColor(TEXT_COLOR);
    tft.setCursor(0,kettleTempY);
    tft.print(getTempReading(ELECTRIC_COOKER_PIN));
    

    tft.setCursor(0,timePosY);
    tft.fillRect(0,timePosY,150,20,ILI9341_DARKCYAN);
    tft.setTextColor(TEXT_COLOR);
    tft.setCursor(0,timePosY);
    int minutes = stat.timeInSeconds/60;
    int seconds = stat.timeInSeconds%60;
    if(minutes < 10)
      tft.print("0");
    tft.print(minutes);
    tft.print(":");
    if(seconds < 10)
      tft.print("0");
    tft.println(seconds);
  }
  else
  {
    // check for user click
    touchScreenServiceRoutine();
  }
}
void resetGamePos()
{
  // give data to the bal game
   ballGame.xPos = tft.width()/2;
   ballGame.yPos = tft.height()/2;
   ballGame.color = ILI9341_LIGHTGREY;
   ballGame.radius = 10;

   // data for rectangles to hit

   // first row
   rectAngles[0].xPos = 5;
   rectAngles[0].yPos = 5;
   rectAngles[0].width = 75;
   rectAngles[0].height = 15;
   rectAngles[0].radius = 5;
   rectAngles[0].color = ILI9341_BLUE;
   rectAngles[0].isRemoved = false;
    
   rectAngles[1].xPos = 82;
   rectAngles[1].yPos = 5;
   rectAngles[1].width = 75;
   rectAngles[1].height = 15;
   rectAngles[1].radius = 5;
   rectAngles[1].color = ILI9341_PURPLE;
   rectAngles[1].isRemoved = false;
   
   rectAngles[2].xPos = 160;
   rectAngles[2].yPos = 5;
   rectAngles[2].width = 75;
   rectAngles[2].height = 15;
   rectAngles[2].radius = 5;
   rectAngles[2].color = ILI9341_DARKGREEN;
   rectAngles[2].isRemoved = false;
   
   // second row
   rectAngles[3].xPos = 5;
   rectAngles[3].yPos = 25;
   rectAngles[3].width = 75;
   rectAngles[3].height = 15;
   rectAngles[3].radius = 5;
   rectAngles[3].color = ILI9341_ORANGE;
   rectAngles[3].isRemoved = false;

   rectAngles[4].xPos = 82;
   rectAngles[4].yPos = 25;
   rectAngles[4].width = 75;
   rectAngles[4].height = 15;
   rectAngles[4].radius = 5;
   rectAngles[4].color = ILI9341_MAROON;
   rectAngles[4].isRemoved = false;
   
   rectAngles[5].xPos = 160;
   rectAngles[5].yPos = 25;
   rectAngles[5].width = 75;
   rectAngles[5].height = 15;
   rectAngles[5].radius = 5;
   rectAngles[5].color = ILI9341_GREEN;
   rectAngles[5].isRemoved = false;
   
   // third row
   rectAngles[6].xPos = 5;
   rectAngles[6].yPos = 45;
   rectAngles[6].width = 75;
   rectAngles[6].height = 15;
   rectAngles[6].radius = 5;
   rectAngles[6].color = ILI9341_NAVY;
   rectAngles[6].isRemoved = false;

   rectAngles[7].xPos = 82;
   rectAngles[7].yPos = 45;
   rectAngles[7].width = 75;
   rectAngles[7].height = 15;
   rectAngles[7].radius = 5;
   rectAngles[7].color = ILI9341_OLIVE;
   rectAngles[7].isRemoved = false;
   
   rectAngles[8].xPos = 160;
   rectAngles[8].yPos = 45;
   rectAngles[8].width = 75;
   rectAngles[8].height = 15;
   rectAngles[8].radius = 5;
   rectAngles[8].color = ILI9341_YELLOW;
   rectAngles[8].isRemoved = false;
   
   // rectangle 
   shootRect.xPos = (tft.width()/2) - 40 ;
   shootRect.yPos = 260;
   shootRect.width = 40;
   shootRect.height = 15;
   shootRect.radius = 5;
   shootRect.color = ILI9341_GREENYELLOW;

   // ball game
   ballGame.xPos = (tft.width()/2) - 10;
   ballGame.yPos = 240;
   ballGame.color = ILI9341_WHITE;
   ballGame.radius = 5;
   ballGame.angleOfDirection = -45;
}
