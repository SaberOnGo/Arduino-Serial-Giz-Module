
#include "Arduino.h"
#include "Os_timer.h"
#include "GlobalFunc.h"

#include "SensorApp.h"

#include "SensorInterface.h"
#include "AtCmd_Drv.h"
#include "DS18B20_Drv.h"

static os_timer_t tGetTempTimer;  // 定时获取温度值的定时器

/********************************************
增加一个读取传感器的流程:
0   定义一个定时器: 如static os_timer_t tGetTempTimer;
1   定义一个回调函数: 如例子中的SensorGetTempTest_CallBack
2   在回调函数中获取传感器的值
3   保存传感器的值, 如温度则用Sensor_SetTemperature() 保存, 其他接口在SensorInterface.h 中

4. 1   发送传感器的数据给ESP8266: Sensor_TriggerToReport()
或者 
4.2    Ardunio不要即刻发送传感器数据, 只要步骤3保存后
         如果ESP8266 探测到有 APP 连接, 则会主动要求 Ardunio 上报

4.1 的步骤是可以保证传感器的数据一有改变就可以push 到 APP

5   在 SensorAppInit() 函数中: 初始化传感器驱动;  初始化定时器

***********************************************/

#if SENSOR_API_TEST_EN
// 获取温度传感器数据的回调函数
static void FLASH_SAVE SensorGetTempTest_CallBack(void * arg)
{    
	float temp = 0;	    
	
	os_timer_disarm(&tGetTempTimer);      
	if(DS18B20_GetTemperature(&temp) == APP_SUCCESS)       // 读取温度传感器成功
	{       
		Sensor_SetTemperature((uint32_t)temp);        // 保存传感器数据  
		Sensor_TriggerToReport();                      // 启动发送, 将传感器数据通过ESP8266 发到 APP
	}	
	os_timer_arm(&tGetTempTimer, 1000, 0); 
}
#endif

static void FLASH_SAVE SensorAppInit(void)
{	

	#if SENSOR_API_TEST_EN	
	DS18B20_Init();  		                      // 温度传感器驱动初始化
	os_timer_disarm(&tGetTempTimer);            // 先 禁止定时器	
	os_timer_setfn(&tGetTempTimer, (os_timer_func_t *) SensorGetTempTest_CallBack, NULL);  	 // 设置回调函数
	os_timer_arm(&tGetTempTimer, 1000, 0);  	  // 启动定时器, 1 s 定时间隔, 单次定时
	#endif
}

void FLASH_SAVE SystemInit(void)
{
    SensorAPI_Init();   // Sensor API 初始化
    SensorAppInit();    // Sensor 应用初始化
}




