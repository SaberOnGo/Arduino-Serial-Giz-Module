
#include "GlobalFunc.h"
#include "SensorInterface.h"
#include "AtCmd_Drv.h"

static T_SENSOR tSensor;  // 传感器集合
static T_DEVICE_STATUS tDeviceStatus;

void FLASH_SAVE Sensor_SetTime(T_TIME *time)
{
   if(NULL == time){INSERT_ERROR_INFO(); return; }
   
   os_memcpy(&tSensor.time, time, sizeof(T_TIME));
}

/*****************************************************************************
 * @\fn  : Sensor_GetHourMinSec
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief :  获取时间值: 包括年月日时分秒
 * @\param[in] :   T_TIME *time  时间结构体的指针
 * @\param[out] : T_TIME *time   输出的时间值
 * @\return : none
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
void FLASH_SAVE Sensor_GetTime(T_TIME *time)
{
   if(NULL == time){ INSERT_ERROR_INFO(); return; }
   
   os_memcpy(time, &tSensor.time, sizeof(T_TIME));
} 

void FLASH_SAVE Sensor_SetSysState(uint8_t sys_state){ tSensor.device.sys_status = sys_state; }

/*****************************************************************************
 * @\fn  : Sensor_GetSysState
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 获取系统状态
 * @\param[in] : void  none
 * @\param[out] : none
 * @\return :  系统状态
 * @\attention : 
 * @\note [others] :  系统状态待修改, TODO

*****************************************************************************/
uint8_t FLASH_SAVE Sensor_GetSysState(void)
{
   return 1;
}

void FLASH_SAVE Sensor_SetPM25Val(uint16_t newVal){ tSensor.device.pm25 = newVal; }

/*****************************************************************************
 * @\fn  : Sensor_GetPM25Val
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 获取 PM25的值, 整数, 单位: ug/m3
 * @\param[in] : void
 * @\param[out] : none
 * @\return : uint16_t,  PM25 值
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint16_t FLASH_SAVE Sensor_GetPM25Val(void)
{
    return tSensor.device.pm25;
}

void FLASH_SAVE Sensor_SetFormaldehyde(uint32_t newVal){ tSensor.device.forma = newVal; }

/*****************************************************************************
 * @\fn  : Sensor_GetFormaldehyde
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 获取甲醛传感器的值, 单位由Set函数自定
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t   甲醛传感器值
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetFormaldehyde(void)
{ 
	return tSensor.device.forma;
}

void FLASH_SAVE Sensor_SetTemperature(uint32_t newVal){ tSensor.device.temperatue = newVal; }

/*****************************************************************************
 * @\fn  : Sensor_GetTemperature
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 获取温度传感器的值, 单位由Set函数自定
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t   温度值
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetTemperature(void)
{
	return tSensor.device.temperatue;
}

void FLASH_SAVE Sensor_SetHumidity(uint32_t newVal){ tSensor.device.humiduty = newVal; }

/*****************************************************************************
 * @\fn  : Sensor_GetHumidity
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief :  获取湿度传感器的值, 单位由Set 函数自定
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  湿度值
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetHumidity(void)
{
    return tSensor.device.humiduty;
}

void FLASH_SAVE Sensor_SetBatCapacity(uint32_t newVal){ tSensor.device.batCapacity = newVal; }

/*****************************************************************************
 * @\fn  : Sensor_GetBatCapacity
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief :  获取电池容量值, 单位由Set 函数自定
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  电池容量
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetBatCapacity(void)
{
   return tSensor.device.batCapacity;
}

void FLASH_SAVE Sensor_SetAirPressure(uint32_t newVal){ tSensor.device.airPressure = newVal; }

/*****************************************************************************
 * @\fn  : Sensor_GetAirPressure
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief :  获取大气压的值,  单位由Set 函数自定
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  大气压
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetAirPressure(void)
{
   return tSensor.device.airPressure;
}

void FLASH_SAVE Sensor_SetWinddSpeed(uint32_t newVal){ tSensor.device.windSpeed; }

/*****************************************************************************
 * @\fn  : Sensor_GetWindSpeed
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief :  获取风速,  单位由Set 函数自定
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  风速
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetWindSpeed(void)
{
   return tSensor.device.windSpeed;
}

void FLASH_SAVE Sensor_SetWindDir(uint32_t newVal){ tSensor.device.windDir; }

/*****************************************************************************
 * @\fn  : Sensor_GetWindDir
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief :  获取风向,  单位由Set 函数自定
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  风向
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetWindDir(void)
{
   return tSensor.device.windDir;
}

void FLASH_SAVE Sensor_SetRainfall(uint32_t newVal){ tSensor.device.rainfall = newVal; }

/*****************************************************************************
 * @\fn  : Sensor_GetRainfall
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 获取降雨量, 单位由Set 函数自定
 * @\param[in] : void 
 * @\param[out] : none
 * @\return : uint32_t   降雨量
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetRainfall(void)
{
   return tSensor.device.rainfall;
}


void FLASH_SAVE Sensor_SetLightIntensity(uint32_t newVal)
{
   tSensor.device.lightIntensity = newVal;
}

/*****************************************************************************
 * @\fn  : Sensor_GetLightIntensity
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 获取光照强度, 单位由Set 函数自定
 * @\param[in] : void 
 * @\param[out] : none
 * @\return : uint32_t  光照强度
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetLightIntensity(void)
{
   return tSensor.device.lightIntensity;
}

/*****************************************************************************
 * @\fn  : Sensor_SetUltraviolet
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 保存紫外线强度的值
 * @\param[in] : uint32_t newVal  紫外线强度
 * @\param[out] : none
 * @\return : void
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
void FLASH_SAVE Sensor_SetUltraviolet(uint32_t newVal)
{
   tSensor.device.ultraviolet = newVal;
}

/*****************************************************************************
 * @\fn  : Sensor_GetUltraviolet
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 获取紫外线强度, 单位由Set 函数自定
 * @\param[in] : void 
 * @\param[out] : none
 * @\return : uint32_t  紫外线强度
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
uint32_t FLASH_SAVE Sensor_GetUltraviolet(void)
{
   return tSensor.device.ultraviolet;
}

/*****************************************************************************
 * @\fn  : Sensor_SetDevice
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 保存所有传感器的值, 除时间值外
 * @\param[in] : T_DEVICE_STATUS * device 传感器设备结构体
 * @\param[out] : none
 * @\return : none
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
void FLASH_SAVE Sensor_SetDevice(T_DEVICE_STATUS * device)
{
   if(NULL == device){ INSERT_ERROR_INFO(); return; }
   
   os_memcpy(&tSensor.device, device, sizeof(T_DEVICE_STATUS));
}

/*****************************************************************************
 * @\fn  : Sensor_GetDevice
 * @\author : pi
 * @\date : 2017 - 1 - 12
 * @\brief : 获取所有传感器的值, 除时间值外
 * @\param[in] : 输入的T_DEVICE_STATUS 的指针
 * @\param[out] : T_DEVICE_STATUS * device 传感器设备结构体
 * @\return :  none
 * @\attention :   数据的具体意义(即单位) 由Set函数决定, 即用户自定义单位
 * @\note [others] : 

*****************************************************************************/
void FLASH_SAVE Sensor_GetDevice(T_DEVICE_STATUS * device)
{
   if(NULL == device){ INSERT_ERROR_INFO(); return; }
   os_memcpy(device, &tSensor.device, sizeof(T_DEVICE_STATUS));
}

/*****************************************************************************
 * @\fn  : Sensor_TriggerToReport
 * @\author : pi
 * @\date : 2017 - 1 - 13
 * @\brief : 触发一次上报传感器数据的流程. 传感器的数据将会通过ESP8266 发送到APP
 * @\param[in] : none
 * @\param[out] : none
 * @\return : void
 * @\attention : 
 * @\note [others] : 

*****************************************************************************/
void FLASH_SAVE Sensor_TriggerToReport(void)
{
   CMDFN_SendReadDeviceCurStatusReport();
}

// 传感器接口初始化
void FLASH_SAVE SensorAPI_Init(void)
{
    T_TIME time = {17, 1, 12, 12, 30, 59};  // 2017-1-12 12:30:59
    
	T_DEVICE_STATUS device;
	
    // begin 设置默认值

    Sensor_SetTime(&time);  // 设置时间
    Sensor_SetSysState(1);  // 系统状态, 仅测试

    
    #if (SENSOR_API_TEST_EN == 0)   // for release
    os_memset(&device, 0, sizeof(device));
	#else   // 仅测试, for debug
	device.pm25 = 70;
	device.forma = 10;
	device.temperatue = 27125;  // 用户自定义格式, 我这里表示: 27.125 'C
	device.humiduty   = 70;      
	device.batCapacity = 90;

	device.airPressure = 105;  
	device.windSpeed = 30;
	device.windDir = 1;
	device.rainfall = 30;
	device.lightIntensity = 10;
	device.ultraviolet = 5;
	#endif

	
	device.hour = time.hour;
	device.min	= time.min;
	device.sec	= time.sec;

	device.sys_status = Sensor_GetSysState();

	Sensor_SetDevice(&device);
	// end 设置默认值
}






