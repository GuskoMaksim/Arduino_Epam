#pragma once
#include <config.h>

class moduleWeather
{
private:
    GTimer TimerWeather;

public:
    moduleWeather();
    bool isReady();
    int16_t GetTemperature();
    int16_t GetHumidity();
    int16_t GetPressure();
};
