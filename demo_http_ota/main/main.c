#include "main.h"

static char* TAG = "app_main";

void app_main(void)
{
    while (1)
    {
        /* code */
        ESP_LOGI(TAG,"hello word!");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
    
}
