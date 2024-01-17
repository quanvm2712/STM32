#include "stm32f10x.h"    
#include "gp_drive.h" 
#include "systick_time.h"
#include "uart_drive.h"

char data[50];
char sendData[] = "Hello from STM32";


void USART2_IRQHandler(){
		if(USART2->SR & (1<<5)){
			USART2_ReceiveString(data, 5); 
		}
}

void UART_InterruptConfig(){
	NVIC_EnableIRQ(USART2_IRQn);
	NVIC_SetPriority(USART2_IRQn, 1);
}

int main(void)
{
	// Delays function	
	systick_init();
	UART_init();
	USART2->CR1 |= (1 << 5);		//Enable interrupt on RX event
	UART_InterruptConfig();

while(1)
	{
		//USART2_ReceiveString(data, 10);
		DelayMs(1000);
		UART_SendString(sendData);
		
		
	}
}