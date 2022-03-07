#include "quickPins_328P.h"



#include <avr/io.h>

void quickMode(uint8_t pin, uint8_t type){
    // Uses standard INPUT, OUTPUT, INPUT_PULLUP
    // Can also accept TOGGLE (3)
    switch(checkPort(&pin)){                     // 0: B, 1: C, 2: D, 255: Error
        case 0:
            if(type == 1){              // OUTPUT
                DDRB |= (0x01 << pin);
            }
            else if(type == 2){         // INPUT_PULLUP
                DDRB &= ~(0x01 << pin);
                PORTB |= (0x01 << pin);
            }
            else if(type == 3){         // TOGGLE
                DDRB ^= (0x01 << pin);
            } else {                    // Reset to input ( 0 )
                DDRB &= ~(0x01 << pin);
            }
            break;
        case 1:
            if(type == 1){              // OUTPUT
                DDRC |= (0x01 << pin);
            }
            else if(type == 2){         // INPUT_PULLUP
                DDRC &= ~(0x01 << pin);
                PORTC |= (0x01 << pin);
            }
            else if(type == 3){         // TOGGLE
                DDRC ^= (0x01 << pin);
            } else {                    // Reset to input ( 0 )
                DDRC &= ~(0x01 << pin);
            }
            break;
        case 2:
            if(type == 1){              // OUTPUT
                DDRD |= (0x01 << pin);
            }
            else if(type == 2){         // INPUT_PULLUP
                DDRD &= ~(0x01 << pin);
                PORTD |= (0x01 << pin);
            }
            else if(type == 3){         // TOGGLE
                DDRD ^= (0x01 << pin);
            } else {                    // Reset to input ( 0 )
                DDRD &= ~(0x01 << pin);
            }
            break;
        default:
            break;
    }
}

uint8_t quickRead(uint8_t pin){                    // Return T or F depending on pin state (non-zero return = true/high, zero return = false/low)
    switch(checkPort(&pin)){                       // 0: B, 1: C, 2: D, 255: Error
        case 0:
            return PINB & (0x01 << pin);
            break;
        case 1:
            return PINC & (0x01 << pin);
            break;
        case 2:
            return PIND & (0x01 << pin);
            break;
        default:
            break;
    }
}

void quickWrite(uint8_t pin, uint8_t state){    // Write state to pin
    switch(checkPort(&pin)){                    // 0: B, 1: C, 2: D, 255: Error
        case 0:
            if(state == 1){
                PORTB |= (0x01 << pin);
            } else {
                PORTB &= ~(0x01 << pin);
            }
            break;
        case 1:
            if(state == 1){
                PORTC |= (0x01 << pin);
            } else {
                PORTC &= ~(0x01 << pin);
            }
            break;
        case 2:
            if(state == 1){
                PORTD |= (0x01 << pin);
            } else {
                PORTD &= ~(0x01 << pin);
            }
            break;
        default:
            break;
    }
}

void quickToggle(uint8_t pin){                   // Toggle state on pin
    switch(checkPort(&pin)){                     // 0: B, 1: C, 2: D, 255: Error
        case 0:
            //PORTB ^= (0x01 << pin);
            PINB |= (0x01 << pin);
            break;
        case 1:
            //PORTC ^= (0x01 << pin);
            PINC |= (0x01 << pin);
            break;
        case 2:
            //PORTD ^= (0x01 << pin);
            PIND |= (0x01 << pin);
            break;
        default:
            break;
    }
}

uint8_t checkPort(uint8_t *ard_pin){
    // Returns port value, alters passed var (*ard_pin) to represent RLS value
    //  this saves a byte in memory and possibly some time.
    switch(*ard_pin){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        return 2;

    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        *ard_pin -= 8;
        return 0;

    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
        *ard_pin -= 14;
        return 1;

    default:
        return 255;
    }

    /*
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
    */
}
