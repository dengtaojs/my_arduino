#include "DHT.h"

DHT::DHT(uint8_t data_pin, dht_type type)
    : _data_pin{data_pin}, _type{type}
{
}

DHT::Result DHT::read()
{
    sendRequest(); 
    return decode(); 
}

void DHT::sendRequest()
{
    noInterrupts();
    pinMode(_data_pin, OUTPUT); 
    
    //1. MCU 拉低
    digitalWrite(_data_pin, LOW); 
    switch (_type)
    {
    case DHT11:
        delay(20);
        break;
    case DHT22:
        delayMicroseconds(1100);
        break;
    }

    //2. MCU 拉高
    pinMode(_data_pin, INPUT_PULLUP); 
    delayMicroseconds(22); 

    //3. 接收数据
    uint32_t buffer[41]; 
    for(int i =0; i < 41; ++i){
        buffer[i] = pulseIn(_data_pin, HIGH, 300); 
    }

    interrupts(); 

    //4.转换成字节格式
    for(int i = 0; i < 5; ++i){
        _data[i] = 0; 
        for(int j = 0; j < 8; ++j){
            if(buffer[8*i + j + 1] > 50){
                bitSet(_data[i], -j + 7);
            }
        }
    }
}

DHT::Result DHT::decode()
{
    if(!check())
        return Result{NAN, NAN}; 

    Result result;
    int16_t huminity, temperature; 

    switch (_type)
    {
    case DHT11:
        result.huminity = _data[0] + 0.1f * (_data[1] & 0xf0);
        result.temperature = _data[2] + 0.1f * (_data[3] & 0xf0);
        break;
    
    case DHT22:
        huminity = ((_data[0] & 0x7f) << 8) | _data[1]; 
        temperature = ((_data[2] & 0x7f) << 8) | _data[3];
        result.huminity = 0.1f * huminity; 
        result.temperature = 0.1f * temperature; 
        break;
    }
    return result; 
}

bool DHT::check()
{
    uint16_t sum = _data[0] + _data[1] + _data[2] + _data[3]; 
    return (sum & 0x00ff) == _data[4]; 
}
