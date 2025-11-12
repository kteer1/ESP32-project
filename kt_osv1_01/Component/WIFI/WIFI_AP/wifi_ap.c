#include "wifi_ap.h"

#include <string.h>
#include "esp_mac.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "esp_log.h"

/** */
#define TAG_AP "kwifi_ap"

static wifi_config_t wifi_ap_config = {
        .ap = {
            .ssid = EXAMPLE_ESP_WIFI_AP_SSID,
            .channel = EXAMPLE_ESP_WIFI_CHANNEL,
            .password = EXAMPLE_ESP_WIFI_AP_PASSWD,
            .max_connection = EXAMPLE_MAX_STA_CONN,
            .authmode = WIFI_AUTH_WPA2_PSK,
            .pmf_cfg = {
                .required = false,
            },
        },
    };

void kWifiAp_Init(void* param)
{
    //创建
    esp_netif_t *fesp_netif_ap = esp_netif_create_default_wifi_ap();
    /** 重新定义名称长度*/
    wifi_ap_config.ap.ssid_len = strlen((const char*)wifi_ap_config.ap.ssid);
    /**判断密码是否为空 */
    if (strlen((const char*)wifi_ap_config.ap.password) == 0) {
        wifi_ap_config.ap.authmode = WIFI_AUTH_OPEN;
    }
    /**配置wifi ap 参数 */
    
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &wifi_ap_config));
    ESP_LOGI(TAG_AP, "wifi_init_softap finished. SSID:%s password:%s channel:%d",
             wifi_ap_config.ap.ssid, wifi_ap_config.ap.password, wifi_ap_config.ap.channel);

    if(param != NULL)
    {
        param = fesp_netif_ap;
    }
    return ;
}
