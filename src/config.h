#include <Arduino.h>
#include <GyverTimer.h>

#ifndef CONFIG_H
#define CONFIG_H

#define ON true
#define OFF false
#define NON -1

//---------Configuration for modules--------
#define MODULE_WEATHER OFF
#define MODULE_LSD OFF
//-------End configuration for modules------

//---------Configuration for devices--------
#if MODULE_WEATHER == ON

//----Configuration of measurement parameters----
#define MODULE_WEATHER_TEMPERATURE NON
#define MODULE_WEATHER_HUMIDITY NON
#define MODULE_WEATHER_PRESSURE NON
#define MODULE_WEATHER_TIME 5000

#define BME_280 1
#define DHT_GROUP 2 // !Not used for direct selection!
#define DHT_11 11
#define DHT_12 12
#define DHT_21 21
#define DHT_22 22
#define AM_2301 21

//----Sensor selection----
#define MODULE_WEATHER_TYPE NON
#if MODULE_WEATHER_TYPE == NON
#error "Select the sensor of weather!"
#endif
#if MODULE_WEATHER_TYPE == DHT_GROUP
#error "Not used for direct selection!"
#endif

#if (MODULE_WEATHER_TEMPERATURE == NON) || (MODULE_WEATHER_HUMIDITY == NON) || (MODULE_WEATHER_PRESSURE == NON)
#error "Set up the weather sensor!"
#endif

#endif

#if MODULE_LSD == ON
#define LCD_1602 1
#define LCD_2004 2
#define MODEULE_LCD_TYPE NON
#if MODEULE_LCD_TYPE == NON
#error "Select a module of LSD!"
#endif
#endif
//-----End of configuration for devices-----

#endif