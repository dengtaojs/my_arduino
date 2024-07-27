#if !defined(GameButton_H)
#define GameButton_H

#include <Arduino.h>

class GameButton
{
public:
    enum Direction : uint8_t
    {
        Idle, 
        Left, 
        Right, 
        Up, 
        Down, 
        ZPressed
    };
    GameButton(uint8_t xPin, uint8_t yPin, uint8_t zPin);
    void init(); 
    bool Pressed(Direction direction); 
    void Update();

private:
    Direction GetState(); 
    uint8_t _xPin; 
    uint8_t _yPin; 
    uint8_t _zPin; 
    Direction _lastDirection; 
};



#endif // GameButton_H
