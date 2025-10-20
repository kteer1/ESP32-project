#include "io_expander.h"
#include "driver/i2c_master.h"
#include "bsp/TCA9554/tca9554.h"


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"



void IOExpander_Init(void)
{
    esp_err_t ret;
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

    /**把从机 挂载到Master 总线上 */
    i2c_device_config_t dev01_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = TCA9554_ADDRESS,
        .scl_speed_hz = TCA9554_CLK_SPEED,
    };
    // /**获取句柄 */
    // i2c_master_bus_handle_t bus_handle;
    // ESP_ERROR_CHECK(i2c_master_get_bus_handle(I2C_NUM_0, &bus_handle));

    i2c_master_dev_handle_t expander_dev_handle;
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev01_cfg, &expander_dev_handle));


    ret = i2c_master_transmit(expander_dev_handle, (unsigned char[]){DIRECTION_REG_ADDR,0x07},2, -1);
    ESP_LOGI("io_expander","ret : %d",ret);
    i2c_master_transmit(expander_dev_handle, (unsigned char[]){OUTPUT_REG_ADDR,0x00},2, -1);
    ESP_LOGI("io_expander","ret : %d",ret);
    vTaskDelay(100/portTICK_PERIOD_MS);

    i2c_master_transmit(expander_dev_handle, (unsigned char[]){OUTPUT_REG_ADDR,0x07},2, -1);
    ESP_LOGI("io_expander","ret : %d",ret);
    vTaskDelay(100/portTICK_PERIOD_MS);
}
