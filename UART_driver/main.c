#include "stm32f10x.h"    
#include "gp_drive.h" 
#include "systick_time.h"

char receivedData;
int main(void)
{
// Delays function	
systick_init();

	//-----------Init UART ------------///
	// Enable the Alternate Function for PINs
		RCC->APB2ENR |= (1 << 0);
	// Enable UART2
		RCC->APB1ENR |=0x20000;
	
	// Enable the related PINs
	init_GP(PA,2,OUT50,O_AF_PP);
	init_GP(PA,3,IN,I_F);
	
	// Setup the baude rate for 9600 bps
	USART2->BRR = 0xEA6; 
	// Enable Uart Transmit
	USART2->CR1 |= 8;
	// Enable Uart Recive
	USART2->CR1 |= 4;
	// Enable Uart
	USART2->CR1 |= 0x2000;


while(1)
	{
	
		// Recieve Char
		while((USART2->SR & 0x20) == 0x00);
		receivedData = USART2->DR;
		
		
		
	}
}