#include "stm32f10x.h"  
#include "gp_drive.h" 

unsigned long USART_BRR(unsigned short usart, unsigned long baud_rate);
void UART_init(unsigned short usart, unsigned long baud_rate);