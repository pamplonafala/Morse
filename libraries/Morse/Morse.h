
#ifndef Morse_h
#define Morse_h
#include <Arduino.h>

class Morse {
	public:
		Morse(int pin, int u);
		void emit(String text);
	
	private:
		int _pin;
		int _u;
		void dot();
		void dash();
		void next();
		void space();
		void emitMorse(char letter);
};

#endif
