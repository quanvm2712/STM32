#include "stm32f10x.h"    
#include "gp_drive.h" 
#include "systick_time.h"
#include "uart_drive.h"

char data[50];
char sendData[] = "Hello from STM32";

int main(void)
{
	// Delays function	
	systick_init();
	UART_init();



while(1)
	{
		USART2_ReceiveString(data, 10);
		DelayMs(1000);
		UART_SendString(sendData);
		
	}
}