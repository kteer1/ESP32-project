#include "button.h"
#include "button_conf.h"
#include "./porting/porting.h"

static void Button_Scan(void*param);

void Button_TaskHandle(void*param)
{
    button_conf_t* button01_t = (button_conf_t*)calloc(1,sizeof(button_conf_t));
    porting_init(button01_t);

    while(1)
    {
        vTaskDelay(10/portTICK_PERIOD_MS);
        Button_Scan(button01_t);
    }
    free(button01_t);
}

static void Button_Scan(void*param)
{
    button_conf_t* ftruct = (button_conf_t*)param;

    ftruct->read_bit(ftruct);
    if(ftruct->level == Button_False)
    {
        if(ftruct->relax_count > BUTTON_RELAX_ONCE_COUNT)
        {
            if(ftruct->press_count_last >= BUTTON_PRESS_ONCE_COUNT)
            {
                ftruct->state = (ftruct->state | BUTTON_STATE_PRESS_ONCE);
                if(ftruct->state&BUTTON_STATE_PRESS_ONCE)
                {
                    ftruct->state&=(~BUTTON_STATE_PRESS_ONCE);
                    ESP_LOGI("Button","Once press");
                }
                ftruct->press_count_last=0;
            }
            
        }
        else{
            ftruct->relax_count++;
            if(ftruct->relax_count == BUTTON_RELAX_SHAKE)
            {
                ftruct->press_count_last = ftruct->press_count;
                ftruct->press_count = 0;
            }
        }
    }
    else{
        if(ftruct->press_count > BUTTON_PRESS_ONCE_COUNT)
        {
            
        }
        else{
            ftruct->press_count++;
            if(ftruct->press_count > BUTTON_PRESS_SHAKE)
            {
                ftruct->relax_count = 0;
            }
        }
    }
    


}

