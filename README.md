Quick Pins version for the ATMega328P Arduino Uno (and uno clones)
Untested currently but will likely function well on Arduino Nano (and clones)

/**************************************************************************/

This library simply adds 5 functions, 4 of which replace common Arduino I/O functions.
All functions respect default pin assignments and macros mapped in Arduino.h with mirrored functionality.
	ie. pinMode(5, OUTPUT) == quickMode(5, OUTPUT)

Arduino.h Function			quickPins_328P.h Function Equivalent
------------------			------------------------------------
pinMode(PIN, TYPE)			quickMode(PIN, TYPE)
digitalWrite(PIN, STATE)		quickWrite(PIN, STATE)
digitalRead(PIN)			quickRead(PIN)

					quickPins_328P.h Unique Functions
					------------------------------------
					quickToggle(PIN)


In many (notably not all) cases there is a 10-35% memory saving upon compile time.

Time has yet to be properly tested.

/**************************************************************************/

Function Descriptions

quickMode(PIN, TYPE)
	uint8_t PIN	Arduino.h equivalent pin number (0-13, 14-19 == A0 - A5)
	uint8_t TYPE	INPUT or 0, OUTPUT or 1, INPUT_PULLUP or 2, TOGGLE or 3	

	Sets DDRn and PORTn (in case of INPUT_PULLUP) for selected pin.


quickWrite(PIN, STATE)
	uint8_t PIN	Same as described above.
	uint8_t TYPE	HIGH or 1, LOW or 0

	Writes STATE to selected PIN.


quickRead(PIN)
	uint8_t PIN	Same as described above.
	
	Returns an 8 bit value. Can be treated as BOOL type: 0x00 == false, non-zero == true


quickToggle(PIN)
	uint8_t PIN	Same as described above.

	Simply toggles the state of selected PIN. 	
