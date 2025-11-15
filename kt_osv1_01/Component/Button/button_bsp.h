#ifndef ___kBUTTON_BSP_H__
#define ___kBUTTON_BSP_H__

#define BUTTON_STATE_PRESS_ONCE     (0x01)

typedef enum{
    Button_Ture = 0,
    Button_False = 1,
    
}Button_Level_t;


typedef unsigned short button_count_size;
typedef struct _button_conf_t button_conf_t;

struct _button_conf_t{
    unsigned char state;
    unsigned char level;
    button_count_size cnt;
    button_count_size press_count;
    button_count_size press_count_last;
    button_count_size relax_count;

    void (*read_bit)(void*param);
};

#endif // BUTTON_BSP_H


