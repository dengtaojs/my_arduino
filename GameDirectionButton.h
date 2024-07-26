#if !defined(GAMEDIRECTIONBUTTON_H)
#define GAMEDIRECTIONBUTTON_H

#include <Arduino.h>



class GameDirectionButton
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
    GameDirectionButton(uint8_t xPin, uint8_t yPin, uint8_t zPin);
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



#endif // GAMEDIRECTIONBUTTON_H
