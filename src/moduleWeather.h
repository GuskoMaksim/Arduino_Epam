#ifndef MODULE_WEATHER_H
#define MODULE_WEATHER_H

#include <config.h>

class moduleWeather
{
private:
    GTimer TimerWeather;

public:
    moduleWeather();
    bool isReady();

    int16_t GetTemperature();

#if MODULE_WEATHER_HUMIDITY == ON
    int16_t GetHumidity();
#endif

#if MODULE_WEATHER_PRESSURE == ON
    int16_t GetPressure();
#endif
};

#endif
