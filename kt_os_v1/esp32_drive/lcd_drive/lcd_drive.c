#include "lcd_drive.h"
#include "Bsp/porting/lcd_porting.h"




void klcd_drive_init(void*param)
{
    lcd_porting_init(param);
}




