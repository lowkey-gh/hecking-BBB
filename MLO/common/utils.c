#include "regs.h"

#define BIT_MASK(num)	(1U << (num) )

void disable_watchdog()
{
        volatile unsigned int * watchdog = WDT_BASE;
        // Write
        watchdog[WDT_WSPR/4] =  STOP_SEQ_1 ;

        // Check if WSPR is completely written , 1 : write is pending
        while ( (watchdog[WDT_WWPS/4] & (1<<4) ) );

        // Repeat
        watchdog[WDT_WSPR/4] =  STOP_SEQ_2 ;
        while ( (watchdog[WDT_WWPS/4] & (1<<4) ) );
}


void enable_gpio_1_clk()
{
        volatile unsigned int * cm_per = CM_PER_BASE;
        cm_per[CM_PER_GPIO1_CLKCTRL/4] = CM_PER_EN;

        int sleep = 1000;
        while(sleep--);

}

// Try to make is a generic one
void gpio_output(volatile unsigned int * gpio_base, int bit)
{
        volatile unsigned int * gpio = gpio_base;
        gpio[GPIO_OE/4] &= ~( BIT_MASK(bit) ) ;
}


// Pass GPIO Pin for it to "blink" 
void blink(const unsigned int led_pin)
{
        volatile unsigned int * gpio = GPIO1_BASE;
        // pick set or clear data
        // 0x190 = 0001 1001 0000 clear
        // 0x194 = 0001 1001 0100 set
        // if inverted_bit_val at LED_BIT is 1 then we have to set unless clear
        unsigned int inverted_bit_val = ( (gpio[ (GPIO_DATAOUT/4)] ^ BIT_MASK(led_pin) ) >> led_pin ) & 0x1  ;

        // use the lower address for picking between the two
        // (0x190 | 0x0 = 0x190)
        // (0x190 | 0x4 = 0x194)
        unsigned int gpio_reg = GPIO_CLEARDATAOUT | (inverted_bit_val << 2); // PS; could've used if-else but yeah :)

        // set the CLEAR/SET reg for the given GPIO
        gpio[gpio_reg/4] = BIT_MASK(led_pin);
}




