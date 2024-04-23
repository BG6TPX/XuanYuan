#include "blink.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void blink_init()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void led_blink_main()
{
    gpio_put(LED_PIN, 1);
    sleep_ms(500);
    gpio_put(LED_PIN, 0);
    sleep_ms(500);
}
