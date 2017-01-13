
#ifndef __SENSOR_INTERFACE_H__
#define  __SENSOR_INTERFACE_H__

//#include "giz_includes.h"
//#include "Arduino.h"
//#include <stdarg.h>
//#include <stdio.h>
//#include <avr/pgmspace.h>
//#include "string.h"
#include "GlobalDef.h"
//#include "GlobalFunc.h"


#define SENSOR_API_TEST_EN   1    // 传感器接口测试, 仅用来演示怎样使用这些接口, 可屏蔽

#pragma pack (1)
typedef struct
{
   uint8_t year;
   uint8_t month;
   uint8_t date;
   uint8_t hour;
   uint8_t min;
   uint8_t sec;
}T_TIME;

#if 0
typedef struct
{
    uint32_t hour;
	uint32_t min;
	uint32_t sec;
	uint8_t  sys_status;
	uint16_t pm25;   // 0 - 9999
	uint32_t forma;  
	uint32_t temperatue;
	uint32_t humiduty;
	uint32_t batCapacity;  // battery capacity
}T_DEVICE_STATUS;  // 31 B
#else
typedef struct struct_device_status
{
    uint32_t hour;
	uint32_t min;
	uint32_t sec;
	uint8_t  sys_status;  // 系统状态
	uint16_t pm25;        // 0 - 9999, pm25 浓度
	uint32_t forma;       // 甲醛浓度
	uint32_t temperatue;  // 温度
	uint32_t humiduty;    // 湿度, %
    uint32_t batCapacity;  // battery capacity
    
	uint32_t airPressure;   // 气压
	uint32_t windSpeed;     // 风速
	uint32_t windDir;        // 风向
	uint32_t rainfall;       // 降雨量
	uint32_t lightIntensity;  // 光照强度
	uint32_t ultraviolet;     // 紫外线强度	
}T_DEVICE_STATUS;  // 传感器集合

// 传感器集合
typedef struct
{
    T_TIME time;
	T_DEVICE_STATUS device;
}T_SENSOR;

#endif

#pragma upack (1)

void     FLASH_SAVE Sensor_SetTime(T_TIME *time);
void     FLASH_SAVE Sensor_GetTime(T_TIME *time);
void     FLASH_SAVE Sensor_SetSysState(uint8_t sys_state);
uint8_t  FLASH_SAVE Sensor_GetSysState(void);
void     FLASH_SAVE Sensor_SetPM25Val(uint16_t newVal);
uint16_t FLASH_SAVE Sensor_GetPM25Val(void);
void     FLASH_SAVE Sensor_SetFormaldehyde(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetFormaldehyde(void);
void     FLASH_SAVE Sensor_SetTemperature(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetTemperature(void);
void     FLASH_SAVE Sensor_SetHumidity(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetHumidity(void);
void     FLASH_SAVE Sensor_SetBatCapacity(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetBatCapacity(void);
void     FLASH_SAVE Sensor_SetAirPressure(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetAirPressure(void);
void     FLASH_SAVE Sensor_SetWinddSpeed(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetWindSpeed(void);
void     FLASH_SAVE Sensor_SetWindDir(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetWindDir(void);
void     FLASH_SAVE Sensor_SetRainfall(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetRainfall(void);
void     FLASH_SAVE Sensor_SetLightIntensity(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetLightIntensity(void);
void     FLASH_SAVE Sensor_SetUltraviolet(uint32_t newVal);
uint32_t FLASH_SAVE Sensor_GetUltraviolet(void);

void     FLASH_SAVE Sensor_SetDevice(T_DEVICE_STATUS * device);
void     FLASH_SAVE Sensor_GetDevice(T_DEVICE_STATUS * device);

void FLASH_SAVE SensorAPI_Init(void);
void FLASH_SAVE Sensor_TriggerToReport(void);


#endif

