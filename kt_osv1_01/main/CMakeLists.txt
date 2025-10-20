file(GLOB_RECURSE SOURCES   
                            "main.c"
                            "../Component/LVGL/*.c"
                            "../Component/IO_Expander/*.c"
                            "../Component/Six_Axis_IMU/*.c"
                    )



set( INCLUDES       
                    "." 
                    "../Component/LVGL"
                    "../Component/IO_Expander"
                    "../Component/Six_Axis_IMU"
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        REQUIRES "log" "driver" "esp_common" "freertos" "esp_lcd" "esp_timer" "nvs_flash" "esp_event" "esp_netif" "esp_driver_i2c"
)