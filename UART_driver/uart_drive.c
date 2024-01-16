#include "uart_drive.h"
#include "systick_time.h"
void UART_init(unsigned short usart, unsigned long baud_rate) 
{
	//USART 1 using clock speed 72Mhz, USART 2 and 3 using 36Mhz
	//USART3 -> PB10 (Tx) and PB11 (Rx)
	//USART2 -> PA2 (Tx) and PA3 (Rx)
	//USART1 -> PA9 (Tx) and PA10(Rx)
	unsigned long BRR_cal;
	BRR_cal = USART_BRR(usart, baud_rate);
	
	// Enable the Alternate Function for PINs
	RCC->APB2ENR |= (1 << 0);
	
	if (usart == 1)
	{
		RCC->APB1ENR |= (1 << 14); // enable USART1
		
		//Enable related PINs
		init_GP(PA, 9, OUT50, O_AF_PP);
		init_GP(PA, 10, IN, I_F);
		
		//setup baud rate
		USART1->BRR = BRR_cal;
		//Enable USART transmit
		USART1->CR1 |= (1 << 3);
		//Enable USART receive
		USART1->CR1 |= (1 << 2);
		//Enable USART
		USART1->CR1 |= (1 << 13);
		
	}
	else if (usart == 2)
	{
		
		
		RCC->APB1ENR |= (1 << 17); // enable USART2
		
		//Enable related PINs
		init_GP(PA, 2, OUT50, O_AF_PP);
		init_GP(PA, 3, IN, I_F);
		
		//setup baud rate
		USART2->BRR = BRR_cal;
		//Enable USART transmit
		USART2->CR1 |= (1 << 3);
		//Enable USART receive
		USART2->CR1 |= (1 << 2);
		//Enable USART
		USART2->CR1 |= (1 << 13);
		
		
	}
	else if (usart == 3)
	{
		
		RCC->APB1ENR |= (1 << 18);// enable USART3
		
		//Enable related PINs
		init_GP(PB, 10, OUT50, O_AF_PP);
		init_GP(PB, 11, IN, I_F);
		
		//setup baud rate
		USART3->BRR = BRR_cal;
		//Enable USART transmit
		USART3->CR1 |= (1 << 3);
		//Enable USART receive
		USART3->CR1 |= (1 << 2);
		//Enable USART
		USART3->CR1 |= (1 << 13);
		
	
	}
	
}

unsigned long USART_BRR(unsigned short usart, unsigned long baud_rate)
{
	
	unsigned long div = 36000000UL; // clock frequency
	unsigned long dec;
	unsigned long final;
	double frac = 36000000.00;// fractional part
	double frac2 = 1.00; // round decimals
	
	if(usart == 1)
	{
	div = 72000000UL;
	frac = 72000000.00;
	}
	div = div / (baud_rate*16);
	frac = 16*((frac / (baud_rate*16))-div);
	dec = frac;
	frac2 = 100*(frac-dec);
	if(frac2>50)
	{
		dec++;
		if(dec == 16)
		{
			dec = 0;
			div++;
		}
	}
	
	final = (div<<4);
	final += dec;
	
	return final;
	
}
char UART_RX(unsigned short usart)
{
	char receivedData;
	if (usart == 1)
	{
		while (!(USART1->SR & (1 << 5))); // wait RXNE set
		receivedData = USART1->DR;
	}
	else if (usart == 2)
	{
		while (!(USART2->SR & (1 << 5))); // wait RXNE set
		receivedData = USART2->DR;
	}
	else if (usart == 3)
	{
		while (!(USART3->SR & (1 << 5))); // wait RXNE set
		receivedData = USART3->DR;
	}
	return receivedData;
}
void UART_TX(unsigned short usart, char transmitData)
{
	if (usart == 1)
	{
		while (!(USART1->SR & (1 << 7))); // wait TXE set
		USART1->DR = transmitData;
	}
	else if (usart == 2)
	{
		while (!(USART2->SR & (1 << 7))); // wait TXE set
		USART2->DR = transmitData;
	}
	else if (usart == 3)
	{
		while (!(USART3->SR & (1 << 7))); // wait TXE set
		USART3->DR = transmitData;
	}
}
void UART_SendString(unsigned short usart, char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		UART_TX(usart, str[i]);
		i++;
	}
}


void UART_ReceiveString(unsigned short usart, char *buffer, int bufferSize)
{
	int i = 0;
	char received;
	
	//Read char until buffer is full or newline character is received
	do
	{
		received = UART_RX(usart);
		buffer[i] = received;
		i++;
	}while (received != '\n' && i < bufferSize - 1);
	//set null is the last pos
	buffer[i] = '\0';
}










