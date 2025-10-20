#include "kt_os.h"
#include "kt_os_drive.h"

#include "ui/ui.h"
#include "src/sensor/io_expander/bsp/tca9554/tca9554.h"

tca9554_port_t tca9554_cfg_s={0};

void KtOs_Init(void* param)
{
    eIIC_Master01(NULL);
    eIIC_Dev01Init(&tca9554_cfg_s);
    unsigned char tca9554_data = 0;
    tca9554_cfg_s.send_data_list(tca9554_cfg_s.user_panel,(unsigned char[]){DIRECTION_REG_ADDR,0x07},2);/**配置io口方向 */
    tca9554_cfg_s.send_data_list(tca9554_cfg_s.user_panel,(unsigned char[]){OUTPUT_REG_ADDR,0x00},2);
    vTaskDelay(100/portTICK_PERIOD_MS);
    tca9554_cfg_s.send_data_list(tca9554_cfg_s.user_panel,(unsigned char[]){OUTPUT_REG_ADDR,0x07},2);
    tca9554_cfg_s.send_receive(tca9554_cfg_s.user_panel,(unsigned char[]){OUTPUT_REG_ADDR},1,&tca9554_data,1);
    ESP_LOGI("KT_OS","TCA9554 Receive Data : %d",tca9554_data);
    vTaskDelay(100/portTICK_PERIOD_MS);
    xTaskCreatePinnedToCore(UI_Task,"UI_Task",(1024*20),NULL,10,NULL,0);


    while(1)
    {
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }

}

