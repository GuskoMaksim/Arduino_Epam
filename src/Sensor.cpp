#include "Sensor.h"

bool Sensor::IsReady()
{
    if (millis() - time_measuring_ > update_interal_)
    {
        time_measuring_ = millis();
        return true;
    }
    return false;
}

void Sensor::Set_update_interal(int16_t update_interal)
{
    update_interal_ = update_interal;
};

void Sensor::Serial_print_data()
{
    if (IsReady())
    {
        Serial.println(Get_temperature());
        Serial.println(Get_pressure());
        Serial.println(Get_humidity());
    }
};

int16_t Sensor::Get_temperature()
{
    return temperature_;
};

int16_t Sensor::Get_humidity()
{
    return humidity_;
};

int16_t Sensor::Get_pressure()
{
    return pressure_;
};
