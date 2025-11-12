#include "qmi8658c.h"



typedef struct{
    sensor_panel_t drive;
    qmi8658_io_panel_t io_panel;

}qmi8658c_panel_t;


/**================================================================ */
static void qmi8658c_panel_init(sensor_panel_t* panel);
static void qmi8658c_panel_reset(sensor_panel_t* panel);
static void qmi8658c_panel_del(sensor_panel_t* panel);
static void qmi8658c_panel_transmit(sensor_panel_t *panel,const sensor_cmd_t* sensor_cmd);
static void qmi8658c_panel_transmit_receive(sensor_panel_t *panel,const sensor_cmd_t* sensor_cmd);

/**================================================================ */
sensor_panel_t* qmi8658c_init(qmi8658_io_panel_t* io_panel)
{
    /*分配*/
    qmi8658c_panel_t* qmi8658c = (qmi8658c_panel_t*)calloc(1,sizeof(qmi8658c_panel_t));

    /**获取接口API */
    qmi8658c->drive.init = qmi8658c_panel_init;
    qmi8658c->drive.reset = qmi8658c_panel_reset;
    qmi8658c->drive.del = qmi8658c_panel_del;
    qmi8658c->drive.transmit = qmi8658c_panel_transmit;
    qmi8658c->drive.transmit_receive = qmi8658c_panel_transmit_receive;

    qmi8658c->io_panel.transmit = io_panel->transmit;
    qmi8658c->io_panel.transmit_receive = io_panel->transmit_receive;
    qmi8658c->io_panel.user_data = io_panel->user_data;
    
    /**获取 */
    return  &qmi8658c->drive;
}

static void qmi8658c_panel_init(sensor_panel_t* panel)
{
    /*获取*/
    qmi8658c_panel_t *qmi8658c = container_of(panel, qmi8658c_panel_t, drive);
    sensor_cmd_t qmi8658c_cmd[QMI8658C_CMD_NUM] = QMI8658C_SetReg_Define();

    uint8_t i;
    for(i=0;i<QMI8658C_CMD_NUM;i++)
    {
        qmi8658c->io_panel.transmit(&qmi8658c->io_panel,&qmi8658c_cmd[i]);
        if(i==0)
        {
            vTaskDelay(10/portTICK_PERIOD_MS);
        }
    }
}
static void qmi8658c_panel_reset(sensor_panel_t* panel)
{
    /*获取*/
    // qmi8658c_panel_t *qmi8658c = container_of(panel, qmi8658c_panel_t, drive);
}
static void qmi8658c_panel_del(sensor_panel_t* panel)
{
    /*获取*/
    qmi8658c_panel_t *qmi8658c = container_of(panel, qmi8658c_panel_t, drive);
    free(qmi8658c);/**释放 */
}

static void qmi8658c_panel_transmit(sensor_panel_t *panel,const sensor_cmd_t* sensor_cmd)
{
    /*获取*/
    qmi8658c_panel_t *qmi8658c = container_of(panel, qmi8658c_panel_t, drive);
    qmi8658c->io_panel.transmit(&qmi8658c->io_panel,sensor_cmd);
}

static void qmi8658c_panel_transmit_receive(sensor_panel_t *panel,const sensor_cmd_t* sensor_cmd)
{
    /*获取*/
    qmi8658c_panel_t *qmi8658c = container_of(panel, qmi8658c_panel_t, drive);
    qmi8658c->io_panel.transmit_receive(&qmi8658c->io_panel,sensor_cmd);
}