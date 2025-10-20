#ifndef ___kQMI8658A_H__
#define ___kQMI8658A_H__

#define QMI8658A_ADDRESS                    (0x6B)
#define QMI8658A_CLK_SPEED                  (200000)

/** Register Address  */
#define QMI8658A_REG_WHO_AM_I                (0x00)/*Device Identifier    (0x05)*/
#define QMI8658A_REG_REVISION_ID             (0x01)/*Device Revision ID */

#define QMI8658A_REG_CTRL1                   (0x02)/*SPI Interface and Sensor Enable */
#define QMI8658A_REG_CTRL2                   (0x03)/*Accelerometer: Output Data Rate, Full Scale, Self-Test*/
#define QMI8658A_REG_CTRL3                   (0x04)/*Gyroscope: Output Data Rate, Full Scale, Self-Test */
#define QMI8658A_REG_CTRL5                   (0x06)/*Low pass filter setting */
#define QMI8658A_REG_CTRL7                   (0x08)/*Enable Sensors */
#define QMI8658A_REG_CTRL8                   (0x09)/*Motion Detection Control */
#define QMI8658A_REG_CTRL9                   (0x0A)/*Host Commands */
/**Calibration Register */
#define QMI8658A_REG_CAL1_L                  (0x0B)/*CAL1_L – lower 8 bits. */
#define QMI8658A_REG_CAL1_H                  (0x0C)/*CAL1_H – upper 8 bits.*/
#define QMI8658A_REG_CAL2_L                  (0x0D)/*CAL2_L – lower 8 bits. */
#define QMI8658A_REG_CAL2_H                  (0x0E)/*CAL2_H – upper 8 bits. */
#define QMI8658A_REG_CAL3_L                  (0x0F)/*CAL3_L – lower 8 bits.*/
#define QMI8658A_REG_CAL3_H                  (0x10)/*CAL3_H – upper 8 bits.*/
#define QMI8658A_REG_CAL4_L                  (0x11)/*CAL4_L – lower 8 bits.*/
#define QMI8658A_REG_CAL4_H                  (0x12)/*CAL4_H – upper 8 bits. */
/*FIFO Registers */
#define QMI8658A_REG_FIFO_WTM_TH             (0x19)/*FIFO watermark level, in ODRs */
#define QMI8658A_REG_FIFO_CTRL               (0x20)/*FIFO Setup */
#define QMI8658A_REG_FIFO_SMPL_CNT           (0x21)/*FIFO sample count LSBs */
#define QMI8658A_REG_FIFO_STATUS             (0x22)/*FIFO Status */
#define QMI8658A_REG_FIFO_DATA               (0x23)/*FIFO Data */
/*Status Registers */
#define QMI8658A_REG_STATUSINT               (0x45)/*Sensor Data Availability with the Locking mechanism, CmdDone (CTRL9 protocol bit).*/
#define QMI8658A_REG_STATUS0                 (0x46)/*Output Data Over Run and Data Availability.*/
#define QMI8658A_REG_STATUS1                 (0x47)/*Miscellaneous Status: Any Motion, No Motion, Significant Motion, Pedometer, Tap.*/
/*Timestamp Register*/
#define QMI8658A_REG_TIMESTAMP_LOW           (0x48)/**/
#define QMI8658A_REG_TIMESTAMP_MID           (0x49)/**/
#define QMI8658A_REG_TIMESTAMP_HIGH          (0x50)/**/
/*Data Output Registers (16 bits 2’s Complement Except COD Sensor Data) */
#define QMI8658A_REG_TEMP_L                  (0x51)/**/
#define QMI8658A_REG_TEMP_H                  (0x52)/**/
#define QMI8658A_REG_TEMP_AX_L               (0x53)/**/
#define QMI8658A_REG_TEMP_AX_H               (0x54)/**/
#define QMI8658A_REG_TEMP_AY_L               (0x55)/**/
#define QMI8658A_REG_TEMP_AY_H               (0x56)/**/
#define QMI8658A_REG_TEMP_AZ_L               (0x57)/**/
#define QMI8658A_REG_TEMP_AZ_H               (0x58)/**/
#define QMI8658A_REG_TEMP_GX_L               (0x59)/**/
#define QMI8658A_REG_TEMP_GX_H               (0x60)/**/
#define QMI8658A_REG_TEMP_GY_L               (0x61)/**/
#define QMI8658A_REG_TEMP_GY_H               (0x62)/**/
#define QMI8658A_REG_TEMP_GZ_L               (0x63)/**/
#define QMI8658A_REG_TEMP_GZ_H               (0x64)/**/
/*COD Indication and General Purpose Registers */
#define QMI8658A_REG_COD_STATUS              (0x70)/**/
#define QMI8658A_REG_dQW_L                   (0x73)/**/
#define QMI8658A_REG_dQW_H                   (0x74)/**/
#define QMI8658A_REG_dQX_L                   (0x75)/**/
#define QMI8658A_REG_dQX_H                   (0x76)/**/
#define QMI8658A_REG_dQY_L                   (0x77)/**/
#define QMI8658A_REG_dQY_H                   (0x78)/**/
#define QMI8658A_REG_dQZ_L                   (0x79)/**/
#define QMI8658A_REG_dQZ_H                   (0x80)/**/

#define QMI8658A_REG_dVX_L                   (0x81)/**/
#define QMI8658A_REG_dVX_H                   (0x82)/**/
#define QMI8658A_REG_dVY_L                   (0x83)/**/
#define QMI8658A_REG_dVY_H                   (0x84)/**/
#define QMI8658A_REG_dVZ_L                   (0x85)/**/
#define QMI8658A_REG_dVZ_H                   (0x86)/**/

/*Activity Detection Output Registers */
#define QMI8658A_REG_TAP_STATUS              (0x89)/**/
#define QMI8658A_REG_STEP_CNT_LOW            (0x90)/**/
#define QMI8658A_REG_STEP_CNT_MIDL           (0x91)/**/
#define QMI8658A_REG_STEP_CNT_HIGH           (0x92)/**/

#define QMI8658A_REG_RESET                   (0X96)/**/

#endif // QMI8658A_H


