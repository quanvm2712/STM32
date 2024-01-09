#include "delay.h"

void TIM2_Config(void){
	//enable timer2 clock
	RCC->APB1ENR |= (1 << 0);
	
	TIM2->ARR = 0xffff - 1;  //auto-reload register (max value of CNT register)
	TIM2->PSC = 72 - 1;  //prescaler
	
	//enable timer
	TIM2->CR1 |= (1<<0);
	
	while(!(TIM2->SR & (1<<0)));
	
}


void delay_us(uint16_t time_us){
	TIM2->CNT = 0;
	while (TIM2->CNT < time_us);
}

void delay_ms(uint16_t time_ms){
	for (uint16_t i=0; i< time_ms; i++){
		delay_us(1000);
	}
}
