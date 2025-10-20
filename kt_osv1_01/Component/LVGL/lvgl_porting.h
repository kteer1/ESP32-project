#ifndef ___kLVGL_PORTING_H__
#define ___kLVGL_PORTING_H__

/**QSPI Define */
#define LCD_HOST                                        SPI2_HOST
#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL                   1
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL                  (!EXAMPLE_LCD_BK_LIGHT_ON_LEVEL)
#define EXAMPLE_PIN_NUM_LCD_CS                          (GPIO_NUM_12)
#define EXAMPLE_PIN_NUM_LCD_PCLK                        (GPIO_NUM_11)
#define EXAMPLE_PIN_NUM_LCD_DATA0                       (GPIO_NUM_4)
#define EXAMPLE_PIN_NUM_LCD_DATA1                       (GPIO_NUM_5)
#define EXAMPLE_PIN_NUM_LCD_DATA2                       (GPIO_NUM_6)
#define EXAMPLE_PIN_NUM_LCD_DATA3                       (GPIO_NUM_7)
#define EXAMPLE_PIN_NUM_LCD_RST                         (-1)
#define EXAMPLE_PIN_NUM_BK_LIGHT                        (-1)

// The pixel number in horizontal and vertical
#define EXAMPLE_LCD_H_RES                               368
#define EXAMPLE_LCD_V_RES                               448
#define LVGL_Disp_BUFF_SIZE                             10
#define LCD_BIT_PER_PIXEL                               (16)
#define BYTE_PER_PIXEL                                  1

#define IIC_MASTER01_HOST               I2C_NUM_0
#define IIC_MASTER01_SCL                (GPIO_NUM_14)
#define IIC_MASTER01_SDA                (GPIO_NUM_15)

#define Touch_IIC_Address                       (0x38)
#define IIC_DEV01_CLK_SPEED                    (200000)


#define MY_DISP_HOR_RES     EXAMPLE_LCD_H_RES
#define MY_DISP_VER_RES     10

typedef struct{

    void(*init)(void* param);
    void(*set_disp_onoff)(void* param,unsigned char fbit);

    void *user_pandel;
    void *user_disp;
}lvgl_porting_t;

void lvgl_porting_init(void * param);

#endif // LVGL_PORTING_H


