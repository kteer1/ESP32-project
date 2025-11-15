#include "porting.h"
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"

static void Get_Button01_Bit(void*param);

void porting_init(void*param)
{
    button_conf_t* fstruct = (button_conf_t*)param;

    // gpio_config_t* io_conf = (gpio_config_t*)calloc(1,sizeof(gpio_config_t));
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,       // 禁用中断，后面在开启
        .mode = GPIO_MODE_INPUT,              // 设置为输入模式
        .pin_bit_mask = (1 << GPIO_NUM_0),           // 要配置的GPIO引脚位掩码(1ULL<<GPIO_OUTPUT_IO_0)
        .pull_down_en = GPIO_PULLDOWN_DISABLE,// 禁用下拉电阻
        .pull_up_en = GPIO_PULLUP_DISABLE     // 禁用上拉电阻
    };
    gpio_config(&io_conf);

    fstruct->read_bit = Get_Button01_Bit;

    // free(gpio_cfg_t);
}


static void Get_Button01_Bit(void*param)
{
    button_conf_t* fstruct = (button_conf_t*)param;
    fstruct->level = gpio_get_level(GPIO_NUM_0);
}