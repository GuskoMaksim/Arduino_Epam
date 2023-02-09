#ifndef MODULE_WEATHER_H
#define MODULE_WEATHER_H

#include <config.h>

#if MODULE_WEATHER_TYPE == BME280
#include <GyverBME280.h>
#endif

#if (MODULE_WEATHER_TYPE == DHT_11) || (MODULE_WEATHER_TYPE == DHT_12) || (MODULE_WEATHER_TYPE == DHT_21) || (MODULE_WEATHER_TYPE == DHT_22) || (MODULE_WEATHER_TYPE == AM_2301)
#include <DHT.h>
#define DHT_PIN 2 // number of the pin to which the sensor is connected
namespace
{
    DHT dht(MODULE_WEATHER_TYPE, DHT_PIN);
}
#define DHT_TYPE MODULE_WEATHER_TYPE  // module type
#define MODULE_WEATHER_TYPE DHT_GROUP // Functions common to all sensors are used
#endif

class moduleWeather
{
private:
    GTimer TimerWeather;
#if MODULE_WEATHER_TYPE == BME_280
    GyverBME280 Bme280_Module;
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
#endif

public:
    bool isReady()
    {
        return TimerWeather.isReady();
    }
    moduleWeather()
    {
        TimerWeather.setInterval(MODULE_WEATHER_TIME);
#if MODULE_WEATHER_TYPE == BME_280
        if (!Bme280_Module.begin(0x76))
            Serial.println("Error!");
        else
            Serial.println("BME280 module added to the device!");
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
        dht.begin();
        Serial.println("DHT module added to the device!");
#endif
    };

#if MODULE_WEATHER_TEMPERATURE == ON
    int16_t GetTemperature()
    {
#if MODULE_WEATHER_TYPE == BME_280
        return round(BME280_Module.readTemperature());
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
        return round(dht.readTemperature());
#endif
        return -1;
    }
#endif

#if MODULE_WEATHER_HUMIDITY == ON
    int16_t GetHumidity()
    {
#if MODULE_WEATHER_TYPE == BME_280
        return BME280_Module.readHumidity();
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
        return round(dht.readHumidity());
#endif
        return -1;
    }
#endif

#if MODULE_WEATHER_PRESSURE == ON
    int16_t GetPressure()
    {
#if MODULE_WEATHER_TYPE == BME_280
        return round(BME280_Module.readPressure() / 132.32f);
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
        return -1;
#error "Modules of the BME group cannot measure pressure"
#endif
        return -1;
    }
#endif
};

#endif
