#pragma once
#include <Arduino.h>
#include <GyverTimer.h>

#define ON true
#define OFF false
#define NOT -1 // Error returned from all measurements when no measurement is possible

//---------Configuration for modules--------
#define MODULE_WEATHER OFF
#define MODULE_LSD OFF
//-------End configuration for modules------

//---------Configuration for devices--------

#if MODULE_WEATHER == ON
//----Configuration of the sensor update rate in milliseconds----
#define MODULE_WEATHER_TIME 5000

#define BME_280 1 // !Check the humidity measurement, some models may not have this feature!
#define DHT_11 11
#define DHT_12 12
#define DHT_21 21
#define DHT_22 22
#define AM_2301 21

//----Sensor selection----
#define MODULE_WEATHER_TYPE NOT
#if MODULE_WEATHER_TYPE == NOT
#error "Select the sensor of weather!"
#endif

#endif

#if MODULE_LSD == ON
#define LCD_1602 1
#define LCD_2004 2
#define MODEULE_LCD_TYPE NOT
#if MODEULE_LCD_TYPE == NOT
#error "Select a module of LSD!"
#endif
#endif
//-----End of configuration for devices-----
