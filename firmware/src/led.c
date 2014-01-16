

#include "stm32f0xx_rcc.h"
#include "stm32f0xx_gpio.h"

#include "led.h"
#include "gpio.h"


#define PIN         GPIO_1

void led_init(void)
{
    gpio_init_out(PIN, GPIO_PP_NOPULL);
    gpio_set(PIN);
}

void led_set(void)
{
    gpio_set(PIN);
}

void led_clear(void)
{
    gpio_clear(PIN);
}

void led_toggle(void)
{
    gpio_toggle(PIN);
}

void led_blink(void) 
{
    for (uint8_t repeat = 0; repeat < 6; repeat++) {
        gpio_toggle(PIN);
        for (uint32_t i = 0; i < BLINK_TIME; i++) {
            asm volatile ("nop");
        }
    }
}