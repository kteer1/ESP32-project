file(GLOB_RECURSE SOURCES   "."
                             "main.c" 

                    )



set( INCLUDES "." 

                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
                        REQUIRES "log" "driver"  "freertos"
)

