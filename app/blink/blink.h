#ifndef BLINK_H__
#define BLINK_H__

#include "pico/stdlib.h"

extern const uint LED_PIN;

extern void blink_init();
extern void led_blink_main();

#endif