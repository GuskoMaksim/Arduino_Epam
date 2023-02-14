#pragma once
#include <Arduino.h>

class Sensor
{
public:
    int16_t Get_temperature();
    int16_t Get_humidity();
    int16_t Get_pressure();
    void Serial_print_data();
    void Set_update_interal(int16_t update_interal);
    virtual void Upadate() = 0;

protected:
    int16_t temperature_;
    int16_t humidity_;
    int16_t pressure_;
    bool IsReady();

private:
    uint16_t update_interal_;
    uint32_t time_measuring_;
};
