# main/CMakeLists.txt
idf_component_register(SRCS "main.c" "spi_config.c"
                    INCLUDE_DIRS "include"
                    REQUIRES driver)

