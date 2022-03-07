#ifndef quickPins_328P_h
#define quickPins_328P_h

#include <avr/io.h>

/*  Below are user service functions to replace:
 *      setMode, digitalRead, digitalWrite
 *
 *
*/

void quickMode(uint8_t pin, uint8_t type);      // Uses standard INPUT, OUTPUT, INPUT_PULLUP
uint8_t quickRead(uint8_t pin);                 // Return T or F depending on pin state
void quickWrite(uint8_t pin, uint8_t state);    // Write state to pin
void quickToggle(uint8_t pin);                  // Toggle the state of a pin

/*  Below are service/helper functions. Users can call these functions as well.
 *
 *
 *
*/

uint8_t checkPort(uint8_t *ard_pin);             // Returns the port a certain pin is within. ( 0[B], 1[C], 2[D] )


#endif // quickPins_328P_h


