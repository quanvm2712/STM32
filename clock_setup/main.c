#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"


int main(void){
	
	SystemInit();
	TIM2_Config();
	//GPIO_Config();

	GPIO_EnableClock(GPIO_C);
	GPIO_Mode(GPIO_C, 13, OUTPUT);

	/*
	RCC->APB2ENR |= (1 << 0); //ENABLE AFIO clock
	AFIO->MAPR |= (1 << 25);//JTAG-DP Disabled and SW-DP Enabled 010 
	
	RCC->APB2ENR |= ( 1 << 3 ); //enable clock for gpiob
	GPIOB->CRL = 0;
	
	//output mode
	GPIOB->CRL |=(1 << 13); //output mode
*/
	

	
	while(1){
		/*
		GPIO_Set(GPIO_C, 13);
		delay_ms(100);
		GPIO_Reset(GPIO_C, 13);
		delay_ms(100);
		*/
		
		GPIO_Toggle(GPIO_C, 13);
		delay_ms(100);
	}
	
	
	
	
}
