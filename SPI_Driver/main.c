#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "spi.h"
#include "MAX7219.h"
#include "DMA.h"


uint8_t data[] = "1234";
uint8_t* dataAddr;


int main(void){
	SystemInit();
	
	SPI_Init(SPI1, SPI_Master);
	SPI_SetClockPolarity(SPI1, SPI_Polarity_HIGH);
	
	DMA_Init(DMA1, DMA1_Channel3, DMA_MemoryToPeripheral, DMA_PRIORITY_VERYHIGH, DMA_CIRCULARMODE_ENABLE);
	
	//MAX7219_Clean();
	MAX7219_Init(10, DIGIT_0_TO_7, DECODE_MODE_DISABLE);
	

	

	while(1){
		//MAX7219_PrintString("2712", DIGIT_POSITION_6);
		//delay_ms(1000);
		//MAX7219_PrintInt(2001, 4, DIGIT_POSITION_5);
		//delay_ms(1000);

		CS_Set();
		SPI_Transmit_DMA(SPI1, data, 4);
		CS_Reset();
		
		delay_ms(10);
	}
}









