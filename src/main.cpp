#include "config.h"

#if MODULE_WEATHER == ON
#include "moduleWeather.h"
moduleWeather *m_weather;
#if MODULE_WEATHER_TEMPERATURE == ON
int16_t temperature = 0;
#endif
#if MODULE_WEATHER_HUMIDITY == ON
int16_t humidity = 0;
#endif
#if MODULE_WEATHER_PRESSURE == ON
int16_t pressure = 0;
#endif

void updateWeatherRoom()
{
  if (m_weather->isReady())
  {
#if MODULE_WEATHER_TEMPERATURE == ON
    temperature = m_weather->GetTemperature();
#endif
#if MODULE_WEATHER_HUMIDITY == ON
    temperature = m_weather->GetHumidity();
#endif
#if MODULE_WEATHER_PRESSURE == ON
    pressure = m_weather->GetPressure();
#endif
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

/*
#if MODEULE_LCD_INCLUDE == ON
#include <LiquidCrystal_I2C.h> //by Frank de Brabander
#endif


#if MODEULE_LCD_INCLUDE == ON
#if MODEULE_LCD_TYPE == LCD1602
  Serial.print("LCD1602 added to the device!");
#endif
#if MODEULE_LCD_TYPE == LCD2004
  Serial.print("LCD2004 added to the device!");
#endif
#endif

*/