
#ifndef __SENSOR_INTERFACE_H__
#define  __SENSOR_INTERFACE_H__

//#include "giz_includes.h"
#include "Arduino.h"
#include <stdarg.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include "string.h"
#include "GlobalDef.h"
#include "GlobalFunc.h"

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
#endif

#pragma upack (1)


E_BOOL FLASH_SAVE Sensor_GetHourMinSec(uint32_t * hour, uint32_t * min, uint32_t * sec);
uint8_t FLASH_SAVE Sensor_GetSysState(void);
uint16_t FLASH_SAVE Sensor_GetPM25Val(void);
uint32_t FLASH_SAVE Sensor_GetFormaldehydeVal(void);
uint32_t FLASH_SAVE Sensor_GetTemperatureVal(void);
uint32_t FLASH_SAVE Sensor_GetHumidityVal(void);
uint32_t FLASH_SAVE Sensor_GetBatCapacityVal(void);

#endif

