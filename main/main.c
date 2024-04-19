#include "pico/stdlib.h"

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    

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
#endif
}
