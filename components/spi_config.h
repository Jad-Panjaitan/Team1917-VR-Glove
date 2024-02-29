// main/include/spi_config.h
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#include "driver/spi_master.h"

// SPI Bus parameters
extern spi_bus_config_t spi_bus_config;

// SPI Device parameters
extern spi_device_interface_config_t spi_device_config;

// Handle for the SPI device
extern spi_device_handle_t spi_handle;

// Function to initialize SPI bus and device
void spi_init();

#endif // SPI_CONFIG_H
