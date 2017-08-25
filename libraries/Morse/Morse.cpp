

#include "Morse.h"
#include <Arduino.h>

Morse::Morse(int pin, int u) {
	_pin = pin;
	_u = u;
	pinMode(_pin, OUTPUT);
	Serial.begin(9600);
}
void Morse::dot() {
	digitalWrite(_pin, HIGH);
	delay(_u);
	digitalWrite(_pin, LOW);
	delay(_u);
}
void Morse::dash() {
	digitalWrite(_pin, HIGH);
	delay(_u*3);
	digitalWrite(_pin, LOW);
	delay(_u);
}
void Morse::next() {delay(_u*3-_u);}
void Morse::space() {delay(_u*7-_u);}
void Morse::emitMorse(char letter) {
    switch (letter) {
		case 'a': dot();dash(); 				break;
		case 'b': dash();dot();dot();dot(); 	break;
		case 'c': dash();dot();dash();dot(); 	break;
		case 'd': dash();dot();dot(); 			break;
		case 'e': dot(); 						break;
		case 'f': dot();dot();dash();dot(); 	break;
		case 'g': dash();dash();dot(); 			break;
		case 'h': dot();dot();dot();dot(); 		break;
		case 'i': dot();dot(); 			 		break;
		case 'j': dot();dash();dash();dash(); 	break;
		case 'k': dash();dot();dash(); 			break;
		case 'l': dot();dash();dot();dot(); 	break;
		case 'm': dash();dash(); 				break;
		case 'n': dash();dot();					break;
		case 'o': dash();dash();dash();			break;
		case 'p': dot();dash();dash();dot();	break;
		case 'q': dash();dash();dot();dash();	break;
		case 'r': dot();dash();dot();			break;
		case 's': dot();dot();dot();			break;
		case 't': dash();						break;
		case 'u': dot();dot();dash();			break;
		case 'v': dot();dot();dot();dash(); 	break;
		case 'w': dot();dash();dash();			break;
		case 'x': dash();dot();dot();dash();	break;
		case 'y': dash();dot();dash();dash();	break;
		case 'z': dash();dash();dot();dot();	break;
		
		case '1': dot();dash();dash();dash();dash(); 	break;
		case '2': dot();dot();dash();dash();dash();		break;
		case '3': dot();dot();dot();dash();dash();	 	break;
		case '4': dot();dot();dot();dot();dash();	 	break;
		case '5': dot();dot();dot();dot();dot();	 	break;
		case '6': dash();dot();dot();dot();dot();	 	break;
		case '7': dash();dash();dot();dot();dot();	 	break;
		case '8': dash();dash();dash();dot();dot();		break;
		case '9': dash();dash();dash();dash();dot(); 	break;
		case '0': dash();dash();dash();dash();dash();	break;

		case '.': dot();dash();dot();dash();dot();			break;
		case ',': dash();dash();dot();dot();dash();dash(); 	break;
		case '?': dot();dot();dash();dash();dot();dot(); 	break;
		case '!': dash();dot();dash();dot();dash();dash(); 	break;
		case '/': dash();dot();dot();dash();dot(); 			break;
		case ':': dash();dash();dash();dot();dot();dot(); 	break;
		case ';': dash();dot();dash();dot();dash();dot(); 	break;
		case '=': dash();dot();dot();dot();dash(); 			break;
		case '+': dot();dash();dot();dash();dot(); 			break;
		case '-': dash();dot();dot();dot();dot();dash(); 	break;
		case '_': dot();dot();dash();dash();dot();dash(); 	break;
		case '"': dot();dash();dot();dot();dash();dot(); 	break;
		case '@': dot();dash();dash();dot();dash();dot();	break;
		
		case ' ': space();						break;
		default:  dot();dash();dot();dash();	break;
    }
}

void Morse::emit(String text) {
	for (int i = 0; i < text.length(); i++) {
		emitMorse(text.charAt(i));
		next();
	}
}