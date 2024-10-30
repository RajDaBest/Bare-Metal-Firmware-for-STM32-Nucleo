#define STM32F4 // for including versions of libopencm3 includes for my microcontroller (F4)
// #define __ARM_ARCH_7EM__

// the vector table is put automatically by the compiler due to libopencm3 with the reset vector doing some startup stuff and then calling the main function

#include "common-defines_app.h"
#include "system.h"
#include "timer.h"

static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(LED_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, LED_PIN);
    gpio_set_af(LED_PORT, GPIO_AF1, LED_PIN);
}

int main(void)
{
    system_setup();
    gpio_setup();
    timer_setup();

    uint64_t start_time = system_get_ticks();
    float duty_cycle = 0.0f;

    timer_pwm_set_duty_cycle(duty_cycle);

    while (true)
    {
        if (system_get_ticks() - start_time >= 10)
        {
            duty_cycle += 1.0f;
            if (duty_cycle > 100.0f)
            {
                duty_cycle = 0.0f;
            }

            timer_pwm_set_duty_cycle(duty_cycle);
            start_time = system_get_ticks();
        }
    }

    // never return
    return EXIT_SUCCESS;
}