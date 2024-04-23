#include "main.h"

int main() {
    blink_init();
    while (1)
    {
        led_blink_main();
    }
}
