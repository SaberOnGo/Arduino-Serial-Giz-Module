# Arduino-Serial-Giz-Module


使用 Arduino IDE 1.0.5 编译时
需将库 "SoftwareSerial" 放在 ../arduino-1.0.5-r2-windows/arduino-1.0.5-r2/libraries  下
       "OneWire" 放在  ../arduino-1.0.5-r2-windows/arduino-1.0.5-r2/libraries   下
  
 Giz模块主要文件: AtCmd_Drv.cpp, GizCmdTest.cpp 及头文件
 移植Giz模块时需实现API:
 os_printf:    串口打印调试输出, 波特率 4800
 GIZ_UartSend(str): 硬件串口输出 Giz命令
 
 软件定时器接口(兼容ESP8266的软件定时器API):
 os_timer_disarm(timer)   停止定时器
 os_timer_setfn(timer, func, param): 设置定时器回调函数
 os_timer_arm(timer, ms, is_repeat): 设置定时时间,单位ms
  
 系统接口:
  Sys_GetRunTime(): 获取系统运行至今的时间, 单位ms
  
  
  使用方法:
  1  定义宏:  #define GIZ_PLATFORM    USE_ARDUINO  // 作为设备端, 与WIFI 模块连接
  2  将Arduino Nano的RX, TX 接WIFI 模块(比如ESP8266)的TX, RX端, 两者波特率需要一致(default: 115200)
  3  将软件串口管脚 D10(RX), D11(TX) 通过USB 转串口模块连接电脑, 波特率4800, 作为调试信息输出
  
  调试方法: 
  1  将 Arduino Nano的RX 接TX
  2  将软件串口管脚 D10(RX), D11(TX) 通过USB 转串口模块连接电脑, 波特率4800, 作为调试信息输出
  
  
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
    
    SerialDrv_Task(ATUART_RxIntServer);   // (if GIZ msg send & receive by UART, not necessary, I2C, SPI is OK)
    COS_TimerTask();                      // to check soft timer 
 }
 
 
 #  Giz module need two physical device: Wifi Module and the Device(MCU)
 #  #define  USE_ARDUINO    0
 #  #define  USE_ESP8266    1

 #  the other side use USE_ESP8266 MARCO as wifi device to tx/rx msg
 #  #define GIZ_PLATFORM    USE_ARDUINO
   