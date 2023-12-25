#include	"spi.h"
/*
Note:
1. TXE flag should be set to 1 prior to write operation to Tx buffer
2. 
*/
void SPI_Config(void){
	//1. Enable clock for spi
	//2. Config hardware slave select
	//3. Config Clock phase and clock polarity
	//2. Config in master mode
	//3. Enable SPI
	
	RCC->APB2ENR |= (1 << 12);  //enable clock for spi1 periphs
	
	SPI->CR1 |= (1 << 4);  //baudrate = clk/8
	
	SPI->CR1 |= (1 << 11);	//16-bit data frame
	
	SPI->CR2 |= (1 << 2);  //slave select is enabled
	
	SPI->CR1 |= (1 << 2);  //master config
	
	SPI->CR1 |= (1 << 6); //enable spi
	
}


void SPI1_Transmit(uint16_t data){
	//3. Wrtie data to data register
	//4/ Wait until TXE=1, BSY=0 to finish transmission
	
	if (SPI->SR & (1 << 1)){  //check if txe flag is set
		SPI->DR = data;  //write data to tx buffer, txe flag will be reset
		uint8_t sr_data = SPI->SR & (1 << 1);
		
	}
	
	while((SPI->SR & (1 << 1)) == 0); //wait until txe flag is set
	while((SPI->SR & (1 << 7))); //wait until busy flag is reset
	
}
