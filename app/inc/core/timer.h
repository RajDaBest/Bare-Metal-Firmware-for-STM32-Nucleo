#ifndef INC_TIMER_H
#define INC_TIMER_H

#define STM32F4

#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/rcc.h>

#define PRESCALER (84)
#define ARR_VALUE (1000)

void timer_setup(void);
void timer_pwm_set_duty_cycle(float duty_cycle);

#endif // INC_TIMER_H