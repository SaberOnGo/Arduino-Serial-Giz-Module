
#include "Arduino.h"
#include "Os_timer.h"
#include "GlobalFunc.h"

#include "SensorApp.h"

#include "SensorInterface.h"
#include "AtCmd_Drv.h"
#include "DS18B20_Drv.h"

static os_timer_t tGetTempTimer;  // ��ʱ��ȡ�¶�ֵ�Ķ�ʱ��

/********************************************
����һ����ȡ������������:
0   ����һ����ʱ��: ��static os_timer_t tGetTempTimer;
1   ����һ���ص�����: �������е�SensorGetTempTest_CallBack
2   �ڻص������л�ȡ��������ֵ
3   ���洫������ֵ, ���¶�����Sensor_SetTemperature() ����, �����ӿ���SensorInterface.h ��

4. 1   ���ʹ����������ݸ�ESP8266: Sensor_TriggerToReport()
���� 
4.2    Ardunio��Ҫ���̷��ʹ���������, ֻҪ����3�����
         ���ESP8266 ̽�⵽�� APP ����, �������Ҫ�� Ardunio �ϱ�

4.1 �Ĳ����ǿ��Ա�֤������������һ�иı�Ϳ���push �� APP

5   �� SensorAppInit() ������: ��ʼ������������;  ��ʼ����ʱ��

***********************************************/

#if SENSOR_API_TEST_EN
// ��ȡ�¶ȴ��������ݵĻص�����
static void FLASH_SAVE SensorGetTempTest_CallBack(void * arg)
{    
	float temp = 0;	    
	
	os_timer_disarm(&tGetTempTimer);      
	if(DS18B20_GetTemperature(&temp) == APP_SUCCESS)       // ��ȡ�¶ȴ������ɹ�
	{       
		Sensor_SetTemperature((uint32_t)temp);        // ���洫��������  
		Sensor_TriggerToReport();                      // ��������, ������������ͨ��ESP8266 ���� APP
	}	
	os_timer_arm(&tGetTempTimer, 1000, 0); 
}
#endif

static void FLASH_SAVE SensorAppInit(void)
{	

	#if SENSOR_API_TEST_EN	
	DS18B20_Init();  		                      // �¶ȴ�����������ʼ��
	os_timer_disarm(&tGetTempTimer);            // �� ��ֹ��ʱ��	
	os_timer_setfn(&tGetTempTimer, (os_timer_func_t *) SensorGetTempTest_CallBack, NULL);  	 // ���ûص�����
	os_timer_arm(&tGetTempTimer, 1000, 0);  	  // ������ʱ��, 1 s ��ʱ���, ���ζ�ʱ
	#endif
}

void FLASH_SAVE SystemInit(void)
{
    SensorAPI_Init();   // Sensor API ��ʼ��
    SensorAppInit();    // Sensor Ӧ�ó�ʼ��
}




