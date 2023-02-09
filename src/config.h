#include <Arduino.h>
#include <GyverTimer.h>

#ifndef CONFIG_H
#define CONFIG_H

#define ON true
#define OFF false
#define NOT -1

//---------Configuration for modules--------
#define MODULE_WEATHER OFF
#define MODULE_LSD OFF
//-------End configuration for modules------

//---------Configuration for devices--------

#if MODULE_WEATHER == ON
//----Configuration of measurement parameters----
#define MODULE_WEATHER_TEMPERATURE NOT
#define MODULE_WEATHER_HUMIDITY NOT
#define MODULE_WEATHER_PRESSURE NOT
#define MODULE_WEATHER_TIME 5000

#define BME_280 1   // !Check the humidity measurement, some models may not have this feature!
#define DHT_GROUP 2 // !Not used for direct selection!
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
#if MODULE_WEATHER_TYPE == DHT_GROUP
#error "Not used DHT_GROUP for direct selection!"
#endif

#if (MODULE_WEATHER_TEMPERATURE == NOT) || (MODULE_WEATHER_HUMIDITY == NOT) || (MODULE_WEATHER_PRESSURE == NOT)
#error "Set up the weather sensor!"
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

#endif