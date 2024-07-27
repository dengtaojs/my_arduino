#include "GameButton.h"

GameButton::GameButton(uint8_t xPin, uint8_t yPin, uint8_t zPin)
    :_xPin{xPin}, _yPin{yPin}, _zPin{zPin}
{
    _lastDirection = Direction::Idle;
}

void GameButton::init()
{
    pinMode(_xPin, INPUT); 
    pinMode(_yPin, INPUT); 
    pinMode(_zPin, INPUT_PULLUP); 
    analogReadResolution(10); 
}

bool GameButton::Pressed(Direction direction)
{
    auto currentDirection = GetState(); 
    auto result = _lastDirection == Direction::Idle && currentDirection == direction; 
    return result; 
}

GameButton::Direction GameButton::GetState()
{   int zValue = digitalRead(_zPin); 
    int xValue = analogRead(_xPin); 
    int yValue = analogRead(_yPin); 

    if(zValue == LOW)
        return Direction::ZPressed; 

    if(xValue <= 100)
        return Direction::Left; 
    if(xValue > 900)
        return Direction::Right; 
   
    if(yValue <= 100)
        return Direction::Up; 
    if(yValue > 900)
        return Direction::Down; 
    
    return Direction::Idle; 
}

void GameButton::Update()
{
    _lastDirection = GetState(); 
}