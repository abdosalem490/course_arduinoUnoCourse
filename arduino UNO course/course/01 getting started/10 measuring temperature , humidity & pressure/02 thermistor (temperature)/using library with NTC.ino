/**** very inportant note ****/
// the connection here is different from the sketch
// the library assumes that NTC is connected to 5V pin not the ground
// so reverese the connection in the schematic

#include "thermistor.h"

//the pin that is we will obtain readings of NTC from
#define THERMISTOR_PIN  A0

// Thermistor object
THERMISTOR thermistor (THERMISTOR_PIN,  // Analog pin
                        9000,           // Nominal resistance at 25 *C (resistance of thermistor)
                        3950,           // thermistor's beta coefficient
                        9950);          // Value of the series resistor

// Global temperature reading
uint16_t temp;                    
                        
void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  temp = thermistor.read(); //Read temperature

  Serial.print("Temp in 1/10 *C : ");
  Serial.println(temp);

  delay(5000);
  
}
