#ifndef __USER_UART_C__
#define __USER_UART_C__

#include "test_config.h"

#if MODULE_UART == 1


#include "user_uart.h"

#define UART_TX_BUF_SIZE 1024
#define UART_RX_BUF_SIZE 1024
void uart_error_handle(app_uart_evt_t *p_event)
{
	if(p_event->evt_type == APP_UART_COMMUNICATION_ERROR)
	{
		APP_ERROR_HANDLER(p_event->data.error_communication);
	}
	if(p_event->evt_type == APP_UART_FIFO_ERROR)
	{
		APP_ERROR_HANDLER(p_event->data.error_code);
	}
}
void uart_config(void)
{
	unsigned int err_code;
	const app_uart_comm_params_t comm_params = 
	{
		RX_PIN_NUMBER,
		TX_PIN_NUMBER,
		RTS_PIN_NUMBER,
		CTS_PIN_NUMBER,
		APP_UART_FLOW_CONTROL_DISABLED,
		false,
		UART_BAUDRATE_BAUDRATE_Baud115200
	};
	APP_UART_FIFO_INIT(&comm_params,
						UART_RX_BUF_SIZE,
						UART_TX_BUF_SIZE,
						uart_error_handle,
						APP_IRQ_PRIORITY_LOW,
						err_code);
	APP_ERROR_CHECK(err_code);
}
void user_uart_init(void)
{
	uart_config();
}
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

void user_uart_loop(void)
{
	printf("\r\nnrf52832 mcu uart running...\r\n");
	local_delay(1000);
}
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


