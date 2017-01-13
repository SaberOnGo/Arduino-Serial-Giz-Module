
#ifndef __DS18B20_DRV_H__
#define  __DS18B20_DRV_H__

//#include "giz_includes.h"
//#include "Arduino.h"
#include "GlobalDef.h"
//#include "GlobalFunc.h"

#define TEMP_DEBUG_EN



#define DS18B20_IO_PIN  12   // D12

#endif


E_RESULT DS18B20_GetTemperature(float * outTemp);
void DS18B20_Init(void);


