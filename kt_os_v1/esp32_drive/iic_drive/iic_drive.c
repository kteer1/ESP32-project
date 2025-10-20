#include "iic_drive.h"
#include "driver/i2c_master.h"
#include "iic_drive_type.h"
#include "esp_log.h"

#include "../../kt_os/src/sensor/io_expander/bsp/tca9554/tca9554.h"


static void dev01_send_data_list(void* param,void* buf_p,unsigned int buf_len);
static void dev01_receive(void* param,void* buf_p,unsigned int buf_len);
static void dev01_send_receive(void* param,void* send_buf,unsigned int send_buf_len,void* rec_buf,unsigned int rec_buf_len);

void eIIC_Master01(void* param)
{
    i2c_master_bus_config_t i2c_mst_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = IIC_MASTER01_HOST,
        .scl_io_num = IIC_MASTER01_SCL,
        .sda_io_num = IIC_MASTER01_SDA,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = 1,
    };
    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));

    // esp_err_t ret=0xff;
    // ret = i2c_master_probe(bus_handle, 0x38, -1);
    // ESP_LOGI("main","ret : %d",ret);

    // ret=0xff;
    // ret = i2c_master_probe(bus_handle, 0x30, -1);
    // ESP_LOGI("main","ret : %d",ret);
}

void eIIC_Dev01Init(void*param)
{
    tca9554_port_t* fstruct_cfg_t = (tca9554_port_t*) param;
    /**把从机 挂载到Master 总线上 */
    i2c_device_config_t dev01_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = IIC_MASTER01_DEV_IOExpander_Address,
        .scl_speed_hz = IIC_MASTER01_CLK_SPEED,
    };

    /**获取句柄 */
    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_master_get_bus_handle(IIC_MASTER01_HOST, &bus_handle));

    i2c_master_dev_handle_t dev01_handle;
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev01_cfg, &dev01_handle));


    fstruct_cfg_t->user_panel = dev01_handle;
    fstruct_cfg_t->send_data_list = dev01_send_data_list;
    fstruct_cfg_t->receive = dev01_receive;
    fstruct_cfg_t->send_receive = dev01_send_receive;
}


static void dev01_send_data_list(void* param,void* buf_p,unsigned int buf_len)
{
    i2c_master_dev_handle_t fstruct_dev = (i2c_master_dev_handle_t)param;
    i2c_master_transmit(fstruct_dev, buf_p, buf_len, -1);
}
static void dev01_receive(void* param,void* buf_p,unsigned int buf_len)
{
    i2c_master_dev_handle_t fstruct_dev = (i2c_master_dev_handle_t)param;
    i2c_master_receive(fstruct_dev, buf_p, buf_len, -1);
}
static void dev01_send_receive(void* param,void* send_buf,unsigned int send_buf_len,void* rec_buf,unsigned int rec_buf_len)
{
    i2c_master_dev_handle_t fstruct_dev = (i2c_master_dev_handle_t)param;
    ESP_ERROR_CHECK(i2c_master_transmit_receive(fstruct_dev, send_buf, send_buf_len, rec_buf, rec_buf_len, -1));
}


