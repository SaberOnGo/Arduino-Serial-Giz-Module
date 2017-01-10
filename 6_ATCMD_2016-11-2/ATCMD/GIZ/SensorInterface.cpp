
#include "SensorInterface.h"

//get the time of device mcu
E_BOOL FLASH_SAVE Sensor_GetHourMinSec(uint32_t * hour, uint32_t * min, uint32_t * sec)
{
   *hour = 12;
   *min = 55;
   *sec = 56;

   return E_TRUE;
} 

// get system running state
uint8_t FLASH_SAVE Sensor_GetSysState(void)
{
   return 1;
}

// real pm2.5 val * 1000, three valid decimal
uint16_t FLASH_SAVE Sensor_GetPM25Val(void)
{
    float realPM25Val = 57.234;  // 25.123%
	uint16_t result = 0;

	result = (uint16_t)(realPM25Val * 1000);
	return result;
}

// real  formaldehyde  val * 1000, three valid decimal
uint32_t FLASH_SAVE Sensor_GetFormaldehydeVal(void)
{
    float realFormaVal = 18.600;  // 2.3 %
	uint32_t result = 0;

	result = (uint32_t)(realFormaVal * 1000);
	return result;
}

// real temperature  val * 1000, three valid decimal
uint32_t FLASH_SAVE Sensor_GetTemperatureVal(void)
{
    float realTempVal = 28.623;  // 25.125 'C
	uint32_t result = 0;

	result = (uint32_t)(realTempVal * 1000);
	
	result += (uint32_t)random(10, 10000);
	
	return result;
}

// real  humidity  val * 1000, two valid decimal
uint32_t FLASH_SAVE Sensor_GetHumidityVal(void)
{
    float realHumiVal = 80.18;  // 70.12 %
	uint32_t result = 0;

	result = (uint32_t)(realHumiVal * 1000);
	return result;
}

// real  battery capacity val * 1000, three valid decimal
uint32_t FLASH_SAVE Sensor_GetBatCapacityVal(void)
{
   float realBatCapacity = 60.15; // 70.15 %
   uint32_t result = 0;

   result = (uint32_t)(realBatCapacity * 1000);
   return result;
}

