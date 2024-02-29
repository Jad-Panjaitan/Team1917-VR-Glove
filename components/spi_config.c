// main/spi_config.c
#include "spi_config.h"

// SPI Bus parameters
spi_bus_config_t spi_bus_config = {
    .mosi_io_num = 35,  // sets the MOSI pin number
    .miso_io_num = 36,  // sets the MISO pin number
    .sclk_io_num = 37,  // sets the SCK pin number
    .quadwp_io_num = -1,        //not used, set to -1
    .quadhd_io_num = -1,        // not used, set to -1
    .max_transfer_sz = 4096,
};

// SPI Device parameters
spi_device_interface_config_t spi_device_config = {
    .clock_speed_hz = 1 * 1000 * 1000,
    .mode = 0,
    .spics_io_num = 17,
    .queue_size = 7,
    .flags = 0,
    .pre_cb = NULL,
    .post_cb = NULL,
};

// Handle for the SPI device
spi_device_handle_t spi_handle;

void spi_init() {
    // Initialize the SPI bus
    ESP_ERROR_CHECK(spi_bus_initialize(SPI3_HOST, &spi_bus_config, SPI_DMA_CH_AUTO));

    // Attach the SPI bus to the SPI device
    ESP_ERROR_CHECK(spi_bus_add_device(SPI3_HOST, &spi_device_config, &spi_handle));
}
