#include "stm32f10x.h"    
#include "gp_drive.h" 
#include "systick_time.h"
#include "uart_drive.h"
char receivedMessage[50];
int main(void)
{
	// Delays function	
	systick_init();
	UART_init(2, 9600);

while(1)
	{
	
		UART_ReceiveString(2, receivedMessage, sizeof(receivedMessage));
		
	}
}