#ifndef __TEST_CONFIG_C__
#define _TEST_CONFIG_C__

#include "test_config.h"

#if DEF_TEST_MODULE == 0
	#error "DEF_TEST_MODULE == 0 means you would not run any function."
#elif DEF_TEST_MODULE == 1
	#include "user_gpio.h"
#elif DEF_TEST_MODULE == 2
	#include "user_gpio.h"
#elif DEF_TEST_MODULE == 3
	#include "user_gpio.h"
	#include "user_uart.h"
#else
	#error "DEF_TEST_MODULE == M means you would not define correct value."
#endif

void test_init(void)
{
	#if DEF_TEST_MODULE == 0
	
	#elif DEF_TEST_MODULE == 1
	leds_init();
	#elif DEF_TEST_MODULE == 2
	leds_init();
	keys_init();
	#elif DEF_TEST_MODULE == 3
	leds_init();
	keys_init();
	user_uart_init();
	
	#else
	
	#endif
}

void test_mainloop(void)
{
	
	#if DEF_TEST_MODULE == 0

	#elif DEF_TEST_MODULE == 1
	leds_loop();
	#elif DEF_TEST_MODULE == 2
	keys_loop();
	#elif DEF_TEST_MODULE == 3
	keys_loop();
	user_uart_loop();
	#else
	
	#endif
}

#endif //#ifndef __TEST_CONFIG_C__


