
#ifndef __WIFI_INTERFACE_H__
#define  __WIFI_INTERFACE_H__

#include "giz_includes.h"

#define NULL_MODE       0x00
#define STATION_MODE    0x01
#define SOFTAP_MODE     0x02
#define STATIONAP_MODE  0x03


enum {
    STATION_IDLE = 0,
    STATION_CONNECTING,
    STATION_WRONG_PASSWORD,
    STATION_NO_AP_FOUND,
    STATION_CONNECT_FAIL,
    STATION_GOT_IP,
};


uint8_t wifi_get_opmode(void);
E_BOOL wifi_station_set_config(void *config);
E_BOOL wifi_station_get_config(void *config);
E_BOOL wifi_station_get_config_default(void *config);
E_BOOL FLASH_SAVE my_wifi_is_config_mode_on(void);
E_BOOL FLASH_SAVE my_wifi_is_binding_on(void);
E_BOOL FLASH_SAVE my_wifi_is_connect_cloud(void);

uint8_t wifi_station_get_connect_status(void);
int8_t wifi_station_get_rssi(void);  // < 10, get rssi success, and return is the value, 31: failed


#endif

