#ifndef __spi_H__
#define __SPI_H__

#include "hardware/spi.h"

#define SPI_PORT spi0
#define PIN_MISO 4
#define PIN_CS   5
#define PIN_SCK  6
#define PIN_MOSI 7


extern void spi_init()
extern void spi_transfer(uint8_t* tx_buffer, uint8_t* rx_buffer, size_t length)
extern int  spi_main()

#endif