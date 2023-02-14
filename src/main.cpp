#include <Arduino.h>
#include "SensorBME280.h"
#include "SensorDHTgroup.h"

constexpr uint32_t update_sensor = 5000;
Sensor *module_weather;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");
  module_weather = new SensorBME280(update_sensor);
}

void loop()
{
  module_weather->Upadate();
  module_weather->Serial_print_data();
}
