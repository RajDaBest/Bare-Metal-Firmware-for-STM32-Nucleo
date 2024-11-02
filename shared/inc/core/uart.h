#ifndef UART_H
#define UART_H

#define STM32F4

#include <stdint.h>
#include <stdbool.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/nvic.h>

void uart_setup(void);
void uart_write(uint8_t *data, const uint32_t length);
void uart_write_byte(uint8_t data);
uint32_t uart_read(uint8_t *data, const uint32_t length);
uint8_t uart_read_byte(void);
bool uart_data_available(void);

#endif