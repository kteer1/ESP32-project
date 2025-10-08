file(GLOB_RECURSE SOURCES   "."
                             "main.c" 
                             "../kt_os/*.c"

                    )



set( INCLUDES   "." 
                "../kt_os"
                    )

idf_component_register(
                        SRCS ${SOURCES} 
                        INCLUDE_DIRS ${INCLUDES}
)
