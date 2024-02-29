// main/main.c
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "spi_config.h"

void app_main(void) {
    spi_init();
    // Your code to interact with the device goes here
    // ...
}
