#pragma once
#include <DHT.h>
#include "Sensor.h"

class SensorDHTgroup : public Sensor
{
private:
    const uint8_t module_pin_ = 2;
    const uint8_t module_type_ = 11;
    DHT *dht;
    void Update() override;

public:
    SensorDHTgroup();
    ~SensorDHTgroup();
};
