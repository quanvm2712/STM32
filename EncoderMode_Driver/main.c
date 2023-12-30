#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"
#include "Timer.h"

int counterVal = 0;

void led_blink(){
	GPIO_Toggle(GPIO_C, 13);
	delay_ms(100);
}

int main(void){
	SystemInit();
	TIM2_Config();
	
	/*
	GPIO_Init(GPIO_A, 6, AFIO_OUTPUT);
	TIM_PWM_Init(TIM3, TIM_Channel_1, 72, 100, 50);
	
	TIM_PWM_Start(TIM3, TIM_Channel_1);
	*/
	
	GPIO_Init(GPIO_B, 6, GPIO_INPUT);
	GPIO_Init(GPIO_B, 7, GPIO_INPUT);
	
	TIM_EncoderMode_Init(TIM4, SLAVE_EncoderMode_3);
	TIM_EncoderStart(TIM4);
	
	while(1){
		counterVal = TIM4->CNT;
	}
	
	return 0;
}