file(GLOB_RECURSE SOURCES   
                    "."
                    "lvgl_porting.c"
                    "drive/Disp/SH8601/*.c"
                    )



set( INCLUDES       
                    "." 
                    "drive/Disp/SH8601/"
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        REQUIRES "log" "driver" "esp_common" "freertos" "esp_timer" "esp_driver_i2c"
)