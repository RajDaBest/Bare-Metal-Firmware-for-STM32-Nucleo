#define STM32F4 // for including versions of libopencm3 includes for my microcontroller (F4)
// #define __ARM_ARCH_7EM__

// the vector table is put automatically by the compiler due to libopencm3 with the reset vector doing some startup stuff and then calling the main function

#include "common-defines_app.h"
#include "../../shared/inc/core/system.h"
#include "timer.h"
#include "../../shared/inc/core/uart.h"

#define BOOTLOADER_SIZE (0x8000U)

#define UART_PORT (GPIOA)
#define RX_PIN (GPIO3)
#define TX_PIN (GPIO2)

static void vector_setup(void)
{
    SCB_VTOR = BOOTLOADER_SIZE; // SCB_VTOR memory-mapped register contains the address of the vector table; by default it will be 0x08000000 (start of flash memory)
    // we reset it here to point to the vector table of the main application
}

static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);

    gpio_mode_setup(LED_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, LED_PIN);
    gpio_set_af(LED_PORT, GPIO_AF1, LED_PIN);

    gpio_mode_setup(UART_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, RX_PIN);
    gpio_mode_setup(UART_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, TX_PIN);
    gpio_set_af(UART_PORT, GPIO_AF7, TX_PIN | RX_PIN);
}

int main(void)
{
    vector_setup();
    system_setup();
    gpio_setup();
    timer_setup();
    uart_setup();

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

        if (uart_data_available())
        {
            uint8_t data_recv = uart_read_byte();
            uart_write_byte(data_recv + 1);
        }
    }

    // never return
    return EXIT_SUCCESS;
}