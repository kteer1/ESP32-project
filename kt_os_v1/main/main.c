#include "main.h"
#include "driver/i2c_master.h"
void app_main(void)
{

    xTaskCreatePinnedToCore(KtOs_Init,"KtOs_Init",(1024*40),NULL,10,NULL,0);

    while(1)
    {
        vTaskDelay(1000/portTICK_PERIOD_MS);
        // ESP_LOGI("main","main ing....");
    }

}
