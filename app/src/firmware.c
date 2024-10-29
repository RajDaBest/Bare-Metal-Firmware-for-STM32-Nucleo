#define STM32F4 // for including versions of libopencm3 includes for my microcontroller (F4)
// #define __ARM_ARCH_7EM__

#include "common-defines.h"
#include "system.h"

static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);
}

int main(void)
{
    system_setup();
    gpio_setup();

    uint64_t start_time = system_get_ticks();

    while (true)
    {
        if (system_get_ticks() - start_time >= 1000)
        {
            gpio_toggle(LED_PORT, LED_PIN);
            start_time = system_get_ticks();
        }
    }

    // never return
    return EXIT_SUCCESS;
}