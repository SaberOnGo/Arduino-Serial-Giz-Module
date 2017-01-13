

#include "Arduino.h"
#include "GlobalFunc.h"

#include "DS18B20_Drv.h"
#include <OneWire.h>
#include "Os_timer.h"

OneWire  ds(DS18B20_IO_PIN);  // on pin 10 (a 4.7K resistor is necessary)

#ifdef  TEMP_DEBUG_EN
#define TEMP_DEBUG   os_printf  // to call this functon must init software serial
#else
#define TEMP_DEBUG(...) 
#endif


//to get temperature
// param out: *outTemp
// return: get temperature success or not: APP_SUCCESS, APP_FAILED
E_RESULT DS18B20_GetTemperature(float * outTemp)
{
   E_RESULT result = APP_FAILED;
   uint8_t addr[8];
   uint8_t i;
   uint8_t type_s = 0;
   uint8_t data[12];
   uint8_t present = 0;
   float celsius, fahrenheit;          // real temperature
   int32_t dwCelsius, dwFahrenheit;  // real temperature * 1000
   int16_t raw = 0;
   uint8_t cfg;
   	
   memset(addr, 0, sizeof(addr));
   if ( !ds.search(addr)) 
   {
	    TEMP_DEBUG("No more addresses\n");
	    ds.reset_search();
	    //delay(250);
	    return APP_FAILED;
  }

  TEMP_DEBUG("ROM = ");
  for(i = 0; i < 8; i++)
  {
     TEMP_DEBUG(" ");
	 TEMP_DEBUG("0x%x", addr[i]);
  }
  TEMP_DEBUG("\r\n");
  
  if (OneWire::crc8(addr, 7) != addr[7]) 
  {
      TEMP_DEBUG("CRC is not valid!\n");
      return APP_FAILED;
  }

  // the first ROM byte indicates which chip
  switch (addr[0]) 
  {
    case 0x10:
      TEMP_DEBUG("  Chip = DS18S20\n");  // or old DS1820
      type_s = 1;
      break;
    case 0x28:
      TEMP_DEBUG("  Chip = DS18B20\n");
      type_s = 0;
      break;
    case 0x22:
      TEMP_DEBUG("  Chip = DS1822\n");
      type_s = 0;
      break;
    default:
      TEMP_DEBUG("Device is not a DS18x20 family device\n");
      return APP_FAILED;
  } 

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  //delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

  TEMP_DEBUG("  Data = ");
  TEMP_DEBUG("0x%x ", present);
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
    TEMP_DEBUG("0x%x ", data[i]);
  }
  TEMP_DEBUG("\n");
  TEMP_DEBUG(" CRC=");
  TEMP_DEBUG("0x%x\n", OneWire::crc8(data, 8));

  // Convert the data to actual temperature
  // because the result is a 16 bit signed integer, it should
  // be stored to an "int16_t" type, which is always 16 bits
  // even when compiled on a 32 bit processor.
  raw = (data[1] << 8) | data[0];
  if (type_s) 
  {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) 
	{
       // "count remain" gives full 12 bit resolution
       raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } 
  else 
  {
    cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  fahrenheit = celsius * 1.8 + 32.0;

  dwCelsius = (int32_t)(celsius * 1000);
  dwFahrenheit = (int32_t)(fahrenheit * 1000);
  
  #if 1
  TEMP_DEBUG("  Temperature Celsius %d.%d  Fahrenheit %d.%d\n", dwCelsius / 1000, dwCelsius % 1000, 
               dwFahrenheit / 1000, dwFahrenheit % 1000);
  #else
  debug_print("  Temperature = ");
  debug_print(celsius);
  debug_print(" Celsius, ");
  debug_print(fahrenheit);
  debug_println(" Fahrenheit");
  #endif
  
  return APP_SUCCESS;
}

static os_timer_t tTempSensorTimer;
static void TempSensorTimer_CallBack(void *)
{
   TEMP_DEBUG("temp call back, tick = %d ms\n", Sys_GetRunTime());
   DS18B20_GetTemperature(NULL);
}

static void TempSensorManager(void)
{
    os_timer_disarm(&tTempSensorTimer);
	os_timer_setfn(&tTempSensorTimer, TempSensorTimer_CallBack, NULL);
	os_timer_arm(&tTempSensorTimer, 500, 1);
}

void DS18B20_Init(void)
{
   TempSensorManager();
}

