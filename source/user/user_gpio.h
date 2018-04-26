#ifndef __USER_GPIO_H__
#define __USER_GPIO_H__

#if 1 //MODULE_LED == 1 || MODULE_KEY == 1

void led_bright(unsigned int lednbr);
void leds_bright(void);
void led_dark(unsigned int lednbr);
void leds_dark(void);
void leds_init(void);
void leds_loop(void);

#endif	// #if MODULE_LED == 1

#if MODULE_KEY == 1
void keys_init(void);
unsigned int keys_getinfo(void);
void keys_loop(void);
#endif	// #if MODULE_KEY == 1

#endif // #ifndef __USER_GPIO_H__

