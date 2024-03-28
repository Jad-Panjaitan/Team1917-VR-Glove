#include "bno08x_spi.h"

#define PRODUCT_ID_REQ 0XF9		//Report ID for Product ID Request
#define PRODUCT_ID_RESP 0XF8	// Report ID for Product ID Response

static const char *TAG = "BNO08x_SPI";

void initialize_spi() {
    esp_err_t ret;

    //SPI bus configuration
    spi_bus_config_t buscfg = {
        .mosi_io_num = MOSI_PIN,
        .miso_io_num = MISO_PIN,
        .sclk_io_num = SCK_PIN,
        .quadwp_io_num = -1, //Quad SPI not used so assigned as -1
        .quadhd_io_num = -1,
        .max_transfer_sz = 4096,  // Adjust as needed
    };

    //SPI device configuration
    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 10*1000*1000, // Adjust to the BNO08x's specs
        .mode = 3,                      // SPI mode 3 is used for BNO08x (found in datasheet)
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



void check_spi_communication() {
	uint8_t send_buffer[2] = {PRODUCT_ID_REQ, 0x00}; // Assuming the MSB needs to be set for a read operation, adjust as necessary
	uint8_t receive_buffer[4] = {0}; //Can be adjusted based on expected response size

	spi_transaction_t transaction;
	memset(&transaction, 0, sizeof(transaction)); // Zero out the transaction
	transaction.length = 8; // Length in bits, sends 2 bytes here
	transaction.tx_buffer = send_buffer;
	transaction.rx_buffer = receive_buffer;

	ESP_LOGI(TAG, "Checking SPI communication with BNO08X...");
	esp_err_t ret = spi_device_transmit(spi_handle, &transaction);
	if (ret != ESP_OK) {
	    ESP_LOGE(TAG, "SPI transaction failed: %s", esp_err_to_name(ret));
	    return;
	}
	// Check if the response starts with the Product ID Response Report ID
	    if (receive_buffer[0] == PRODUCT_ID_RESP) { // PRODUCT_ID_RESP should be defined based on your datasheet
	        ESP_LOGI(TAG, "Successfully received Product ID Response from BNO08X.");
	        // Further processing can be done here to validate the entire response
	    } else {
	        ESP_LOGE(TAG, "Unexpected response received from BNO08X.");
	    }

}
