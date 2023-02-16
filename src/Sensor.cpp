#include "Sensor.h"

void Sensor::Serial_print_data()
{
    Serial.println(Get_temperature());
    Serial.println(Get_pressure());
    Serial.println(Get_humidity());
};

const int16_t Sensor::Get_temperature()
{
    return temperature_;
};

const int16_t Sensor::Get_humidity()
{
    return humidity_;
};

const int16_t Sensor::Get_pressure()
{
    return pressure_;
};
