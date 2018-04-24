#ifndef __TEST_CONFIG_C__
#define _TEST_CONFIG_C__

#include "test_config.h"

#if DEF_TEST_MODULE == 0

#elif DEF_TEST_MODULE == 1
	#include "user_gpio.h"
#else

#endif

void test_init(void)
{
	#if DEF_TEST_MODULE == 0
	
	#elif DEF_TEST_MODULE == 1
	gpiomodule_init();
	#else
	
	#endif
}

void test_mainloop(void)
{
	
	#if DEF_TEST_MODULE == 0

	#elif DEF_TEST_MODULE == 1
	gpiomodule_loop();
	#else
	
	#endif
}

#endif //#ifndef __TEST_CONFIG_C__


