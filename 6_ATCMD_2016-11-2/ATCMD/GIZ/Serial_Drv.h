
#ifndef __SERIAL_DRV_H__
#define  __SERIAL_DRV_H__

//#include "giz_includes.h"
#include "Arduino.h"
#include <stdarg.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include "string.h"
#include "GlobalDef.h"
#include "tfp_printf.h"



#define SOFT_RX_PIN  10  //  D10, name on hardware board 
#define SOFT_TX_PIN  11  // D11,

#define SOFT_UART_EN   1   //  软件串口使能, 调试打印, 
#define SW_PRINTF_EN   0   //1: 使用stdio.h 中的printf;  0: 使用 tfp_printf


#define  os_memset(src, c, len)   memset(src, c, len)
#define  os_strncpy(dsc, src, len)  strncpy((char *)dsc, (const char *)src, len)
#define  os_strlen(str)   strlen((char *)str)
#define  os_memcpy(dsc, src, len)       memcpy(dsc, src, len)


typedef void (*ATCMD_RxProcessFunc)(uint8_t *data, int32_t len);


void SerialDrv_UartSend(char *data);
void SerialDrv_Print(char *data);
void SerialDrv_PrintHex(char c);
void SerialDrv_Println(char *data);
void SerialDrv_Task(ATCMD_RxProcessFunc AtCmdRxProcessFunc);

void FLASH_SAVE  SerialDrv_Init(ATCMD_RxProcessFunc func);
void FLASH_SAVE SerialDrv_SetRxCompleteBool(E_BOOL isComplete);

#define at_port_print(str)   SerialDrv_UartSend((char *)str)

#if SW_PRINTF_EN
#define os_printf printf
#else

#if USE_OPTIMIZE_PRINTF
#define os_printf(fmt, ...)  do {\
    int len = 0, i;\
    char readChar = 0;\
	static const char flash_str[] PROGMEM  = fmt;\
	char buf[128];\
	len = strlen_P(flash_str);\
	os_memset(buf, 0, sizeof(buf));\
	for(i = 0; i < len; i++)\
		{\
		readChar =  pgm_read_byte_near(flash_str + i);\
		buf[i] = readChar;\
		}\
		tfp_printf(buf, ##__VA_ARGS__);\
		} while(0)
#else
#define os_printf	tfp_printf
#endif

#endif

#if SERIAL_DEBUG_EN
#define SERIAL_DEBUG  os_printf
#else
#define SERIAL_DEBUG(...)
#endif

#endif

