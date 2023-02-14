#include "SensorDHTgroup.h"

SensorDHTgroup::SensorDHTgroup(uint32_t update_sensor)
{
    dht = new DHT(module_type_, module_pin_);
    dht->begin();
    Serial.println("DHT module added to the device!");
};

SensorDHTgroup::~SensorDHTgroup()
{
    delete dht;
};

void SensorDHTgroup::Upadate()
{
    if (IsReady())
    {
        temperature_ = dht->readTemperature();
        pressure_ = 0;
        humidity_ = dht->readHumidity();
    }
};
