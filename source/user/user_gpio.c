#ifndef __USER_GPIO_C__

#define __USER_GPIO_C__

#include "test_config.h"
#if MODULE_LED == 1


//\components\drivers_nrf\hal\nrf_gpio.h
#include "nrf_gpio.h"

#include "user_gpio.h"

void led_bright(unsigned int lednbr)
{
	nrf_gpio_pin_clear(lednbr);
}
void leds_bright(void)
{
	led_bright(LED1);
	led_bright(LED2);
	led_bright(LED3);
	led_bright(LED4);
}
void led_dark(unsigned int lednbr)
{
	nrf_gpio_pin_set(lednbr);
}
void leds_dark(void)
{
	led_dark(LED1);
	led_dark(LED2);
	led_dark(LED3);
	led_dark(LED4);
}

void led_init(unsigned int lednbr)
{
	nrf_gpio_cfg_output(lednbr);
	led_dark(lednbr);
}
void leds_init(void)
{
	led_init(LED1);
	led_init(LED2);
	led_init(LED3);
	led_init(LED4);
}

void leds_loop(void)
{
	test_delay(1000);
	leds_dark();
	test_delay(1000);
	leds_bright();
}

#endif // #if MODULE_LED == 1

#if MODULE_KEY == 1
void keys_init(void)
{
	nrf_gpio_cfg_input(KEY1,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(KEY2,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(KEY3,NRF_GPIO_PIN_PULLUP);
	nrf_gpio_cfg_input(KEY4,NRF_GPIO_PIN_PULLUP);
}
unsigned int keys_getinfo(void)
{
	unsigned int tmp = 0;
	if(nrf_gpio_pin_read(KEY1) == 0)
	{
		tmp |= 0x01;
	}
	if(nrf_gpio_pin_read(KEY2) == 0)
	{
		tmp |= 0x02;
	}
	if(nrf_gpio_pin_read(KEY3) == 0)
	{
		tmp |= 0x04;
	}
	if(nrf_gpio_pin_read(KEY4) == 0)
	{
		tmp |= 0x08;
	}
	return tmp;
}
void keys_loop(void)
{
	unsigned int keyinfo = 0;
	keyinfo = keys_getinfo();
	if((keyinfo & 0x01) == 0x01)
	{
		led_bright(LED1);
	}
	else
	{
		led_dark(LED1);
	}
	if((keyinfo & 0x02) == 0x02)
	{
		led_bright(LED2);
	}
	else
	{
		led_dark(LED2);
	}
	if((keyinfo & 0x04) == 0x04)
	{
		led_bright(LED3);
	}
	else
	{
		led_dark(LED3);
	}
	if((keyinfo & 0x08) == 0x08)
	{
		led_bright(LED4);
	}
	else
	{
		led_dark(LED4);
	}
}
#endif	// #if MODULE_KEY == 1

#endif //#ifndef __USER_GPIO_C__


