#ifndef __UTIL_H
#define __UTIL_H

void disable_watchdog();

// Make it generic
void enable_gpio_1_clk();

// GENERIC
void gpio_output(volatile unsigned int * gpio_base, int bit);

// Pass GPIO Pin for it to "blink" 
void blink(const unsigned int led_pin);

#endif
