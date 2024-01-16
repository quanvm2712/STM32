#include "uart_drive.h"

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

unsigned long USART_BRR(unsigned short usart, unsigned long BR)
{
	unsigned long div = 36000000UL;
	unsigned long dec;
	unsigned long final;
	double frac = 36000000.00;
	double frac2 = 1.00;
	
	if(usart == 1)
	{
	div = 72000000UL;
	frac = 72000000.00;
	}
	div = div / (BR*16);
	frac = 16*((frac / (BR*16))-div);
	dec = frac;
	frac2 = 100*(frac-dec);
	if(frac2>50)
	{
		dec ++;
		if(dec == 16)
		{
			dec = 0;
			div ++;
		}
	}
	
	final = (div<<4);
	final += dec;
	
	return final;
	
}
/*
unsigned long USART_BRR(unsigned short usart, unsigned long BR) {
	//Fractional baud rate generation
	// Tx/Rx baud = fCK / (16 * USARTDIV) 
	//USARTDIV = DIV_Mantissa + DIV_Fraction
	//DIV_Mantissa[15:4], DIV_Fraction[3:0] and devine 16
	
  // Select clock frequency based on USART (usart) type
	unsigned long div = (usart == 1) ? 72000000UL : 36000000UL;
	
    
    // Calculate DIV_Mantissa
    unsigned long div_mantissa = div / (BR * 16);
    
    // Calculate Fractional Part
    unsigned long fractional_part = (div % (BR * 16)) * 16;
    
    // Calculate USARTDIV
    unsigned long frac = fractional_part / 16;
    
    // Rounding the Fractional Part
    frac += (fractional_part % 16 >= 8);  // Rounding
    
    // Combine DIV_Mantissa and Fractional Part to form USARTDIV
    unsigned long final = (div_mantissa << 4) | frac;

    return final;
}
*/