#include "imu.h"
#include "porting/imu_porting.h"
#include "./drive/QMI8658C/qmi8658c.h"
#include "imu_bsp.h"


typedef struct{
    uint8_t id;
    uint32_t state;

    sensor_panel_t* panel;
}Sensor_qmi8658c_t;


static void IMU_QMI8658TaskHandle(void*param);
static void QMI8658C_ReadID(void*param);
static void QMI8658C_ReadStatus(void*param);
sensor_panel_t* qmi8568c_panel;
void imu_init(void*param)
{
    qmi8568c_panel = IMUporting_Init(NULL);
    xTaskCreatePinnedToCore(IMU_QMI8658TaskHandle,"IMU_QMI8658TaskHandle",(1024*10),NULL,10,NULL,0);
}



static void IMU_QMI8658TaskHandle(void*param)
{
    Sensor_qmi8658c_t* qmi8658c_data_t = calloc(1,sizeof(Sensor_qmi8658c_t));
    qmi8658c_data_t->panel = qmi8568c_panel;
    qmi8658c_data_t->panel->init(qmi8658c_data_t->panel);
    QMI8658C_ReadID(qmi8658c_data_t);
    while(1)
    {
        vTaskDelay(1000/portTICK_PERIOD_MS);
        QMI8658C_ReadStatus(qmi8658c_data_t);
    }
}

static void QMI8658C_ReadID(void*param)
{
    Sensor_qmi8658c_t* sensor_struct = (Sensor_qmi8658c_t*)param;
    sensor_cmd_t qmi8568_cmd_t={
        .cmd_state = 0,
        .cmd = NULL,
        .cmd_bytes=0,
        .data=NULL,
        .data_bytes=0,
        .delay_ms=100,
    };

    /**配置传输参数 */
    qmi8568_cmd_t.cmd_bytes = 1;
    unsigned char*qmi8658_cmd_data_list = calloc(qmi8568_cmd_t.cmd_bytes,sizeof(unsigned char));
    qmi8568_cmd_t.data_bytes = 2;
    unsigned char*qmi8658_data_data_list = calloc(qmi8568_cmd_t.data_bytes,sizeof(unsigned char));

    qmi8658_cmd_data_list[0] = QMI8658C_REG_WHO_AM_I;
    qmi8568_cmd_t.cmd = qmi8658_cmd_data_list;
    qmi8568_cmd_t.data = qmi8658_data_data_list;
    // /*传输读取寄存器数据*/
    sensor_struct->panel->transmit_receive(sensor_struct->panel,&qmi8568_cmd_t);
    ESP_LOGI("imu.h","QMI8658C_REG_WHO_AM_I=0x%02x,QMI8658C_REG_REVISION_ID=0x%02x",qmi8568_cmd_t.data[0],qmi8568_cmd_t.data[1]);
    sensor_struct->id = qmi8568_cmd_t.data[0];

    // /*清除*/
    free(qmi8658_cmd_data_list);
    free(qmi8658_data_data_list);
}

static void QMI8658C_ReadAccandGry(void*param)
{
    Sensor_qmi8658c_t* sensor_struct = (Sensor_qmi8658c_t*)param;
    sensor_cmd_t qmi8568_cmd_t={
        .cmd_state = 0,
        .cmd = NULL,
        .cmd_bytes=0,
        .data=NULL,
        .data_bytes=0,
        .delay_ms=100,
    };
    /**配置传输参数 */
    qmi8568_cmd_t.cmd_bytes = 1;
    unsigned char*qmi8658_cmd_data_list = calloc(qmi8568_cmd_t.cmd_bytes,sizeof(unsigned char));
    qmi8568_cmd_t.data_bytes = 12;
    unsigned char*qmi8658_data_data_list = calloc(qmi8568_cmd_t.data_bytes,sizeof(unsigned char));

    qmi8658_cmd_data_list[0] = QMI8658C_REG_STATUS0;
    qmi8568_cmd_t.cmd = qmi8658_cmd_data_list;
    qmi8568_cmd_t.data = qmi8658_data_data_list;
    /*传输读取寄存器数据*/
    sensor_struct->panel->transmit_receive(sensor_struct->panel,&qmi8568_cmd_t);
    










    // /*清除*/
    free(qmi8658_cmd_data_list);
    free(qmi8658_data_data_list);
}

// static void QMI8658C_Read