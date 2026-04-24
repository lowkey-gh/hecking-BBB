#include "../common/regs.h"
#include "../common/utils.h"

int main()
{
	disable_watchdog();
	enable_gpio_1_clk();
	gpio_1_21_output();
	while(1)
	{
		blink();
		for (volatile int i = 0; i < 200000; i++); // sleep
	}
}
