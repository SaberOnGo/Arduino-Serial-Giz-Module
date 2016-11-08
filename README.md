# Arduino-Serial-Giz-Module


ʹ�� Arduino IDE 1.0.5 ����ʱ
�轫�� "SoftwareSerial" ���� ../arduino-1.0.5-r2-windows/arduino-1.0.5-r2/libraries  ��
       "OneWire" ����  ../arduino-1.0.5-r2-windows/arduino-1.0.5-r2/libraries   ��
  
 Gizģ����Ҫ�ļ�: AtCmd_Drv.cpp, GizCmdTest.cpp ��ͷ�ļ�
 ��ֲGizģ��ʱ��ʵ��API:
 os_printf:    ���ڴ�ӡ�������, ������ 4800
 GIZ_UartSend(str): Ӳ��������� Giz����
 
 �����ʱ���ӿ�(����ESP8266�������ʱ��API):
 os_timer_disarm(timer)   ֹͣ��ʱ��
 os_timer_setfn(timer, func, param): ���ö�ʱ���ص�����
 os_timer_arm(timer, ms, is_repeat): ���ö�ʱʱ��,��λms
  
 ϵͳ�ӿ�:
  Sys_GetRunTime(): ��ȡϵͳ���������ʱ��, ��λms
  
  
  ʹ�÷���:
  1  �����:  #define GIZ_PLATFORM    USE_ARDUINO  // ��Ϊ�豸��, ��WIFI ģ������
  2  ��Arduino Nano��RX, TX ��WIFI ģ��(����ESP8266)��TX, RX��, ���߲�������Ҫһ��(default: 115200)
  3  ��������ڹܽ� D10(RX), D11(TX) ͨ��USB ת����ģ�����ӵ���, ������4800, ��Ϊ������Ϣ���
  
  ���Է���: 
  1  �� Arduino Nano��RX ��TX
  2  ��������ڹܽ� D10(RX), D11(TX) ͨ��USB ת����ģ�����ӵ���, ������4800, ��Ϊ������Ϣ���
  
  
        --CLOUD-------------------------------------------                            
                                                                                
            ^
            | 
            |  wilddog push data
            |
            |
            |             Giz Module 
        wifi device   <---------------->   MCU device  <------- Sensor 
                         UART/SPI/I2C
 
 
 main "Giz Module" file: AtCmd_Drv.cpp GizCmdTest.cpp and their header files
 
 if you want to use giz module on other MCU platforms like STM8/32, AVR...
 you have to implement as following:
 os_printf:          to print debug info out
 GIZ_UartSend(str):  giz module send cmd out

 software timer  API:
 os_timer_disarm(timer)   stop the timer
 os_timer_setfn(timer, func, param): set timer call back func
 os_timer_arm(timer, ms, is_repeat): set timing time and is repeat or not 
 
 systetem API:
 Sys_GetRunTime():   get system running time after power on, millisecond
 
 and then Init Giz Module:
 ATCMD_Init();
 
 In the loop call the following task forever:
 void loop(void)
 {
    SerialDrv_Task(ATUART_RxIntServer);   //(if GIZ msg send & receive by UART, not necessary, I2C, SPI is OK)
    COS_TimerTask();                      // to check soft timer 
 }
 
 
 Giz module need two physical device: Wifi Module and the Device(MCU)
#define  USE_ARDUINO    0
#define  USE_ESP8266    1

#define GIZ_PLATFORM    USE_ARDUINO  // the other side use USE_ESP8266 MARCO as wifi device to tx/rx msg