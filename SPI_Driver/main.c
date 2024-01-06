#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "spi.h"

#define CS_Set()		GPIO_Reset(GPIO_A, 4)
#define CS_Reset()	GPIO_Set(GPIO_A, 4)


void SPI_SendData(uint8_t* data){
	CS_Set();
	SPI_Transmit(SPI1, data, 1);
	CS_Reset();
}

int main(void){
	SystemInit();
	TIM2_Config();
	
	SPI_IO_Init();
	SPI_Init(SPI1, SPI_Master);

	
	/*
	GPIO_Reset(GPIO_A, 4);
	SPI_Transmit(SPI1, &data, 1);
	GPIO_Set(GPIO_A, 4);
	*/
	uint8_t data = 0x21;
	SPI_SendData(&data);
	
	data = 0x22;
	SPI_SendData(&data);
	
	while(1){
		
	}
}









