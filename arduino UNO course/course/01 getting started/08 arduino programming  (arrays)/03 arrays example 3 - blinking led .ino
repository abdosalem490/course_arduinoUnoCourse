//pin 13 is connected to built in led
//this is a program to blink led with specific time changing
//use 1D array not 2D for readability and clean code

const int ledPin              = 13; //according to arduino documentations , it's better to
const int totalStates         = 10; //use constants instead of #define
int ledState[totalStates]     = {1, 0, 1, 0, 1, 0, 0, 1, 0};  //0 -> led off , 1 -> led on
int ledDurations[totalStates] = {200, 400, 500, 100, 200, 50, 50, 500, 500}; // these are the time of blinking in ms

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < totalStates; i++)
  {
    digitalWrite(ledPin, ledState[i]);
    delay(ledDurations[i]);
  }
}
