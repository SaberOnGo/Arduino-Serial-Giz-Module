
#include "WifiInterface.h"
#include "Arduino.h"

uint8_t wifi_get_opmode(void)
{
   static uint8_t i = 0;
   i++;if(i > 3) i = 0;
   return i;
}

E_BOOL wifi_station_set_config(void *config)
{
   return E_TRUE;
}

E_BOOL wifi_station_get_config(void *config)
{
   return E_TRUE;
}
E_BOOL wifi_station_get_config_default(void *config)
{
   return E_TRUE;
}

uint8_t wifi_station_get_connect_status(void)
{
   return STATION_IDLE;
}
int8_t wifi_station_get_rssi(void)
{
   return 7;
}

E_BOOL FLASH_SAVE my_wifi_is_config_mode_on(void)
{
   E_BOOL result = E_FALSE;

   if(E_TRUE == wifi_station_get_config(NULL))result = E_TRUE;
   if(E_TRUE == wifi_station_get_config_default(NULL))result = E_TRUE;

   return result;
}

E_BOOL FLASH_SAVE my_wifi_is_binding_on(void)
{
   return E_FALSE;
}

E_BOOL FLASH_SAVE my_wifi_is_connect_cloud(void)
{
   return E_FALSE;
}

