#include <GyverBME280.h>
#include "Sensor.h"

class SensorBME280 : public Sensor
{
private:
    GyverBME280 BME280;
    const float mmColumn_ = 132.32f;     // Conversion factor into millimeters of mercury column
    const uint8_t module_adress_ = 0x76; // Device address for communication
    void Upadate() override;

public:
    SensorBME280(uint32_t update_sensor);
};
