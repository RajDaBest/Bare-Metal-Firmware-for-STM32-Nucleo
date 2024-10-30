#define STM32F4 // for including versions of libopencm3 includes for my microcontroller (F4)
// #define __ARM_ARCH_7EM__

#include "../inc/common-defines.h"
#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/vector.h>

#define BOOTLOADER_SIZE (0x8000U) // U always forces the number to be treated as unsigned, even if it overflows in signed range
#define MAIN_APP_START_ADDRESS (FLASH_BASE + BOOTLOADER_SIZE)

static void jump_to_main(void)
{
    vector_table_t *vector_table_main = (vector_table_t *)(MAIN_APP_START_ADDRESS);
    vector_table_main->reset();
}

int main(void)
{
    jump_to_main();

    // never return
    return EXIT_SUCCESS;
}