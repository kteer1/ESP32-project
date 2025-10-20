file(GLOB_RECURSE SOURCES   
                            "imu_porting.c"
                    )



set( INCLUDES       
                    "." 
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        REQUIRES "log" "driver" "esp_common" "freertos" "esp_lcd" "esp_timer" "nvs_flash" "esp_event" "esp_netif"
)