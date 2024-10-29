#define STM32F4 // for including versions of libopencm3 includes for my microcontroller (F4)
#define __ARM_ARCH_7EM__

#include "../inc/common-defines.h"
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h> // i have added the libopencm3 folder in the vscode include paths
// i have also added that folder to the makefile include file that calls the compiler so as to recognize these includes

#define LED_PORT (GPIOA)
#define LED_PIN (GPIO5)

static void rcc_setup(void)
{
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_3V3_84MHZ]);
}

static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);
}

static void delay_cycles(uint32_t cycles)
{
    for (uint32_t i = 0; i < cycles; i++)
    {
        __asm__("nop"); // nop takes one clock cycle
    }
}

int main(void)
{
    rcc_setup();
    gpio_setup();

    while (true)
    {
        gpio_toggle(LED_PORT, LED_PIN);
        delay_cycles(84000000 / 4);
    }

    // never return
    return EXIT_SUCCESS;
}