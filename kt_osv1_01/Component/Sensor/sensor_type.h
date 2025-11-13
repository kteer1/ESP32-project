#ifndef ___kSENSOR_TYPE_H__
#define ___kSENSOR_TYPE_H__

#include <stdint.h>
#include <stdlib.h>

#ifndef _DEQUALIFY_
    #define	_DEQUALIFY_(type, var)	((type)(__uintptr_t)(const volatile void *)(var))
#endif

#ifndef container_of
        #define	container_of(x, s, m) ({					\
            const volatile __typeof(((s *)0)->m) *__x = (x);		\
            _DEQUALIFY_(s *, (const volatile char *)__x - __offsetof(s, m));\
        })
#endif

// enum sensor_cmd_status_e{
//     sensor_cmd_write = 0,
//     sensor_cmd_read,
// };

// typedef struct {
//     int cmd_state;
//     unsigned char*cmd;
//     uint16_t cmd_bytes;      /*<! Size of `data` in memory, in bytes */
//     unsigned char *data;       /*<! Buffer that holds the command specific data */
//     uint16_t data_bytes;      /*<! Size of `data` in memory, in bytes */
//     unsigned int delay_ms;  /*<! Delay in milliseconds after this command */
// } sensor_cmd_t;

typedef unsigned char  sensor_size_t;
typedef unsigned char  sensor_len_t;

typedef struct _sensor_panel_t sensor_panel_t;
struct _sensor_panel_t{
    /**
     * @brief init Sensor panel
     *
     * @param[in] panel Sensor panel handle, which is created by other factory API 
     * @return
     *          
     */
    void (*init)(sensor_panel_t *panel);
    /**
     * @brief Reset Sensor panel
     *
     * @param[in] panel Sensor panel handle, which is created by other factory API 
     * @return
     *          
     */
    void (*reset)(sensor_panel_t *panel);
    /**
     * @brief del Sensor panel
     *
     * @param[in] panel Sensor panel handle, which is created by other factory API 
     * @return
     *          
     */
    void (*del)(sensor_panel_t *panel);

    /**
     * @brief 
     *
     * @note 
     *
     * @param[in] panel 
     * @param[in] write_buffer Data bytes to send on the I2C bus.
     * @param[in] write_size Size, in bytes, of the write buffer.
     * @param[in] xfer_timeout_ms Wait timeout, in ms. Note: -1 means wait forever.
     * @return
     */
    void (*transmit)(sensor_panel_t *panel,const sensor_size_t* sensor_cmd,sensor_len_t sensor_len);


    /**
     * @brief 
     *
     * @note 
     *
     * @param[in] panel 
     * @param[in] write_buffer Data bytes to send on the I2C bus.
     * @param[in] write_size Size, in bytes, of the write buffer.
     * @param[out] read_buffer Data bytes received from i2c bus.
     * @param[in] read_size Size, in bytes, of the read buffer.
     * @param[in] xfer_timeout_ms Wait timeout, in ms. Note: -1 means wait forever.
     * @return
     */
    void (*transmit_receive)(sensor_panel_t *panel,const sensor_size_t* sensor_cmd,sensor_len_t cmd_len,const sensor_size_t* sensor_data,sensor_len_t sensor_data_len);

    void *user_data;
};


#endif // SENSOR_TYPE_H


