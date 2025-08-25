file(GLOB_RECURSE SOURCES   "."
                             "main.c" 

                    )



set( INCLUDES "." 

                    )


idf_component_register(
    SRCS ${SOURCES} 
    INCLUDE_DIRS ${INCLUDES}
    PRIV_REQUIRES "drive" "freertos" "esp_wifi" "lwip" "esp_event" "esp_common"
)