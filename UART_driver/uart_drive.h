#include "stm32f10x.h"  
#include "gp_drive.h" 

unsigned long USART_BRR(unsigned short usart, unsigned long baud_rate);
void UART_init(unsigned short usart, unsigned long baud_rate);
char UART_RX(unsigned short usart);
void UART_TX(unsigned short usart, char transmitData);
void UART_SendString(unsigned short usart, char str[]);
void UART_ReceiveString(unsigned short usart, char *buffer, int bufferSize);