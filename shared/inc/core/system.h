#ifndef INC_SYSTEM_H
#define INC_SYSTEM_H

#define STM32F4

#include <stdint.h>
#include "libopencm3/cm3/systick.h"
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/vector.h>
#include <libopencm3/stm32/rcc.h> // i have added the libopencm3 folder in the vscode include paths
// i have also added that folder to the makefile include file that calls the compiler so as to recognize these includes

#define CPU_FREQ (84000000)
#define SYSTICK_FREQ (1000)

#define LED_PORT (GPIOA)
#define LED_PIN (GPIO5)

void system_setup(void);
uint64_t system_get_ticks(void);
void system_delay(uint64_t milliseconds);

#endif // INC_SYSTEM_H