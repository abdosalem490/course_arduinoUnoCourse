//pin 13 is connected to built in led
//this is a program to blink led with specific time changing and reading the input from user
//use 1D array not 2D for readability and clean code


//-------------- important Note --------------
//change in the window of the serial monitor the option from NewLine to No Line Ending 
//as as the NewLine option will send 2 chars , the char you entered and the char for the new line

const int ledPin              = 13; //according to arduino documentations , it's better to
const int totalStates         = 10; //use constants instead of #define
int ledState[totalStates];       //0 -> led off , 1 -> led on
int ledDurations[totalStates] = {200, 400, 500, 100, 200, 50, 50, 500, 500}; // these are the time of blinking in ms

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ;//wait for the serial port to connect , Needed for native USB
  }

  //read input from the user which upon determine the pattern
  for (int i = 0; i < totalStates; i++)
  {
    Serial.print("Please type 1 or 0 for pattern step ");
    Serial.print(i);
    Serial.print(" out of ");
    Serial.print(totalStates - 1);
    Serial.print(" (default is 1): ");

    while (Serial.available() == 0)
    {

    }

    char userInput = Serial.read();
    if (userInput == '1')
      ledState[i] = 1;
    else if (userInput == '0')
      ledState[i] = 0;
    else
      ledState[i] = 1;

    Serial.println(ledState[i]);
  }

  Serial.println("Thank you , now let's blink this LED using this pattern: ");
  for (int i = 0; i < totalStates; i++)
  {
    Serial.print("Step ");
    Serial.print(i);
    Serial.print(" state is: ");
    Serial.print(ledState[i]);
    Serial.print(" with duration ");
    Serial.println(ledDurations[i]);
  }
}

void loop() {
  for (int i = 0; i < totalStates; i++)
  {
    digitalWrite(ledPin, ledState[i]);
    delay(ledDurations[i]);
  }
}
