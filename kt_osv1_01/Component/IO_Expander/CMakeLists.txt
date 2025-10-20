file(GLOB_RECURSE SOURCES   
                    "."
                    
                    )



set( INCLUDES       
                    "." 
                    
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        REQUIRES "log" "driver" "esp_common" "freertos"
)