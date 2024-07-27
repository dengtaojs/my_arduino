#ifndef KeyBoard4x4_H
#define KeyBoard4x4_H

#include <Arduino.h>


class KeyBoard4x4
{
private:
    uint8_t _row_pins[4]; 
    uint8_t _col_pins[4]; 
    int _col_status[16]; 

public:
    KeyBoard4x4(uint8_t row_pins[4], uint8_t col_pins[4]);
    void init(); 

    char getKeyChar(char chardata[16], char defaultChar = '\0'); 

private:
    void scan(); 
};

#endif 