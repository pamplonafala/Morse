
#ifndef Morse_h
#define Morse_h
#include <Arduino.h>

class Morse {
	public:
		Morse(int pin, int u, int frequency);
		void emit(String text);
		void unit();
	
	private:
		int _pin;
		int _u;
		int _f;
		void dot();
		void dash();
		void next();
		void space();
		void emitMorse(char letter);
};

#endif
