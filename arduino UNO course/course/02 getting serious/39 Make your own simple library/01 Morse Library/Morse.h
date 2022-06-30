#ifndef MORSE_H_
#define MORSE_H_

#include<Arduino.h>

#define TOTAL_MORSE_CODE_ITEMS	37

struct Morse_code
{
	char character;
	String code;
};

static Morse_code codes[TOTAL_MORSE_CODE_ITEMS] = {
	{'A',".-"},
	{'B',"-..."},
	{'C',"-.-."},
	{'D',"-..-"},
	{'E',"."},
	{'F',"..-."},
	{'G',"--."},
	{'H',"...."},
	{'I',".."},
	{'J',".---"},
	{'K',"-.-"},
	{'L',".-.."},
	{'M',"--"},
	{'N',"-."},
	{'O',"---"},
	{'P',".--."},
	{'Q',"--.-"},
	{'R',".-."},
	{'S',"..."},
	{'T',"-"},
	{'U',"..-"},
	{'V',"...-"},
	{'W',".--"},
	{'X',"-..-"},
	{'Y',"-.--"},
	{'Z',"--.."},
	{'1',".----"},
	{'2',"..---"},
	{'3',"...--"},
	{'4',"....-"},
	{'5',"....."},
	{'6',"-...."},
	{'7',"--..."},
	{'8',"---.."},
	{'9',"----."},
	{'0',"-----"},
	{' '," "}
};



class Morse
{
private:
	int _dot_length_ms;
	int _dash_length;
	int _port_gap;
	int _letter_space;
	int _words_space;
	int _led_pin;
	void flash_led(char code);
public:
	Morse();
	Morse(int dot_duration);
	Morse(int dot_duration, int LED_pin);
	void transmit(String text_to_transmit);
};

#endif