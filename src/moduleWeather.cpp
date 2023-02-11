#include "moduleWeather.h"

#if MODULE_WEATHER == ON

#if MODULE_WEATHER_TYPE == BME_280
#include <GyverBME280.h>
GyverBME280 BME280_Module;
const float mmColumn = 132.32f; // parameter conversion to millimeters of mercury column
#define MODULE_ADDRESS 0x76
#define READ_TEMPERATURE round(BME280_Module.readTemperature())
#define READ_HUMIDITY round(BME280_Module.readHumidity())
#define READ_PRESSURE round(BME280_Module.readPressure() / mmColumn)
#define SET_UP                                \
    if (!BME280_Module.begin(MODULE_ADDRESS)) \
        Serial.println("Error!");             \
    else                                      \
        Serial.println("BME280 module added to the device!");
#endif

#if (MODULE_WEATHER_TYPE == DHT_11) || (MODULE_WEATHER_TYPE == DHT_12) || (MODULE_WEATHER_TYPE == DHT_21) || (MODULE_WEATHER_TYPE == DHT_22) || (MODULE_WEATHER_TYPE == AM_2301)
#include <DHT.h>
#define DHT_PIN NOT // number of the pin to which the sensor is connected (Example 2)
#if DHT_PIN == NOT
#error "Select the pin in to which the sensor is connected!"
#endif
DHT dht(MODULE_WEATHER_TYPE, DHT_PIN);
#define READ_TEMPERATURE dht.readTemperature()
#define READ_HUMIDITY dht.readHumidity()
#define READ_PRESSURE NOT // "Modules of the DHT group cannot measure pressure"
#define SET_UP   \
    dht.begin(); \
    Serial.println("DHT module added to the device!");
#endif

moduleWeather::moduleWeather()
{
    TimerWeather.setInterval(MODULE_WEATHER_TIME);
    SET_UP
};

bool moduleWeather::isReady()
{
    return TimerWeather.isReady();
};

int16_t moduleWeather::GetTemperature()
{
    return READ_TEMPERATURE;
};

int16_t moduleWeather::GetHumidity()
{
    return READ_HUMIDITY;
};

int16_t moduleWeather::GetPressure()
{
    return READ_PRESSURE;
};

#endif
