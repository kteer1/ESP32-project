file(GLOB_RECURSE SOURCES   "."
                             "main.c" 
                             "../kt_os/*.c"
                             "../esp32_drive/*.c"

                    )



set( INCLUDES   "." 
                "../kt_os"
                "../esp32_drive"
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
)
