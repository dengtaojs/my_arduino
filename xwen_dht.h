#ifndef XWEN_DHT_H
#define XWEN_DHT_H

#include <Arduino.h>

class xwen_dht
{
public:
    enum dht_type : uint8_t
    {
        DHT11, 
        DHT22
    };

    typedef struct
    {
        float temperature;
        float huminity;
    }dht_result; 


    xwen_dht(uint8_t data_pin, dht_type type);
    dht_result read(); 

private:
    void send_request(); 
    dht_result decode(); 
    bool check();

    dht_type _type; 
    uint8_t _data_pin; 
    uint8_t _data[5]; 
};


#endif 