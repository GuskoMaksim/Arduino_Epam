#include <Arduino.h>
#include "SensorBME280.h"
#include "SensorDHTgroup.h"

constexpr uint32_t refresh_interval_ms = 5000;
uint32_t timer_to_update_ms;
Sensor *module_weather;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");
  timer_to_update_ms = millis();
  module_weather = new SensorBME280();
}

void loop()
{
  if (millis() - timer_to_update_ms > refresh_interval_ms)
  {
    module_weather->Update();
    module_weather->Serial_print_data();
    timer_to_update_ms = millis();
  }
}
