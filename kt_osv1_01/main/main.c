#include <stdio.h>
#include "main.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"

void app_bspinit(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
}



void app_main(void)
{
    container_of();
    vTaskDelay(200/portTICK_PERIOD_MS);
    app_bspinit();
    IOExpander_Init();
    xTaskCreatePinnedToCore(lvgl_app,"lvgl_app",(1024*20),NULL,10,NULL,0);
    IMUporting_Init();
    while(1)
    {
        vTaskDelay(1000/portTICK_PERIOD_MS);
        ESP_LOGI("main","main ing....");
    }
}
