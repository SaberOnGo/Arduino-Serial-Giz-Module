
#ifndef __GLOBAL_DEF_H__
#define __GLOBAL_DEF_H__

#define  USE_ARDUINO    0
#define  USE_ESP8266    1

#define GIZ_PLATFORM    USE_ARDUINO


#define FLASH_SAVE        
#define RO_DATA_IN_FLASH   PROGMEM

// if enable the following debug switch at the same time, RAM will be run out, so be careful !
#define SERIAL_DEBUG_EN   0
#define GIZ_DEBUG_EN      0
#define TIMER_DEBUG_EN    0
#define TEST_DEBUG_EN     0  // 1
#define USE_OPTIMIZE_PRINTF 1
#define ALL_STRING_SAVE_IN_FLASH  1  

#define GIZ_CMD_TEST_EN    1    //  do not touch it !

#define CMD_CFGMODE_DEBUG_EN          1   // enable(1) cmd 0x09 debug info print
#define CMD_RESTARTWIFI_DEBUG_EN      1   // cmd 0x0b debug
#define CMD_DEVCURSTAREPORT_DEBUG_EN  1   // cmd 0x0d debug

typedef long int32;
typedef long int32_t;
typedef unsigned long INT32U;
typedef signed   long INT32S;
typedef unsigned char INT8U;
typedef signed char   INT8S;
typedef unsigned int  INT16U;
typedef signed int    INT16S;
	
typedef enum
{
   APP_SUCCESS = 0,
   APP_FAILED = 1,
   APP_NULL = 0xFF,
}E_RESULT;

typedef enum
{
   E_TRUE = 1,
   E_FALSE = 0,
}E_BOOL;

typedef enum
{
   OS_OK = 0,
   OS_ERROR = 1,
}OS_RESULT;



#endif
