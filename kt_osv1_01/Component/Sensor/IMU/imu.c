#include "imu.h"
#include "porting/imu_porting.h"
#include "./drive/QMI8658C/qmi8658c.h"
#include "imu_bsp.h"


typedef struct{
    uint8_t id;
    uint8_t state;
    uint16_t acc_data[3];
    uint16_t gry_data[3];
    sensor_panel_t* panel;
}Sensor_qmi8658c_t;


static void IMU_QMI8658TaskHandle(void*param);
static void QMI8658C_ReadAccandGry(void*param);
Sensor_qmi8658c_t qmi8658_cfg_t={0};
void imu_init(void*param)
{
    qmi8658_cfg_t.panel = IMUporting_Init(NULL);

    qmi8658_cfg_t.panel->reset(qmi8658_cfg_t.panel);
    vTaskDelay(20/portTICK_PERIOD_MS);
    qmi8658_cfg_t.panel->init(qmi8658_cfg_t.panel);

    // Sensor_qmi8658c_t s_qmi8658_t={0};
    // qmi8568c_panel->transmit_receive(qmi8568c_panel,(uint8_t[]){QMI8658C_REG_WHO_AM_I},1,&s_qmi8658_t.id,1);
    // ESP_LOGI("imu","QMI8658C_REG_WHO_AM_I=0x%02x",s_qmi8658_t.id);
    xTaskCreatePinnedToCore(IMU_QMI8658TaskHandle,"IMU_QMI8658TaskHandle",(1024*10),&qmi8658_cfg_t,10,NULL,0);
}



static void IMU_QMI8658TaskHandle(void*param)
{
    Sensor_qmi8658c_t* qmi8568c_panel = (Sensor_qmi8658c_t*)param;
    qmi8568c_panel->panel->transmit_receive(qmi8568c_panel->panel,(uint8_t[]){QMI8658C_REG_WHO_AM_I},1,&qmi8568c_panel->id,1);
    ESP_LOGI("imu","QMI8658C_REG_WHO_AM_I=0x%02x",qmi8568c_panel->id);
    while(1)
    {
        vTaskDelay(600/portTICK_PERIOD_MS);
        QMI8658C_ReadAccandGry(qmi8568c_panel);
    }
}


static void QMI8658C_ReadAccandGry(void*param)
{
    Sensor_qmi8658c_t* qmi8568c_panel = (Sensor_qmi8658c_t*)param;

    uint8_t f_data_s[12]={0};

    qmi8568c_panel->panel->transmit_receive(qmi8568c_panel->panel,(uint8_t[]){QMI8658C_REG_STATUS0},1,&qmi8568c_panel->state,1);
    ESP_LOGI("imu","QMI8658C_REG_STATUS0=0x%02x",qmi8568c_panel->state);

    if(qmi8568c_panel->state & 0x03)
    {
        qmi8568c_panel->panel->transmit_receive(qmi8568c_panel->panel,(uint8_t[]){QMI8658C_REG_AX_L},1,f_data_s,12);
        ESP_LOGI("imu","QMI8658C_REG_AX_L=0x%02x,QMI8658C_REG_AX_H=0x%02x",f_data_s[0],f_data_s[1]);
        ESP_LOGI("imu","QMI8658C_REG_AY_L=0x%02x,QMI8658C_REG_AY_H=0x%02x",f_data_s[2],f_data_s[3]);
        ESP_LOGI("imu","QMI8658C_REG_AZ_L=0x%02x,QMI8658C_REG_AZ_H=0x%02x",f_data_s[4],f_data_s[5]);
        
        ESP_LOGI("imu","QMI8658C_REG_GX_L=0x%02x,QMI8658C_REG_GX_H=0x%02x",f_data_s[6],f_data_s[7]);
        ESP_LOGI("imu","QMI8658C_REG_GY_L=0x%02x,QMI8658C_REG_GY_H=0x%02x",f_data_s[8],f_data_s[9]);
        ESP_LOGI("imu","QMI8658C_REG_GZ_L=0x%02x,QMI8658C_REG_GZ_H=0x%02x",f_data_s[10],f_data_s[11]);
    }

}