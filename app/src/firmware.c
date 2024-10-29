#define STM32F4 // for including versions of libopencm3 includes for my microcontroller (F4)
#define __ARM_ARCH_7EM__

#include "../inc/common-defines.h"
#include <libopencm3/stm32/rcc.h> // i have added the libopencm3 folder in the vscode include paths
// i have also added that folder to the makefile include file that calls the compiler so as to recognize these includes

static void rcc_setup(void)
{
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_3V3_84MHZ]);
}

int main(void)
{
    while (true)
    {
    }

    // never return
    return EXIT_SUCCESS;
}