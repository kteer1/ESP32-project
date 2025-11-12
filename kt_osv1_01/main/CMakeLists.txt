file(GLOB_RECURSE SOURCES   
                            "main.c"
                            "../Component/LVGL/*.c"
                            "../Component/IO_Expander/*.c"
                            "../Component/Sensor/IMU/*.c"
                            "../Component/Sensor/IMU/porting/*.c"
                            "../Component/WIFI/*.c"
                    )



set( INCLUDES       
                    "." 
                    "../Component/LVGL"
                    "../Component/IO_Expander"
                    "../Component/Sensor"
                    "../Component/Sensor/IMU"
                    "../Component/Sensor/IMU/porting"
                    "../Component/WIFI"
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        REQUIRES "log" "driver" "esp_common" "freertos" "esp_lcd" "esp_timer" "nvs_flash" "esp_event" "esp_netif" "esp_driver_i2c" "esp_wifi"
)