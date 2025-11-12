#ifndef ___kQMI8658A_H__
#define ___kQMI8658A_H__

#include "../../imu_bsp.h"

#define QMI8658C_ADDRESS                    (0x6B)
#define QMI8658C_CLK_SPEED                  (200000)

/** Register Address  */
#define QMI8658C_REG_WHO_AM_I                (0x00)/*Device Identifier    (0x05)*/
#define QMI8658C_REG_REVISION_ID             (0x01)/*Device Revision ID */

#define QMI8658C_REG_CTRL1                   (0x02)/*SPI Interface and Sensor Enable */
#define QMI8658C_REG_CTRL2                   (0x03)/*Accelerometer: Output Data Rate, Full Scale, Self-Test*/
#define QMI8658C_REG_CTRL3                   (0x04)/*Gyroscope: Output Data Rate, Full Scale, Self-Test */
#define QMI8658C_REG_CTRL5                   (0x06)/*Low pass filter setting */
#define QMI8658C_REG_CTRL7                   (0x08)/*Enable Sensors */
#define QMI8658C_REG_CTRL8                   (0x09)/*Motion Detection Control */
#define QMI8658C_REG_CTRL9                   (0x0A)/*Host Commands */
/**Calibration Register */
#define QMI8658C_REG_CAL1_L                  (0x0B)/*CAL1_L – lower 8 bits. */
#define QMI8658C_REG_CAL1_H                  (0x0C)/*CAL1_H – upper 8 bits.*/
#define QMI8658C_REG_CAL2_L                  (0x0D)/*CAL2_L – lower 8 bits. */
#define QMI8658C_REG_CAL2_H                  (0x0E)/*CAL2_H – upper 8 bits. */
#define QMI8658C_REG_CAL3_L                  (0x0F)/*CAL3_L – lower 8 bits.*/
#define QMI8658C_REG_CAL3_H                  (0x10)/*CAL3_H – upper 8 bits.*/
#define QMI8658C_REG_CAL4_L                  (0x11)/*CAL4_L – lower 8 bits.*/
#define QMI8658C_REG_CAL4_H                  (0x12)/*CAL4_H – upper 8 bits. */
/*FIFO Registers */
#define QMI8658C_REG_FIFO_WTM_TH             (0x13)/*FIFO watermark level, in ODRs */
#define QMI8658C_REG_FIFO_CTRL               (0x14)/*FIFO Setup */
#define QMI8658C_REG_FIFO_SMPL_CNT           (0x15)/*FIFO sample count LSBs */
#define QMI8658C_REG_FIFO_STATUS             (0x16)/*FIFO Status */
#define QMI8658C_REG_FIFO_DATA               (0x17)/*FIFO Data */
/*Status Registers */
#define QMI8658C_REG_STATUSINT               (0x2D)/*Sensor Data Availability with the Locking mechanism, CmdDone (CTRL9 protocol bit).*/
#define QMI8658C_REG_STATUS0                 (0x2E)/*Output Data Over Run and Data Availability.*/
#define QMI8658C_REG_STATUS1                 (0x2F)/*Miscellaneous Status: Any Motion, No Motion, Significant Motion, Pedometer, Tap.*/
/*Timestamp Register*/
#define QMI8658C_REG_TIMESTAMP_LOW           (0x30)/**/
#define QMI8658C_REG_TIMESTAMP_MID           (0x31)/**/
#define QMI8658C_REG_TIMESTAMP_HIGH          (0x32)/**/
/*Data Output Registers (16 bits 2’s Complement Except COD Sensor Data) */
#define QMI8658C_REG_TEMP_L                  (0x33)/**/
#define QMI8658C_REG_TEMP_H                  (0x34)/**/
#define QMI8658C_REG_AX_L                    (0x35)/**/
#define QMI8658C_REG_AX_H                   (0x36)/**/
#define QMI8658C_REG_AY_L                   (0x37)/**/
#define QMI8658C_REG_AY_H                   (0x38)/**/
#define QMI8658C_REG_AZ_L                   (0x39)/**/
#define QMI8658C_REG_AZ_H                   (0x3A)/**/
#define QMI8658C_REG_GX_L                   (0x3B)/**/
#define QMI8658C_REG_GX_H                   (0x3C)/**/
#define QMI8658C_REG_GY_L                   (0x3D)/**/
#define QMI8658C_REG_GY_H                   (0x3E)/**/
#define QMI8658C_REG_GZ_L                   (0x3F)/**/
#define QMI8658C_REG_GZ_H                   (0x40)/**/
/*COD Indication and General Purpose Registers */
#define QMI8658C_REG_dQW_L                   (0x49)/**/
#define QMI8658C_REG_dQW_H                   (0x4A)/**/
#define QMI8658C_REG_dQX_L                   (0x4B)/**/
#define QMI8658C_REG_dQX_H                   (0x4C)/**/
#define QMI8658C_REG_dQY_L                   (0x4D)/**/
#define QMI8658C_REG_dQY_H                   (0x4E)/**/
#define QMI8658C_REG_dQZ_L                   (0x4F)/**/
#define QMI8658C_REG_dQZ_H                   (0x50)/**/
#define QMI8658C_REG_dVX_L                   (0x51)/**/
#define QMI8658C_REG_dVX_H                   (0x52)/**/
#define QMI8658C_REG_dVY_L                   (0x53)/**/
#define QMI8658C_REG_dVY_H                   (0x54)/**/
#define QMI8658C_REG_dVZ_L                   (0x55)/**/
#define QMI8658C_REG_dVZ_H                   (0x56)/**/
/*Reset Register*/
#define QMI8658C_REG_RESET                   (0X60)/**/


#define QMI8658C_SetReg_Define()                                                                            \
{                                                                                                           \
    {sensor_cmd_write,(uint8_t[]){QMI8658C_REG_RESET,0xb0},2,(uint8_t[]){0x60},0,100},/**CTRL1 */                               \
    {sensor_cmd_write,(uint8_t[]){QMI8658C_REG_CTRL1,0x40},2,(uint8_t[]){0x60},0,100},/**CTRL1 */                               \
    {sensor_cmd_write,(uint8_t[]){QMI8658C_REG_CTRL7,0x03},2,(uint8_t[]){0x43},0,100},/**CTRL7 启动加速度 启动陀螺仪*/            \
    {sensor_cmd_write,(uint8_t[]){QMI8658C_REG_CTRL2,0x95},2,(uint8_t[]){0xB0},0,100},/**CTRL2 16g   7520(hz)*/                 \
    {sensor_cmd_write,(uint8_t[]){QMI8658C_REG_CTRL3,0xd5},2,(uint8_t[]){0xF0},0,100},/**CTRL3 2048dps 7520(hz)*/               \ 
}

#define QMI8658C_CMD_NUM    5



typedef struct _qmi8658_io_panel_t qmi8658_io_panel_t;

struct _qmi8658_io_panel_t{
    uint8_t address;
    void (*transmit)(qmi8658_io_panel_t *panel,const sensor_cmd_t* sensor_cmd);
    void (*transmit_receive)(qmi8658_io_panel_t *panel,const sensor_cmd_t* sensor_cmd);
    void* user_data;
};


sensor_panel_t* qmi8658c_init(qmi8658_io_panel_t* io_panel);

#endif // QMI8658A_H


