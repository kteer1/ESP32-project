#ifndef ___kWIFI_DRIVE_H__
#define ___kWIFI_DRIVE_H__
#include <stdio.h>
#include <stdint.h>

#define EXAMPLE_ESP_WIFI_SSID      "KT_ESP_AP"
#define EXAMPLE_ESP_WIFI_PASS      "123456789"
#define EXAMPLE_ESP_WIFI_CHANNEL   1
#define EXAMPLE_MAX_STA_CONN       5


typedef struct __wifidrive_config_t{
    uint8_t status;

}wifidrive_config_t;


void WIFIDrive_TASK(void* param);

#endif // WIFI_DRIVE_H


