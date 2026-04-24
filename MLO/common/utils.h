#ifndef __UTIL_H
#define __UTIL_H

void disable_watchdog();

// Make it generic
void enable_gpio_1_clk();

// GENERIC
void gpio_1_21_output();

// Pass GPIO Pin for it to "blink" 
void blink();


#endif
