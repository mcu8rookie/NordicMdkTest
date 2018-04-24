#ifndef __USER_GPIO_C__

#define __USER_GPIO_C__

#include "test_config.h"
#if DEF_TEST_MODULE == 1


//\components\drivers_nrf\hal\nrf_gpio.h
#include "nrf_gpio.h"

#include "user_gpio.h"
static void local_delay(unsigned int ar)
{
	unsigned int i,j;
	for(i=0;i<ar;i++)
	{
		for(j=0;j<1000;j++)
		{

		}
	}
}
static void leds_light(void)
{
	nrf_gpio_pin_set(LED1);
	nrf_gpio_pin_set(LED2);
	nrf_gpio_pin_set(LED3);
	nrf_gpio_pin_set(LED4);
}
static void leds_dark(void)
{
	nrf_gpio_pin_clear(LED1);
	nrf_gpio_pin_clear(LED2);
	nrf_gpio_pin_clear(LED3);
	nrf_gpio_pin_clear(LED4);
}

void gpiomodule_init(void)
{
	nrf_gpio_cfg_output(LED1);
	nrf_gpio_cfg_output(LED2);
	nrf_gpio_cfg_output(LED3);
	nrf_gpio_cfg_output(LED4);
	nrf_gpio_pin_set(LED1);
	nrf_gpio_pin_clear(LED2);
	nrf_gpio_pin_set(LED3);
	nrf_gpio_pin_clear(LED4);
}

void gpiomodule_loop(void)
{
	local_delay(1000);
	leds_dark();
	local_delay(2000);
	leds_light();
}

#endif // #if DEF_TEST_MODULE == 1
#endif //#ifndef __USER_GPIO_C__


