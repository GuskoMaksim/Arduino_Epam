#include "SensorDHTgroup.h"

SensorDHTgroup::SensorDHTgroup()
{
    dht = new DHT(module_type_, module_pin_);
    dht->begin();
    Serial.println("DHT module added to the device!");
};

SensorDHTgroup::~SensorDHTgroup()
{
    delete dht;
};

void SensorDHTgroup::Update()
{
    temperature_ = dht->readTemperature();
    pressure_ = 0;
    humidity_ = dht->readHumidity();
};
