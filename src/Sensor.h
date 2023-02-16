#pragma once
#include <Arduino.h>

class Sensor
{
public:
    const int16_t Get_temperature();
    const int16_t Get_humidity();
    const int16_t Get_pressure();
    void Serial_print_data();
    virtual void Update() = 0;

protected:
    int16_t temperature_;
    int16_t humidity_;
    int16_t pressure_;

private:
};
