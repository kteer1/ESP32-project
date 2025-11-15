file(GLOB_RECURSE SOURCES   
                            "porting.c"
                    )



set( INCLUDES       
                    "." 
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        REQUIRES "log" "driver" "esp_driver_gpio" "freertos" 
)