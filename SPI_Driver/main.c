#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "spi.h"
#include "MAX7219.h"



int main(void){
	SystemInit();
	TIM2_Config();
	
	SPI_IO_Init();
	SPI_Init(SPI1, SPI_Master);

	MAX7219_Init(10, DIGIT_0_TO_7, DECODE_MODE_DISABLE);

	/*
	MAX7219_SendData(0x1, DigitCodes[3]);
	MAX7219_SendData(0x2, DigitCodes[1]);
	MAX7219_SendData(0x3, DigitCodes[0]);
	MAX7219_SendData(0x4, DigitCodes[1]);	
	*/
	

	//MAX7219_PrintInt(200);
	
	while(1){
		MAX7219_PrintString("2712", 6);
		delay_ms(1000);
		MAX7219_PrintInt(2001, 4, 5);
		delay_ms(1000);
	}
}









