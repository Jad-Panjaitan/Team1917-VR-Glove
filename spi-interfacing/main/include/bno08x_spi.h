#ifndef BNO08X_SPI_H
#define BNO08X_SPI_H

#include "driver/spi_master.h"
#include "esp_log.h"

// Pin definitions moved to the header file for easier reference and modifications

//BNO pins	--------->	//ESP32-S3 pins
#define BNO_CS_PIN      GPIO_NUM_5  // Chip select pin for BNO08x sensor
#define MOSI_PIN        GPIO_NUM_14 // MOSI pin connects to SDA on BNO08x (MOSI = Master out, Slave in)
#define MISO_PIN        GPIO_NUM_25 // MISO pin (MISO = Master in, Slave out)
#define SCK_PIN         GPIO_NUM_18 // Serial Clock pin (aka SCL on the BNO but has same functionality)

// SPI device handle for the BNO08X sensor
extern spi_device_handle_t spi_handle;

// Function prototypes
void initialize_spi();
void initialize_bno08x();
void read_sensor_data();

#endif /* BNO08X_SPI_H */
