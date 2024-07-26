#include "keyboard4x4.h"

keyboard4x4::keyboard4x4(uint8_t row_pins[4], uint8_t col_pins[4])
{
    for (int i = 0; i < 4; ++i)
    {
        _row_pins[i] = row_pins[i];
        _col_pins[i] = col_pins[i];
    }

    for(int i = 0; i < 16; ++i)
    {
        _col_status[i] = HIGH;
    }
}

void keyboard4x4::init()
{
    for (int i = 0; i < 4; ++i)
    {
        pinMode(_row_pins[i], OUTPUT);
    }

    for (int i = 0; i < 4; ++i)
    {
        pinMode(_col_pins[i], INPUT_PULLUP);
    }
}

char keyboard4x4::getKeyChar(char chardata[16], char defaultChar)
{
    scan(); 
    for(int i = 0; i < 16; ++i)
    {
        if(_col_status[i] == LOW){
            return chardata[i]; 
        }
    }
    return defaultChar; 
}

void keyboard4x4::scan()
{
    for(int r = 0; r < 4; ++r)
    {
        // 设置电压
        for (int i = 0; i < 4; ++i)
            digitalWrite(_row_pins[i], r != i);

        delay(10);
        
        // 读取状态
        for(int c = 0; c < 4; ++c)
            _col_status[4 * r + c] = digitalRead(_col_pins[c]);
        
        delay(10); 
    }
}
