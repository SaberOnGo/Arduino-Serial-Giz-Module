
#ifndef __DS18B20_DRV_H__
#define  __DS18B20_DRV_H__

#include "giz_includes.h"

#define TEMP_DEBUG_EN

#ifdef  TEMP_DEBUG_EN
#define TEMP_DEBUG   os_printf  // to call this functon must init software serial
#else
#define TEMP_DEBUG(...) 
#endif

#define DS18B20_IO_PIN  12   // D12

#endif


E_RESULT DS18B20_GetTemperature(float * outTemp);
void DS18B20_Init(void);


