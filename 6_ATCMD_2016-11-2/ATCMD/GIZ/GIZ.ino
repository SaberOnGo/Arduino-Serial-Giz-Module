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
#include "giz_includes.h"

void setup() {
   ATCMD_Init();
   //DS18B20_Init();
   GizCmdTestInit();
}

void loop() 
{
    SerialDrv_Task(ATUART_RxIntServer);
    COS_TimerTask();
    //DS18B20_GetTemperature(&tempVal);
     
}





