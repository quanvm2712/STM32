#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "spi.h"




int main(void){
	
	SystemInit();
	TIM2_Config();

	SPI_Config();
	SPI1_Transmit(0x7777);

	
	while(1){

	}
}









