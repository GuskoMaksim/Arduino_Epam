#include "config.h"

#if MODULE_WEATHER == ON
#include "moduleWeather.h"
moduleWeather *m_weather;
int16_t temperature = 0;
int16_t humidity = 0;
int16_t pressure = 0;

void updateWeatherRoom()
{
  if (m_weather->isReady())
  {
    temperature = m_weather->GetTemperature();
    humidity = m_weather->GetHumidity();
    pressure = m_weather->GetPressure();
    Serial.println(temperature);
    Serial.println(humidity);
    Serial.println(pressure);
  }
}
#endif

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");
#if MODULE_WEATHER == ON
  m_weather = new moduleWeather();
#endif
}

void loop()
{
#if MODULE_WEATHER == ON
  updateWeatherRoom();
#endif
}
