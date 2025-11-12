#include "imu_porting.h"
#include "driver/i2c_master.h"
#include "esp_log.h"
#include "../drive/QMI8658C/qmi8658c.h"

static void qmi8658c_transmit(qmi8658_io_panel_t *panel,const sensor_cmd_t* sensor_cmd);
static void qmi8658c_transmit_receive(qmi8658_io_panel_t *panel,const  sensor_cmd_t* sensor_cmd);

// sensor_panel_t* qmi8568c_panel;
/**------------------- */
sensor_panel_t* IMUporting_Init(void* param)
{
    
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
        .device_address = QMI8658C_ADDRESS,
        .scl_speed_hz = QMI8658C_CLK_SPEED,
    };

    
    
    i2c_master_dev_handle_t dev_handle;
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle));
    
    
    // uint8_t imu_id=0,imu_rev=0;
    // i2c_master_bus_wait_all_done(bus_handle,-1);
    // i2c_master_transmit_receive(dev_handle,(uint8_t[]){QMI8658C_REG_WHO_AM_I},1,&imu_id,1,-1);
    // i2c_master_transmit_receive(dev_handle,(uint8_t[]){QMI8658C_REG_REVISION_ID},1,&imu_rev,1,-1);
    // ESP_LOGI("imu_porting","imu_id=%d,imu_rev=%d",imu_id,imu_rev);


    /**获取IMU API 函数 */
    qmi8658_io_panel_t panel = {
        .address = QMI8658C_ADDRESS,
        .transmit = qmi8658c_transmit,
        .transmit_receive = qmi8658c_transmit_receive,
        .user_data = dev_handle,
    };
    ESP_LOGI("imu_porting","qmi8658 init...");
    if(param!=NULL)
    {
        ESP_LOGI("imu_porting","param != NULL");
    }
    return  qmi8658c_init(&panel);

}


static void qmi8658c_transmit(qmi8658_io_panel_t *panel,const sensor_cmd_t* sensor_cmd)
{
    i2c_master_transmit((i2c_master_dev_handle_t)panel->user_data,sensor_cmd->cmd,sensor_cmd->cmd_bytes,sensor_cmd->delay_ms);
}

static void qmi8658c_transmit_receive(qmi8658_io_panel_t *panel,const sensor_cmd_t* sensor_cmd)
{

    i2c_master_transmit_receive((i2c_master_dev_handle_t)panel->user_data,sensor_cmd->cmd,sensor_cmd->cmd_bytes,sensor_cmd->data,sensor_cmd->data_bytes,sensor_cmd->delay_ms);
}