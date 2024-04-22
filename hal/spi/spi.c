#include "spi.h"

void spi_init() {
    // 设置SPI引脚
    spi_init(SPI_PORT, 1000 * 1000);  // 初始化SPI，设置速率为1MHz
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_CS, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);

    // 设置CS引脚为高电平（未选中）
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);
}

void spi_transfer(uint8_t* tx_buffer, uint8_t* rx_buffer, size_t length) {
    // 选中SPI设备
    gpio_put(PIN_CS, 0);

    // 进行SPI传输
    spi_write_read_blocking(SPI_PORT, tx_buffer, rx_buffer, length);

    // 取消选中SPI设备
    gpio_put(PIN_CS, 1);
}

int spi_main() {
    stdio_init_all();
    spi_init();

    uint8_t tx_buffer[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    uint8_t rx_buffer[10];

    spi_transfer(tx_buffer, rx_buffer, 10);

    for (int i = 0; i < 10; i++) {
        printf("Received: %d\n", rx_buffer[i]);
    }

    return 0;
}
