#include "bno08x_spi.h" // Adjust this path according to your project structure

void app_main() {
    // Initialize SPI
    initialize_spi();

    // Initialize BNO08x sensor
    initialize_bno08x();

    while(1) {
        // Read sensor data
        read_sensor_data();
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}
