/*  1110 - The Ethernet Shield (W5100) simple reporting web server
 * 
 * This sketch shows you how to create a simple web server
 * using an Arduino Uno and an Ethernet Shield.
 * 
 * The server prints out values acquired from a DHT22 and light sensor.
 * 
 * You can modify this sketch to add other sensors and report their values.
 * 
 * 
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - a compatible Ethernet shield (W5100 chipset)
 *  - Access to an Ethernet switch and CAT5 cable
 *  - A DHT22 sensor
 *  - A 10KOhm pull-up resistor for the DHT22
 *  - A photoresistor
 *  - A 10KOhm pull-down resistor for the photoresistor
 *  - A breadboard
 *  - Jumper wires
 *  
 *  Libraries
 *  ---------
 *  - SPI (comes with the Arduino IDE)
 *  - Ethernet (comes with the Arduino IDE)
 *  - Adafruit_Sensor (use the Library Manager to install it)
 *  - DHT (use the Library Manager to install it)
 *
 * Connections
 * -----------
 *  
 * Attach the Ethernet shield to the Arduino Uno.
 * Using a Cat5 cable, connect the Ethernet shield 
 * to an Ethernet switch that is already a member
 * of your Local Area Network.
 * 
 * Attach the sensors and resistors on the breadboard as shown in the schematic diagram 
 * for this lecture.
 *     
 * Other information
 * -----------------
 * About the Arduino Ethernet shield v2: https://store.arduino.cc/usa/arduino-ethernet-shield-2
 * About the Arduino Ethernet shield v1: https://www.arduino.cc/en/Main/ArduinoEthernetShieldV1
 * The Ethernet library: https://www.arduino.cc/en/Reference/Ethernet
 * Learn about HTTP: https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol 
 *  
 *  Created on July 4 2017 by Peter Dalmaris
 * 
 */
/*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 */

#include <SPI.h>
#include <Ethernet.h>
#include <Adafruit_Sensor.h>    //If you are using the Adafruit DHT library, make sure 
                                // that Adafruit_Sensor.h is required first 
#include "DHT.h"
#define DHTPIN 2    // what pin we're connected to

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,6);  // preferred to be an address that is not used by anyelse device (local)

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  dht.begin();

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin

          int sensorReading = analogRead(0);
          client.print("analog input ");
          client.print(0);
          client.print(" is ");
          client.print(sensorReading);
          client.println("<br />");       


          float h = dht.readHumidity();
          float t = dht.readTemperature();

          // check if returns are valid, if they are NaN (not a number) then something went wrong!
          if (isnan(t) || isnan(h)) {
            Serial.println("Failed to read from DHT");
          } 
          else {
            client.print("Humidity: ");
            client.print(h);
            client.println("<br />");       
            client.print("Temperature: ");
            client.print(t);
            client.print(" *C");
            client.println("<br />");       
          }

          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}
