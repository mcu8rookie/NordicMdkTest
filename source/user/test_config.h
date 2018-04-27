#ifndef __TEST_CONFIG_H__
#define __TEST_CONFIG_H__

#define DEF_TEST_MODULE 5 // 

#if 0 // for note
0
1		for 	leds
2		for 	keys
3		for 	uart
4		for 	iic

#endif

#include "user_board.h"

#define MODULE_LED	1
#define MODULE_KEY	1
#define MODULE_UART 1
#define MODULE_IIC 	1
#define MODULE_MPU6050 1
#define MODULE_TIMER 1


void test_delay(unsigned int ar);


void test_init(void);
void test_mainloop(void);

#endif 


