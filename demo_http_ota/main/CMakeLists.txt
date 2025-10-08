file(GLOB_RECURSE SOURCES   "."
                             "main.c" 
                             "../Component/ESP32_Drive/WIFI_Drive/*.c"

                    )



set( INCLUDES   "." 
                "../Component/ESP32_Drive/WIFI_Drive"
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
)

