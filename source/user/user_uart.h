#ifndef __USER_UART_H__
#define __USER_UART_H__

#if MODULE_UART == 1
#include "app_uart.h"
void uart_error_handle(app_uart_evt_t *p_event);
void uart_config(void);

void user_uart_init(void);
void user_uart_loop(void);


#if 0
void Uart_ModuleInit(void)
{
	Communication_Init(&Comm_Uart1);
	uart_config();
	printf("\r\n\r\n123------------------------------");
	printf("\r\nNRF52832 MCU Start running....\r\n");
	printf("Uart0_115200.123\r\n");

	printf("\r\n\r\n456------------------------------");
	printf("\r\nNRF52832 MCU Start running....\r\n");
	printf("Uart0_115200.456\r\n");
	
}

void Uart_MainProcess(void)
{
	
}

#endif
#endif
#endif // #ifndef __USER_UART_C__


