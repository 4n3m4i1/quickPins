#include "quickPins_328P.h"

/*  Demonstration of functional replacements for:
 *      pinMode()       --> quickMode(uint8_t pin, uint8_t state)
 *      digitalRead()   --> quickRead(uint8_t pin)
 *      digitalWrite()  --> quickWrite(uint8_t pin, uint8_t state)
 *      
 *  The quickMode function will respond to default modes such as: OUTPUT (1), INPUT (0), INPUT_PULLUP (2), and TOGGLE (3)    
 *  The quickWrite function will respond to all default states (HIGH, LOW, true, false, 1, 0)
 *  Quick read returns a TRUE (non-zero) result if power is on pin.
 *  
 *  The quickToggle() function is very lightweight and should be used if states can be properly managed.
 */


#define SOME_PIN 10
#define OTHER_PIN 3

void setup() {

  Serial.begin(115200);
  
  quickMode(SOME_PIN, OUTPUT);          // Some output.
  quickMode(OTHER_PIN, INPUT_PULLUP);   // Perhaps use for a button or other input.
}

void loop() {
  Serial.print("Pin state ");
  Serial.print(OTHER_PIN);
  Serial.print(" is ");
  Serial.println(quickRead(OTHER_PIN));
  
  if(quickRead(OTHER_PIN)){             // If OTHER_PIN is LOW ( 0x00 )
    quickWrite(SOME_PIN, HIGH);          // Write pin 10 HIGH
    delay(1500);                          //
    quickWrite(SOME_PIN, LOW);           // Write pin 10 LOW
  }

  delay(1000);

  quickToggle(SOME_PIN);                 // Toggle state of pin 10

  delay(150);

  quickToggle(SOME_PIN);                 // Toggle state of pin 10

  delay(500);

}
