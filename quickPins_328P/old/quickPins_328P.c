#include "quickPins_328P.h"



#include <avr/io.h>

void quickMode(uint8_t pin, uint8_t type){      // Uses standard INPUT, OUTPUT, INPUT_PULLUP





}

uint8_t quickRead(uint8_t pin){                    // Return T or F depending on pin state

}

void quickWrite(uint8_t pin){                   // Write state to pin
    switch(checkPort(&pin)){                    // 0: B, 1: C, 2: D, 255: Error
        case 0:
            PORTB |= (0x01 << pin);
            break;
        case 1:
            PORTC |= (0x01 << pin);
            break;
        case 2:
            PORTD |= (0x01 << pin);
            break;
        default:
            break;
    }
}

uint8_t checkPort(uint8_t *ard_pin){
    // Returns port value, alters passed var to represent rls value
    if(*ard_pin < 8){
        return 2;
    }
    else if(*ard_pin > 7 && *ard_pin < 14){
        *ard_pin -= 8;
        return 0;
    }
    else if(*ard_pin > 13 && *ard_pin < 20){
        *ard_pin -= 14;
        return 1;
    }
    else{
        return 255;
    }
}
