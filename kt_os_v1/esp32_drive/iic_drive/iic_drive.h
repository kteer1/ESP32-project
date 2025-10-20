#ifndef ___kIIC_DRIVE_H__
#define ___kIIC_DRIVE_H__


#define IIC_MASTER01_HOST               I2C_NUM_0
#define IIC_MASTER01_SCL                (GPIO_NUM_14)
#define IIC_MASTER01_SDA                (GPIO_NUM_15)

#define IIC_MASTER01_CLK_SPEED          200000

#define IIC_MASTER01_DEV_IOExpander_Address     0x20






void eIIC_Master01(void* param);
void eIIC_Dev01Init(void*param);

#endif // IIC_DRIVE_H













