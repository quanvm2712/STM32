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
	
	while(1){
		MAX7219_PrintString("2712", DIGIT_POSITION_6);
		delay_ms(1000);
		MAX7219_PrintInt(2001, 4, DIGIT_POSITION_5);
		delay_ms(1000);
	}
}









