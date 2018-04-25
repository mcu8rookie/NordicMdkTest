#ifndef __USER_BOARD_H__
#define __USER_BOARD_H__

// define leds gpio

#define LED_START 17
#define LED1 17
#define LED2 18
#define LED3 19
#define LED4 20
#define LED_END 20
#define LED_ALLBITMASK 0x001e0000

// define keys gpio
#define KEY_START 13
#define KEY1	13
#define KEY2	14
#define KEY3	15
#define KEY4	16
#define KEY_END	16
#define KEY_ALLBITMASK	0x0001e000

#define KEY_SPEC 21
#define TOUCHKEY 3

#define RX_PIN_NUMBER  8
#define TX_PIN_NUMBER  6
#define CTS_PIN_NUMBER 7
#define RTS_PIN_NUMBER 5
#define HWFC           true


#endif // #ifndef __USER_BOARD_H__



