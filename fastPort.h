#ifndef fastPort_h
#define fastPort_h

#include <avr/io.h>

    uint8_t DigitalWS(uint8_t type, uint8_t pin);
    void multiDigitalWS(uint8_t type, uint8_t *pins, uint8_t pins_length);

#endif
