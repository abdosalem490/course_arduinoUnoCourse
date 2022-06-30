#include <Morse.h>
#include <Arduino.h>


// constructors
Morse::Morse()
{
	_dot_length_ms 	= 50; 					// duration of a dot
	_dash_length 	= 3 * _dot_length_ms; 	// one dash is three dots
	_port_gap 		= 1 * _dot_length_ms; 	// Space between ports of a letter
	_letter_space 	= 3 * _dot_length_ms; 	// Space between letters 
	_words_space 	= 7 * _dot_length_ms; 	// Space between words
	_led_pin		= 13;
	pinMode(_led_pin,OUTPUT);
}

Morse::Morse(int dot_duration)
{
	_dot_length_ms 	= dot_duration; 		// duration of a dot
	_dash_length 	= 3 * _dot_length_ms; 	// one dash is three dots
	_port_gap 		= 1 * _dot_length_ms; 	// Space between ports of a letter
	_letter_space 	= 3 * _dot_length_ms; 	// Space between letters 
	_words_space 	= 7 * _dot_length_ms; 	// Space between words
	_led_pin		= 13;
	pinMode(_led_pin,OUTPUT);
}

Morse::Morse(int dot_duration, int LED_pin)
{
	_dot_length_ms 	= dot_duration; 		// duration of a dot
	_dash_length 	= 3 * _dot_length_ms; 	// one dash is three dots
	_port_gap 		= 1 * _dot_length_ms; 	// Space between ports of a letter
	_letter_space 	= 3 * _dot_length_ms; 	// Space between letters 
	_words_space 	= 7 * _dot_length_ms; 	// Space between words
	_led_pin		= LED_pin;
	pinMode(_led_pin,OUTPUT);
}

void Morse::transmit(String text_to_transmit)
{
	// for each letter, find its code and transmit it
	for(unsigned int letter = 0; letter < text_to_transmit.length(); letter++)
	{
		int code_index = 0;
		for(int i = 0; i < TOTAL_MORSE_CODE_ITEMS; i++)
		{
			if(codes[i].character == text_to_transmit[letter])
			{
				code_index = i;
				break;
			}
		}
		
		// make flashes for letter at index code_index
		for(unsigned int i = 0; i < codes[code_index].code.length(); i++)
		{
			flash_led(codes[code_index].code[i]);
		}
		
		flash_led(' ');		// Space in between words is three units
		
	}
}

void Morse::flash_led(char code)
{
	digitalWrite(_led_pin,HIGH);
	if(code == '.')
		delay(_dot_length_ms);
	else if(code == ' ')
		delay(_words_space);
	else
		delay(_dash_length);
	
	digitalWrite(_led_pin,LOW);
	delay(_letter_space);
}