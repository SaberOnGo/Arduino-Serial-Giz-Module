/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
 clears it.
 
 A good test for this is to try it with a GPS receiver 
 that sends out NMEA 0183 sentences. 
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */
#include "Arduino.h"
#include <OneWire.h>
#include <SoftwareSerial.h>
#include "Serial_Drv.h"
#include "Os_timer.h"
#include "AtCmd_Drv.h"

#include "GizCmdTest.h"
#include "SensorApp.h"

// 建议: 不要在这个文件中增加任何代码
// 传感器数据获取建议在 SensorApp.cpp 中用定时器回调获取

void setup() {
   ATCMD_Init();
   SystemInit();
   GizCmdTestInit();
}

void loop() 
{
    SerialDrv_Task(ATUART_RxIntServer);
    OS_TimerTask();
    //DS18B20_GetTemperature(&tempVal);
     
}





