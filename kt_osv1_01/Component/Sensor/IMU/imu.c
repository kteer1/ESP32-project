#include "imu.h"
#include "porting/imu_porting.h"
#include "./drive/QMI8658C/qmi8658c.h"
#include "imu_bsp.h"
#include <math.h> 

typedef int16_t imu_data_size;
typedef struct{
    uint8_t id;
    uint8_t state;
    imu_data_size acc_data[3];
    imu_data_size gry_data[3];
    
    float angle[3];

    sensor_panel_t* panel;
}Sensor_qmi8658c_t;


static void IMU_QMI8658TaskHandle(void*param);
static void QMI8658C_ReadAccandGry(void*param);
static void QMI8658C_AccCpmpute(void* param);
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
        vTaskDelay(1000/portTICK_PERIOD_MS);
        QMI8658C_ReadAccandGry(qmi8568c_panel);/**读加速度和陀螺仪 */
        // QMI8658C_AccCpmpute(qmi8568c_panel);/*利用加速度数据计算角度*/
    }
}


static void QMI8658C_ReadAccandGry(void*param)
{
    Sensor_qmi8658c_t* qmi8568c_panel = (Sensor_qmi8658c_t*)param;

    uint8_t* f_data_s = (uint8_t*)calloc(12,sizeof(uint8_t));
    // uint8_t f_data_s[12]={0};

    qmi8568c_panel->panel->transmit_receive(qmi8568c_panel->panel,(uint8_t[]){QMI8658C_REG_STATUS0},1,&qmi8568c_panel->state,1);
    ESP_LOGI("imu","QMI8658C_REG_STATUS0=0x%02x",qmi8568c_panel->state);

    if(qmi8568c_panel->state & 0x03)
    {
        /**读取 加速度 陀螺仪 数据 */
        qmi8568c_panel->panel->transmit_receive(qmi8568c_panel->panel,(uint8_t[]){QMI8658C_REG_AX_L},1,f_data_s,12);

        /**储存 */
        qmi8568c_panel->acc_data[0]=(imu_data_size)((uint16_t)(f_data_s[1]<<8)|(uint16_t)(f_data_s[0]));
        qmi8568c_panel->acc_data[1]=(imu_data_size)((uint16_t)(f_data_s[3]<<8)|(uint16_t)(f_data_s[2]));
        qmi8568c_panel->acc_data[2]=(imu_data_size)((uint16_t)(f_data_s[5]<<8)|(uint16_t)(f_data_s[4]));

        qmi8568c_panel->gry_data[0]=(imu_data_size)((uint16_t)(f_data_s[7]<<8)|(uint16_t)(f_data_s[6]));
        qmi8568c_panel->gry_data[1]=(imu_data_size)((uint16_t)(f_data_s[9]<<8)|(uint16_t)(f_data_s[8]));
        qmi8568c_panel->gry_data[2]=(imu_data_size)((uint16_t)(f_data_s[11]<<8)|(uint16_t)(f_data_s[10]));
        ESP_LOGI("imu","AX=%d,\tAY=%d,\tAZ=%d",qmi8568c_panel->acc_data[0],qmi8568c_panel->acc_data[1],qmi8568c_panel->acc_data[2]);
        ESP_LOGI("imu","GX=%d,\tGY=%d,\tGZ=%d",qmi8568c_panel->gry_data[0],qmi8568c_panel->gry_data[1],qmi8568c_panel->gry_data[2]);
        
        QMI8658C_AccCpmpute(qmi8568c_panel);/*利用加速度数据计算角度*/
    }
    free(f_data_s);
}

static void QMI8658C_AccCpmpute(void* param)
{
    Sensor_qmi8658c_t* qmi8568c_panel = (Sensor_qmi8658c_t*)param;
    float* f_data_s = (float*)calloc(3,sizeof(float));

    f_data_s[0] = qmi8568c_panel->acc_data[0]/8192.0f;//量程±4g,
    f_data_s[1] = qmi8568c_panel->acc_data[1]/8192.0f;
    f_data_s[2] = qmi8568c_panel->acc_data[2]/8192.0f;

    // 计算X轴角度(绕X轴旋转的俯仰角)
    qmi8568c_panel->angle[0] = atan2(f_data_s[1], sqrt(f_data_s[0] * f_data_s[0] + f_data_s[2] * f_data_s[2])) * 180.0f / (3.14f);
    
    // 计算Y轴角度(绕Y轴旋转的横滚角)
    qmi8568c_panel->angle[1] = atan2(-f_data_s[0], sqrt(f_data_s[1] * f_data_s[1] + f_data_s[2] * f_data_s[2])) * 180.0f / (3.14f);
    
    // Z轴角度需要结合磁力计或陀螺仪积分计算，这里简化处理
    qmi8568c_panel->angle[2] = atan2(sqrt(f_data_s[0] * f_data_s[0] + f_data_s[1] * f_data_s[1]), f_data_s[2]) * 180.0f / (3.14f);


    ESP_LOGI("imu","qmi8568c_panel->angle[0]=%.02f,qmi8568c_panel->angle[1]=%.02f,qmi8568c_panel->angle[2]=%.02f",qmi8568c_panel->angle[0],\
                                                                        qmi8568c_panel->angle[1],qmi8568c_panel->angle[2]);
    free(f_data_s);
}