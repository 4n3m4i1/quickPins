#include "fastPort.h"
#include <avr/io.h>

#define AVR328P

#ifdef AVR328P
  #define A0_ 14
  #define A1_ 15
  #define A2_ 16
  #define A3_ 17
  #define A4_ 18
  #define A5_ 19
#endif

uint8_t DigitalWS(uint8_t type, uint8_t pin){
    uint8_t reg_sel;
    uint8_t to_wr;

    switch(pin){
        case 0:               // Arduino Pin 0
          #ifdef AVR328P   // Arduino Uno/Nano 0
          // PD0
            reg_sel = 2;
            to_wr = 0b00000001;
          #endif
        break;

        case 1:               // Arduino Pin 1
          #ifdef AVR328P   // Arduino Uno/Nano 1
          // PD1
            reg_sel = 2;
            to_wr = 0b00000010;
          #endif
        break;

        case 2:               // Arduino Pin 2
          #ifdef AVR328P   // Arduino Uno/Nano 2
          // PD2
            reg_sel = 2;
            to_wr = 0b00000100;
          #endif
        break;

        case 3:               // Arduino Pin 3
          #ifdef AVR328P   // Arduino Uno/Nano 3
          // PD3
            reg_sel = 2;
            to_wr = 0b00001000;
          #endif
        break;

        case 4:               // Arduino Pin 4
          #ifdef AVR328P   // Arduino Uno/Nano 4
          // PD4
            reg_sel = 2;
            to_wr = 0b00010000;
          #endif
        break;

        case 5:               // Arduino Pin 5
          #ifdef AVR328P   // Arduino Uno/Nano 5
          // PD5
            reg_sel = 2;
            to_wr = 0b00100000;
          #endif
        break;

        case 6:               // Arduino Pin 6
          #ifdef AVR328P   // Arduino Uno/Nano 6
          // PD6
            reg_sel = 2;
            to_wr = 0b01000000;
          #endif
        break;

        case 7:               // Arduino Pin 7
          #ifdef AVR328P   // Arduino Uno/Nano 7
          // PD7
            reg_sel = 2;
            to_wr = 0b10000000;
          #endif
        break;

        case 8:               // Arduino Pin 8
          #ifdef AVR328P   // Arduino Uno/Nano 8
          // PB0
            reg_sel = 0;
            to_wr = 0b00000001;
          #endif
        break;

        case 9:               // Arduino Pin 9
          #ifdef AVR328P   // Arduino Uno/Nano 9
          // PB1
            reg_sel = 0;
            to_wr = 0b00000010;
          #endif
        break;

        case 10:              // Arduino Pin 10
          #ifdef AVR328P   // Arduino Uno/Nano 10
          // PB2
            reg_sel = 0;
            to_wr = 0b00000100;
          #endif
        break;

        case 11:              // Arduino Pin 11
          #ifdef AVR328P   // Arduino Uno/Nano 11
          // PB3
            reg_sel = 0;
            to_wr = 0b00001000;
          #endif
        break;

        case 12:              // Arduino Pin 12
          #ifdef AVR328P   // Arduino Uno/Nano 12
          // PB4
            reg_sel = 0;
            to_wr = 0b00010000;
          #endif
        break;

        case 13:              // Arduino Pin 13
          #ifdef AVR328P   // Arduino Uno/Nano 13
          // PB5
            reg_sel = 0;
            to_wr = 0b00100000;
          #endif
        break;

        case 14:
          #ifdef AVR328P    // Arduino Uno/Nano A0
          // PC0
            reg_sel = 1;
            to_wr = 0b00000001;
          #endif
        break;

        case 15:
          #ifdef AVR328P    // Arduino Uno/Nano A1
          // PC1
            reg_sel = 1;
            to_wr = 0b00000010;
          #endif
        break;

        case 16:
          #ifdef AVR328P    // Arduino Uno/Nano A2
          // PC2
            reg_sel = 1;
            to_wr = 0b00000100;
          #endif
        break;

        case 17:
          #ifdef AVR328P    // Arduino Uno/Nano A3
          // PC3
            reg_sel = 1;
            to_wr = 0b00001000;
          #endif
        break;

        case 18:
          #ifdef AVR328P    // Arduino Uno/Nano A4
          // PC4
            reg_sel = 1;
            to_wr = 0b00010000;
          #endif
        break;

        case 19:
          #ifdef AVR328P    // // Arduino Uno/Nano A5
          // PC5
            reg_sel = 1;
            to_wr = 0b00100000;
          #endif
        break;

        default:
        break;
      }

        /* Boards based on 328P have 3 PORTS available: [0]B, [1]C, [2]D
        *  Boards based on 32u4 have 5 PORTS available: [0]B, [1]C, [2]D, [3]E, [4]F
        */
      switch(type){
        case 'W':           // Write to pin     ( PORTn )
            #ifdef AVR328P
                switch(reg_sel){
                    case 0:
                        PORTB |= to_wr;
                    break;
                    case 1:
                        PORTC |= to_wr;
                    break;
                    case 3:
                        PORTD |= to_wr;
                    break;
                    default:
                    break;
                }
            #endif // AVR328P
        break;

        case 'R':           // Read from pin    ( PINn )
            #ifdef AVR328P
                switch(reg_sel){
                    case 0:
                        return PORTB & to_wr;
                    break;
                    case 1:
                        return PORTC & to_wr;
                    break;
                    case 3:
                        return PORTD & to_wr;
                    break;
                    default:
                    break;
                }
            #endif // AVR328P
        break;

        case 'T':           // Toggle Pin Write State ( PORTn )
            #ifdef AVR328P
                switch(reg_sel){
                    case 0:
                        PORTB ^= to_wr;
                    break;
                    case 1:
                        PORTC ^= to_wr;
                    break;
                    case 3:
                        PORTD ^= to_wr;
                    break;
                    default:
                    break;
                }
            #endif // ACR328P
        break;

        case 'C':           // Clear output bit
            #ifdef AVR328P
                switch(reg_sel){
                    case 0:
                        PORTB &= ~to_wr;
                    break;
                    case 1:
                        PORTC &= ~to_wr;
                    break;
                    case 3:
                        PORTD &= ~to_wr;
                    break;
                    default:
                    break;
                }
            #endif // AVR328P
        break;

        case 'Z':           // Zero Pin ( DDRn AND PORTn )
            #ifdef AVR328P
                switch(reg_sel){
                    case 0:
                        DDRB &= ~to_wr;
                        PORTB &= ~to_wr;
                    break;
                    case 1:
                        DDRC &= ~to_wr;
                        PORTC &= ~to_wr;
                    break;
                    case 3:
                        DDRD &= ~to_wr;
                        PORTD &= ~to_wr;
                    break;
                    default:
                    break;
                }
            #endif // AVR328P
        break;

        case 'S':           // Toggle Data Direction ( DDRn )
            #ifdef AVR328P
                switch(reg_sel){
                    case 0:
                        DDRB ^= to_wr;
                    break;
                    case 1:
                        DDRC ^= to_wr;
                    break;
                    case 3:
                        DDRD ^= to_wr;
                    break;
                    default:
                    break;
                }
            #endif // AVR328P
        break;

        default:
        break;
      }

    return 0;
}

void multiDigitalWS(uint8_t type, uint8_t *pins, uint8_t pins_length){
  /*  Types:
   *     W: Write 1 to every pin specified
   *     T: Toggle. XOR pin specified with 1
   *     Z: Write 0 to every pin specified
   *
   *     S: Set OUTPUT mode on selected pins
   */

  /*  Analog Designations follow as INT after digitalPins have been defined
   *    such that A0 follows D13 (on uno) as 14, A1 as 15, etc..
   */

  /*  Boards based on 328P have 3 PORTS available: [0]B, [1]C, [2]D
   *  Boards based on 32u4 have 5 PORTS available: [0]B, [1]C, [2]D, [3]E, [4]F
   */
  #ifdef AVR328P
    uint8_t PORT_DATA_[3] = {0};
  #endif
  #ifdef AVR32U4
    uint8_t PORT_DATA_[5] = {0};
  #endif

  for(uint8_t n = 0; n < pins_length; n++){
      switch(pins[n]){
        case 0:               // Arduino Pin 0
          #ifdef AVR328P   // Arduino Uno/Nano 0
          // PD0
            PORT_DATA_[2] |= 0b00000001;
          #endif
        break;

        case 1:               // Arduino Pin 1
          #ifdef AVR328P   // Arduino Uno/Nano 1
          // PD1
            PORT_DATA_[2] |= 0b00000010;
          #endif
        break;

        case 2:               // Arduino Pin 2
          #ifdef AVR328P   // Arduino Uno/Nano 2
          // PD2
            PORT_DATA_[2] |= 0b00000100;
          #endif
        break;

        case 3:               // Arduino Pin 3
          #ifdef AVR328P   // Arduino Uno/Nano 3
          // PD3
            PORT_DATA_[2] |= 0b00001000;
          #endif
        break;

        case 4:               // Arduino Pin 4
          #ifdef AVR328P   // Arduino Uno/Nano 4
          // PD4
            PORT_DATA_[2] |= 0b00010000;
          #endif
        break;

        case 5:               // Arduino Pin 5
          #ifdef AVR328P   // Arduino Uno/Nano 5
          // PD5
            PORT_DATA_[2] |= 0b00100000;
          #endif
        break;

        case 6:               // Arduino Pin 6
          #ifdef AVR328P   // Arduino Uno/Nano 6
          // PD6
            PORT_DATA_[2] |= 0b01000000;
          #endif
        break;

        case 7:               // Arduino Pin 7
          #ifdef AVR328P   // Arduino Uno/Nano 7
          // PD7
            PORT_DATA_[2] |= 0b10000000;
          #endif
        break;

        case 8:               // Arduino Pin 8
          #ifdef AVR328P   // Arduino Uno/Nano 8
          // PB0
            PORT_DATA_[0] |= 0b00000001;
          #endif
        break;

        case 9:               // Arduino Pin 9
          #ifdef AVR328P   // Arduino Uno/Nano 9
          // PB1
            PORT_DATA_[0] |= 0b00000010;
          #endif
        break;

        case 10:              // Arduino Pin 10
          #ifdef AVR328P   // Arduino Uno/Nano 10
          // PB2
            PORT_DATA_[0] |= 0b00000100;
          #endif
        break;

        case 11:              // Arduino Pin 11
          #ifdef AVR328P   // Arduino Uno/Nano 11
          // PB3
            PORT_DATA_[0] |= 0b00001000;
          #endif
        break;

        case 12:              // Arduino Pin 12
          #ifdef AVR328P   // Arduino Uno/Nano 12
          // PB4
            PORT_DATA_[0] |= 0b00010000;
          #endif
        break;

        case 13:              // Arduino Pin 13
          #ifdef AVR328P   // Arduino Uno/Nano 13
          // PB5
            PORT_DATA_[0] |= 0b00100000;
          #endif
        break;

        case 14:
          #ifdef AVR328P    // Arduino Uno/Nano A0
          // PC0
            PORT_DATA_[1] |= 0b00000001;
          #endif
        break;

        case 15:
          #ifdef AVR328P    // Arduino Uno/Nano A1
          // PC1
            PORT_DATA_[1] |= 0b00000010;
          #endif
        break;

        case 16:
          #ifdef AVR328P    // Arduino Uno/Nano A2
          // PC2
            PORT_DATA_[1] |= 0b00000100;
          #endif
        break;

        case 17:
          #ifdef AVR328P    // Arduino Uno/Nano A3
          // PC3
            PORT_DATA_[1] |= 0b00001000;
          #endif
        break;

        case 18:
          #ifdef AVR328P    // Arduino Uno/Nano A4
          // PC4
            PORT_DATA_[1] |= 0b00010000;
          #endif
        break;

        case 19:
          #ifdef AVR328P    // // Arduino Uno/Nano A5
          // PC5
            PORT_DATA_[1] |= 0b00100000;
          #endif
        break;

        default:
        break;
      }
  }

  switch(type){                         // Mode Selection. Here we write to control registers.

    /* Port State Register Actions */

    case 'W':             // Force Write selected pins
      #ifdef AVR328P
        PORTB |= PORT_DATA_[0];
        PORTC |= PORT_DATA_[1];
        PORTD |= PORT_DATA_[2];
      #endif
    break;

    case 'T':             // Toggle Selected Pins
      #ifdef AVR328P
        PORTB ^= PORT_DATA_[0];
        PORTC ^= PORT_DATA_[1];
        PORTD ^= PORT_DATA_[2];
      #endif
    break;

    case 'Z':             // Zero selected pins
      #ifdef AVR328P
        PORTB &= ~PORT_DATA_[0];
        PORTC &= ~PORT_DATA_[1];
        PORTD &= ~PORT_DATA_[2];
      #endif
    break;

    /* Data Direction Register Actions */

    case 'S':             // Force Write INPUT/OUTPUT modes
      #ifdef AVR328P
        DDRB |= PORT_DATA_[0];
        DDRC |= PORT_DATA_[1];
        DDRD |= PORT_DATA_[2];
      #endif
    break;

    default:
    break;
  }

}     // End funct
