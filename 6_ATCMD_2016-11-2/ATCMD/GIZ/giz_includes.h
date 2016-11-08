#ifndef __GIZ_INCLUDES_H__
#define  __GIZ_INCLUDES_H__

#include "Arduino.h"
#include <stdarg.h>
#include <avr/pgmspace.h>
#include "string.h"
#include "GlobalDef.h"
#include "GlobalFunc.h"
#include <SoftwareSerial.h>
#include "tfp_printf.h"
#include "Serial_Drv.h"
#include "Os_timer.h"
#include <OneWire.h>
#include "DS18B20_Drv.h"
#include "WifiInterface.h"
#include "SensorInterface.h"
#include "AtCmd_Drv.h"
#include "GizCmdTest.h"





#define DEVICE_PROTOCOL_VER   "COMV1.00"   // serial version: 8B,V0.01
#define DEVICE_PRIVATE_VER    "PV1.00R0"
#define DEVICE_PCB_VER        "HV1.00R1"   // PCB version: 8B, V1.00
#define DEVICE_SOFT_VER       "SV0.01T1"   // Software 8B
#define DEVICE_PRODUCT_KEY    "Arduino Nano V3.00"   // 32

#endif

