#include "../../inc/core/system.h"

static volatile uint64_t ticks = 0;

static void rcc_setup(void)
{
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_3V3_84MHZ]);
}

static void systick_setup(void)
{
    systick_set_frequency(SYSTICK_FREQ, CPU_FREQ);
    systick_counter_enable();
    systick_interrupt_enable();
}

void system_setup(void)
{
    rcc_setup();
    systick_setup();
}

uint64_t system_get_ticks(void)
{
    return ticks;
}

void sys_tick_handler(void)
{
    ticks++;
}

void system_delay(uint64_t milliseconds)
{
    uint64_t end_time = system_get_ticks() + milliseconds;
    while (end_time > system_get_ticks())
    {
        // spin
    }
}
