#include "../common/regs.h"
#include "../common/utils.h"

int main()
{
	disable_watchdog();
	enable_gpio_1_clk();

	gpio_output(GPIO1_BASE, USR_0_LED_PIN);
	gpio_output(GPIO1_BASE, USR_1_LED_PIN);
	gpio_output(GPIO1_BASE, USR_2_LED_PIN);
	gpio_output(GPIO1_BASE, USR_3_LED_PIN);
	while(1)
	{	
		blink(USR_3_LED_PIN);
		for (volatile int i = 0; i < 200000; i++); // sleep
	}
	return -1;
}
