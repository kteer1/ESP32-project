#include "main.h"

static char* TAG = "app_main";

void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    xTaskCreatePinnedToCore(WIFIDrive_TASK,"WIFIDrive_TASK",(1024*4),NULL,10,NULL,0);
    while (1)
    {
        /* code */
        /**这是主函数里 */
        ESP_LOGI(TAG,"hello word!");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    
}
