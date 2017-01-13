
#include "GlobalFunc.h"
#include "SensorInterface.h"
#include "AtCmd_Drv.h"

static T_SENSOR tSensor;  // ����������
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
 * @\brief :  ��ȡʱ��ֵ: ����������ʱ����
 * @\param[in] :   T_TIME *time  ʱ��ṹ���ָ��
 * @\param[out] : T_TIME *time   �����ʱ��ֵ
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
 * @\brief : ��ȡϵͳ״̬
 * @\param[in] : void  none
 * @\param[out] : none
 * @\return :  ϵͳ״̬
 * @\attention : 
 * @\note [others] :  ϵͳ״̬���޸�, TODO

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
 * @\brief : ��ȡ PM25��ֵ, ����, ��λ: ug/m3
 * @\param[in] : void
 * @\param[out] : none
 * @\return : uint16_t,  PM25 ֵ
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
 * @\brief : ��ȡ��ȩ��������ֵ, ��λ��Set�����Զ�
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t   ��ȩ������ֵ
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
 * @\brief : ��ȡ�¶ȴ�������ֵ, ��λ��Set�����Զ�
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t   �¶�ֵ
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
 * @\brief :  ��ȡʪ�ȴ�������ֵ, ��λ��Set �����Զ�
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  ʪ��ֵ
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
 * @\brief :  ��ȡ�������ֵ, ��λ��Set �����Զ�
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  �������
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
 * @\brief :  ��ȡ����ѹ��ֵ,  ��λ��Set �����Զ�
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  ����ѹ
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
 * @\brief :  ��ȡ����,  ��λ��Set �����Զ�
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  ����
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
 * @\brief :  ��ȡ����,  ��λ��Set �����Զ�
 * @\param[in] : none
 * @\param[out] : none
 * @\return : uint32_t  ����
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
 * @\brief : ��ȡ������, ��λ��Set �����Զ�
 * @\param[in] : void 
 * @\param[out] : none
 * @\return : uint32_t   ������
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
 * @\brief : ��ȡ����ǿ��, ��λ��Set �����Զ�
 * @\param[in] : void 
 * @\param[out] : none
 * @\return : uint32_t  ����ǿ��
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
 * @\brief : ����������ǿ�ȵ�ֵ
 * @\param[in] : uint32_t newVal  ������ǿ��
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
 * @\brief : ��ȡ������ǿ��, ��λ��Set �����Զ�
 * @\param[in] : void 
 * @\param[out] : none
 * @\return : uint32_t  ������ǿ��
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
 * @\brief : �������д�������ֵ, ��ʱ��ֵ��
 * @\param[in] : T_DEVICE_STATUS * device �������豸�ṹ��
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
 * @\brief : ��ȡ���д�������ֵ, ��ʱ��ֵ��
 * @\param[in] : �����T_DEVICE_STATUS ��ָ��
 * @\param[out] : T_DEVICE_STATUS * device �������豸�ṹ��
 * @\return :  none
 * @\attention :   ���ݵľ�������(����λ) ��Set��������, ���û��Զ��嵥λ
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
 * @\brief : ����һ���ϱ����������ݵ�����. �����������ݽ���ͨ��ESP8266 ���͵�APP
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

// �������ӿڳ�ʼ��
void FLASH_SAVE SensorAPI_Init(void)
{
    T_TIME time = {17, 1, 12, 12, 30, 59};  // 2017-1-12 12:30:59
    
	T_DEVICE_STATUS device;
	
    // begin ����Ĭ��ֵ

    Sensor_SetTime(&time);  // ����ʱ��
    Sensor_SetSysState(1);  // ϵͳ״̬, ������

    
    #if (SENSOR_API_TEST_EN == 0)   // for release
    os_memset(&device, 0, sizeof(device));
	#else   // ������, for debug
	device.pm25 = 70;
	device.forma = 10;
	device.temperatue = 27125;  // �û��Զ����ʽ, �������ʾ: 27.125 'C
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
	// end ����Ĭ��ֵ
}






