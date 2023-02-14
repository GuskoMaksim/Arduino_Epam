#include "SensorBME280.h"

SensorBME280::SensorBME280(uint32_t update_sensor)
{
    if (!BME280.begin(module_adress_))
        Serial.println("Error!");
    else
        Serial.println("BME280 module added to the device!");
};

void SensorBME280::Upadate()
{
    if (IsReady())
    {
        temperature_ = BME280.readTemperature();
        pressure_ = BME280.readPressure() / mmColumn_;
        humidity_ = BME280.readHumidity();
    }
};
