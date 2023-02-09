#include "moduleWeather.h"

#if MODULE_WEATHER == ON

#if MODULE_WEATHER_TYPE == BME_280
#include <GyverBME280.h>
GyverBME280 BME280_Module;
#endif

#if (MODULE_WEATHER_TYPE == DHT_11) || (MODULE_WEATHER_TYPE == DHT_12) || (MODULE_WEATHER_TYPE == DHT_21) || (MODULE_WEATHER_TYPE == DHT_22) || (MODULE_WEATHER_TYPE == AM_2301)
#include <DHT.h>
#define DHT_PIN NOT // number of the pin to which the sensor is connected (Example 2)
#if DHT_PIN == NOT
#error "Select the pin in to which the sensor is connected!"
#endif
DHT dht(MODULE_WEATHER_TYPE, DHT_PIN);
#define DHT_TYPE MODULE_WEATHER_TYPE  // module type
#define MODULE_WEATHER_TYPE DHT_GROUP // Functions common to all sensors are used
#endif

moduleWeather::moduleWeather()
{
    TimerWeather.setInterval(MODULE_WEATHER_TIME);
#if MODULE_WEATHER_TYPE == BME_280
    if (!BME280_Module.begin(0x76))
        Serial.println("Error!");
    else
        Serial.println("BME280 module added to the device!");
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
    dht.begin();
    Serial.println("DHT module added to the device!");
#endif
};

bool moduleWeather::isReady()
{
    return TimerWeather.isReady();
};

#if MODULE_WEATHER_TEMPERATURE == ON
int16_t moduleWeather::GetTemperature()
{
#if MODULE_WEATHER_TYPE == BME_280
    return round(BME280_Module.readTemperature());
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
    return round(dht.readTemperature());
#endif
    return -1;
};
#endif

#if MODULE_WEATHER_HUMIDITY == ON
int16_t moduleWeather::GetHumidity()
{
#if MODULE_WEATHER_TYPE == BME_280
    return BME280_Module.readHumidity();
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
    return round(dht.readHumidity());
#endif
    return -1;
};
#endif

#if MODULE_WEATHER_PRESSURE == ON
int16_t moduleWeather::GetPressure()
{
#if MODULE_WEATHER_TYPE == BME_280
    return round(BME280_Module.readPressure() / 132.32f);
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
    return -1;
#error "Modules of the DHT group cannot measure pressure"
#endif
    return -1;
};
#endif

#endif
