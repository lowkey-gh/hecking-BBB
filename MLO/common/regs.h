#ifndef __REG_H
#define __REG_H


// WDT1 regs
#define WDT_BASE          (volatile unsigned int*)0x44E35000
#define WDT_WSPR          0x48          // Watchdog Start/Stop Register
#define WDT_WWPS          0x34          // Write Posting Bits (wait for sync)

#define STOP_SEQ_1        0xAAAA
#define STOP_SEQ_2        0x5555


// CM_PER regs
#define CM_PER_BASE             (volatile unsigned int*) 0x44E00000
#define CM_PER_GPIO1_CLKCTRL    0xAC
#define CM_PER_EN               0x2
#define CM_PER_DIS              0x0




// GPIO regs

#define GPIO1_BASE              (volatile unsigned int*) 0x4804C000
#define GPIO_OE                 0x134           // output enable
#define GPIO_DATAOUT            0x13C           // data out register
#define GPIO_SETDATAOUT         0x194           // set reg
#define GPIO_CLEARDATAOUT       0x190           // clear reg
						//
#define USR_0_LED_PIN           21
#define USR_1_LED_PIN           22
#define USR_2_LED_PIN           23
#define USR_3_LED_PIN           24


#endif 

