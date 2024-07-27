#ifndef DHT_H
#define DHT_H

#include <Arduino.h>

class DHT
{
public:
    enum Type : uint8_t
    {
        DHT11, 
        DHT22
    };

    typedef struct
    {
        float temperature;
        float huminity;
    }Result; 


    DHT(uint8_t data_pin, Type type);
    Result read(); 

private:
    void sendRequest(); 
    Result decode(); 
    bool check();

    Type _type; 
    uint8_t _data_pin; 
    uint8_t _data[5]; 
};


#endif 