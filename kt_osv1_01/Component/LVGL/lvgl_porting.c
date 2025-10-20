#include "lvgl_porting.h"

#include "esp_log.h"
// #include "esp_driver_i2c/i2c_private.h"

#include "driver/i2c_types.h"
#include "driver/i2c_master.h"
#include "driver/spi_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"

#include "lvgl/lvgl.h"
#include "drive/Disp/SH8601/esp_lcd_sh8601.h"
#include "drive/Touch/FT5x06/ft5x06.h"



static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p);
static bool example_spi_notify_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx);
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static void Touch_DevInit(void* param);

static void example_disp_init(void* param);
static void example_disp_set_onoff(void* param,unsigned char fbit);

static char* TAG ="lvgl_porting";
/**SH8601 初始化命令 */
static const sh8601_lcd_init_cmd_t lcd_init_cmds[] = {
    {0x11, (uint8_t[]){0x00}, 0, 120},/**退出睡眠模式 */
    {0x44, (uint8_t[]){0x01, 0xD1}, 2, 0},
    {0x35, (uint8_t[]){0x00}, 1, 0},
    {0x53, (uint8_t[]){0x20}, 1, 10},
    {0x2A, (uint8_t[]){0x00, 0x00, 0x01, 0x6F}, 4, 0},/**定义列地址集(0x0000 ~ 0x016F) */
    {0x2B, (uint8_t[]){0x00, 0x00, 0x01, 0xBF}, 4, 0},/**定义行地址集(0x0000 ~ 0x01BF) */
    {0x51, (uint8_t[]){0x00}, 1, 10},
    {0x29, (uint8_t[]){0x00}, 0, 10},
    {0x51, (uint8_t[]){0x7F}, 1, 0},/**写入亮度 */
};

// lvgl_porting_t lvgl_cfg_t={0};

void lvgl_porting_init(void* param)
{
    lvgl_porting_t* lvgl_cfg_t = (lvgl_porting_t*)param;
    /**lvgl disp 配置 */
    static lv_disp_draw_buf_t draw_buf_dsc_2;
    static lv_color_t buf_2_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];                        /*A buffer for 10 rows*/
    static lv_color_t buf_2_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];                        /*An other buffer for 10 rows*/
    lv_disp_draw_buf_init(&draw_buf_dsc_2, buf_2_1, buf_2_2, MY_DISP_HOR_RES * MY_DISP_VER_RES);   /*Initialize the display buffer*/
    static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/
    /*Set the resolution of the display*/
    disp_drv.hor_res = EXAMPLE_LCD_H_RES;
    disp_drv.ver_res = EXAMPLE_LCD_V_RES;
    /*Used to copy the buffer's content to the display*/
    // disp_drv.user_data = fstruct_config;
    disp_drv.flush_cb = disp_flush;
    /*Set a display buffer*/
    disp_drv.draw_buf = &draw_buf_dsc_2;
    /*Finally register the driver*/
    // lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv={0};
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    
    indev_drv.read_cb = touchpad_read;
    

    /**初始化 SPI 配置 */
    const spi_bus_config_t buscfg = SH8601_PANEL_BUS_QSPI_CONFIG(EXAMPLE_PIN_NUM_LCD_PCLK,
                                                                 EXAMPLE_PIN_NUM_LCD_DATA0,
                                                                 EXAMPLE_PIN_NUM_LCD_DATA1,
                                                                 EXAMPLE_PIN_NUM_LCD_DATA2,
                                                                 EXAMPLE_PIN_NUM_LCD_DATA3,
                                                                 EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES * LCD_BIT_PER_PIXEL / 8);
    ESP_ERROR_CHECK(spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO));//初始化


    /**lcd 配置 */
    esp_lcd_panel_io_handle_t io_handle = NULL;
    const esp_lcd_panel_io_spi_config_t io_config = SH8601_PANEL_IO_QSPI_CONFIG(EXAMPLE_PIN_NUM_LCD_CS,
                                                                                example_spi_notify_ready,
                                                                                    &disp_drv);

                                                                                    /**SH8601 初始命令属性 */
    sh8601_vendor_config_t vendor_config = {
        .init_cmds = lcd_init_cmds,
        .init_cmds_size = sizeof(lcd_init_cmds) / sizeof(lcd_init_cmds[0]),
        .flags = {
            .use_qspi_interface = 1,
        },
    }; 
    // Attach the LCD to the SPI bus
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &io_config, &io_handle));
    
    /** */
    esp_lcd_panel_handle_t panel_handle = NULL;
    const esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = EXAMPLE_PIN_NUM_LCD_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_RGB,
        .bits_per_pixel = LCD_BIT_PER_PIXEL,
        .vendor_config = &vendor_config,
    };
    ESP_LOGI(TAG, "Install SH8601 panel driver");
    ESP_ERROR_CHECK(esp_lcd_new_panel_sh8601(io_handle, &panel_config, &panel_handle));

    
    ESP_LOGI(TAG, "Install SH8601 panel driver finishing....");


    /**其他地方 已经初始化了总线  */
    #if 0
        i2c_master_bus_config_t i2c_mst_config = {
            .clk_source = I2C_CLK_SRC_DEFAULT,
            .i2c_port = I2C_NUM_0,
            .scl_io_num = Expander_IIC_SCL,
            .sda_io_num = Expander_IIC_SDA,
            .glitch_ignore_cnt = 7,
            .flags.enable_internal_pullup = 1,
        };
        i2c_master_bus_handle_t bus_handle;
        ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));
    #endif
    /**获取句柄 */
    i2c_master_bus_handle_t bus_handle;

    ESP_ERROR_CHECK(i2c_master_get_bus_handle(I2C_NUM_0, &bus_handle));

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = Touch_IIC_Address,
        .scl_speed_hz = IIC_DEV01_CLK_SPEED,
    };
    static i2c_master_dev_handle_t dev_handle;
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle));
    
    /** 各句柄的关联 */
    lvgl_cfg_t->user_pandel = panel_handle;
    disp_drv.user_data = panel_handle;/** disp_drv 空指针指向 panel_handle ，方便在 disp_flush 调用*/
    lv_disp_drv_register(&disp_drv);

    esp_lcd_panel_init(panel_handle);
    esp_lcd_panel_disp_on_off(panel_handle,true);

    indev_drv.user_data = dev_handle;
    lv_indev_drv_register(&indev_drv);
    Touch_DevInit(indev_drv.user_data);

    /** 参数保存 */
    lvgl_cfg_t->init = example_disp_init;
    lvgl_cfg_t->set_disp_onoff = example_disp_set_onoff;
}

/**lvgl disp 的显示刷新回调事件 */
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    esp_lcd_panel_handle_t fstruct_config = (esp_lcd_panel_handle_t)(disp_drv->user_data);
    esp_lcd_panel_draw_bitmap((fstruct_config), area->x1, area->y1, area->x2 + 1,area->y2 + 1, color_p);
}
/**ESP spi 完成传输的回调事件 */
static bool example_spi_notify_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    /**提示spi传输数据已完成 */
    lv_disp_flush_ready((lv_disp_drv_t*)user_ctx);
    return false;
}

static void Touch_DevInit(void* param)
{
    esp_err_t ret = ESP_OK;
    i2c_master_dev_handle_t fstruct_dev = (i2c_master_dev_handle_t)param;


    ESP_LOGI(TAG,"Touch_DevInit...");
    do{
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_THGROUP, 70},2,-1);// Valid touching detect threshold
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_THPEAK, 60},2,-1);// valid touching peak detect threshold
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_THCAL, 16},2,-1);// Touch focus threshold
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_THWATER, 60},2,-1);// threshold when there is surface water
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_THTEMP, 10},2,-1);// threshold of temperature compensation
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_THDIFF, 20},2,-1);// Touch difference threshold
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_TIME_ENTER_MONITOR, 2},2,-1);// Delay to enter 'Monitor' status (s)
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_PERIODACTIVE, 12},2,-1);// Period of 'Active' status (ms)
            ret = i2c_master_transmit(fstruct_dev, (uint8_t[]){FT5x06_ID_G_PERIODMONITOR, 40},2,-1);// Timer to enter 'idle' when in 'Monitor' (ms)
            if(ret != ESP_OK)
            {
                vTaskDelay(10/portTICK_PERIOD_MS);
            }
    }while(ret);
    


}

/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{

    i2c_master_dev_handle_t fstruct_dev = (i2c_master_dev_handle_t)(indev_drv->user_data);
    unsigned int tp_x=0;
    unsigned int tp_y=0;
    unsigned char tp_cnt=0;
    unsigned char tp_press = 0;  
    /**获取 触摸点数 触摸点的坐标 */
    uint8_t f_points_data[4];
    /**读取点数 */
    i2c_master_transmit_receive(fstruct_dev,(uint8_t[]){FT5x06_TOUCH_POINTS},1,&tp_cnt,1,-1);
    i2c_master_transmit_receive(fstruct_dev,(uint8_t[]){FT5x06_TOUCH1_XH},1,f_points_data,4,-1);
    (tp_x) = (((uint16_t)f_points_data[0] & 0x0f) << 8) + f_points_data[1];
    (tp_y) = (((uint16_t)f_points_data[2] & 0x0f) << 8) + f_points_data[3];
    if(tp_cnt>0)
    {
        (tp_press) = 1;
    }
    else{
        (tp_press) = 0;
    }
    // ESP_LOGI("lvgl_porting","tp_x=%d\ttp_y=%d\ttp_cnt=%d\ttp_press=%d",tp_x,tp_y,tp_cnt,tp_press);
    if(tp_press && (tp_cnt>0))
    {
        data->point.x = tp_x;
        data->point.y = tp_y;
        data->state = LV_INDEV_STATE_PR;
    }
    else{
        data->state = LV_INDEV_STATE_REL;
    }
}
/** example */
static void example_disp_init(void* param)
{
    esp_lcd_panel_handle_t fstruct = (esp_lcd_panel_handle_t)param;
    esp_lcd_panel_init(fstruct);
}

static void example_disp_set_onoff(void* param,unsigned char fbit)
{
    esp_lcd_panel_handle_t fstruct = (esp_lcd_panel_handle_t)param;
    esp_lcd_panel_disp_on_off(fstruct,(bool)fbit);
}
