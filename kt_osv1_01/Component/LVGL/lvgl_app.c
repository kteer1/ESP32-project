#include "lvgl_app.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lvgl/lvgl.h"
#include "lvgl_porting.h"
#include "esp_timer.h"

static void lvgl_tick(void* param);


/**简单示例 */
void lvgl_demo(void)
{
     lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, 0);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);
}




void lvgl_app(void* param)
{
    lvgl_porting_t app_cfg;
    lv_init();
    lvgl_porting_init(&app_cfg);
    lvgl_demo();

    /**利用 ESP32 定时器 创造一个中断事件 */
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = lvgl_tick,
        .name = "lvgl_tick"
    };
    esp_timer_handle_t lvgl_tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, LVGL_TICK_INC * 1000));
    

    while(1)
    {
        lv_timer_handler();
        vTaskDelay(5/portTICK_PERIOD_MS);
        
    }
}



static void lvgl_tick(void* param)
{
    lv_tick_inc(LVGL_TICK_INC);
}