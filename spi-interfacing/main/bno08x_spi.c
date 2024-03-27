#include "bno08x_spi.h"

static const char *TAG = "BNO08x_SPI";

void initialize_spi() {
    esp_err_t ret;

    spi_bus_config_t buscfg = {
        .mosi_io_num = MOSI_PIN,
        .miso_io_num = MISO_PIN,
        .sclk_io_num = SCK_PIN,
        .quadwp_io_num = -1, //Quad SPI not used so assigned as -1
        .quadhd_io_num = -1,
        .max_transfer_sz = 4096,  // Adjust as needed
    };

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 10*1000*1000, // Adjust to the BNO08x's specs
        .mode = 0,                      // SPI mode 0
        .spics_io_num = BNO_CS_PIN,
        .queue_size = 7,                // Transaction queue size
    };

    // Initialize the SPI bus
    ret = spi_bus_initialize(SPI3_HOST, &buscfg, SPI_DMA_CH_AUTO);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize SPI bus: %s", esp_err_to_name(ret));
        return;
    }

    // Add the SPI device
    ret = spi_bus_add_device(SPI3_HOST, &devcfg, &spi_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to add SPI device: %s", esp_err_to_name(ret));
        return;
    }
}

void initialize_bno08x() {
    ESP_LOGI(TAG, "Initializing BNO08X sensor...");
    // Sensor-specific initialization code here
}

void read_sensor_data() {
    ESP_LOGI(TAG, "Reading data from BNO08X sensor...");
    // SPI read operation code here
}
