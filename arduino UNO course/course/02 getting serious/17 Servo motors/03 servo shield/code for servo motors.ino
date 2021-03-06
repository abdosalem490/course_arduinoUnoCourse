#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way , it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make , the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for the max range. you will hace to tweak them as necessary to match the servos you have

//#define SERVOMIN 130 // this is the 'minimum' pulse length count (out of 4096) for the HD-1800A servo
//#define SERVOMAX 530 // this is the 'maximum' pulse length count (out of 4096) for the HD-1800A servo

#define SERVOMIN 0    // 1 // this is the 'minimum' pulse length count (out of 4096) for the SM-S4303R continuous rotation servo
#define SERVOMAX 360  // 380 // this is the 'maximum' pulse length count (out of 4096) for the SM-S4303R continuous rotation servo

// we use map function because the PWM on the shield is 12 bit while on the arduino is 8 bit
int pulselength_0   = map(0,0,180,SERVOMIN,SERVOMAX);
int pulselength_45  = map(45,0,180,SERVOMIN,SERVOMAX);
int pulselength_90  = map(90,0,180,SERVOMIN,SERVOMAX);
int pulselength_135 = map(135,0,180,SERVOMIN,SERVOMAX);
int pulselength_160 = map(160,0,180,SERVOMIN,SERVOMAX);
int pulselength_180 = map(180,0,180,SERVOMIN,SERVOMAX);

void setup()
{
  Serial.begin(9600);
  pwm.begin();
  
  pwm.setPWMFreq(60); // Analog servos run at ~60 HZ updates
    
}

void loop()
{
  // Drive each servo one at a time
  // use pulselength = map(degress,0,180,SERVOMIN,SERVOMAX); to convert degrees to pulse length
  
  for(uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++)
  {
    Serial.println(pulselen);
    // setPWM(cahnnel,on,off); => channel : to select which servo motor , you will find them numbered on the shield
    //                            on : the tick (between 0..4095 when the signal should transition from low to high
    //                            off : the tick (between 0..4095 when the signal should transition from high to low
    pwm.setPWM(0,0,pulselen);
    delay(100);
  }
  delay(500);
  for(uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--)
  {
    pwm.setPWM(0,0,pulselen);
    delay(100);
  }
  delay(500);

  // Uncomment the following lines to make the servo move to specific posotions
  // CRS : continous rotation servo 
//  pwm.setPWM(0,0,pulselength_0);    // Turn servo to 0 degrees (make pulselength 1 for a CRS - this will make it turn CCW at top speed)
//  delay(500);
//  pwm.setPWM(0,0,pulselength_45);   // Turn servo to 45 degrees (if using a CRS , it will turn CCW at medium speed)
//  delay(500);
//  pwm.setPWM(0,0,pulselength_90);   // Turn servo to 90 degrees (if using a CRS , it will stop)
//  delay(500);
//  pwm.setPWM(0,0,pulselength_135);  // Turn servo to 135 degrees (if using a CRS , it will turn CW at medium speed)
//  delay(500);
//  pwm.setPWM(0,0,pulselength_160);  // Turn servo to 160 degrees (is using a CRS , it will turn CW at higher medium speed)
//  delay(500);
//  pwm.setPWM(0,0,pulselength_180);  // Turn servo to 180 degrees (if using a CRS , it will turn CW at top speed)
//  delay(500);
}
