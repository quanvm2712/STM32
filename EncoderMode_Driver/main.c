#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"
#include "Timer.h"


void led_blink(){
	GPIO_Toggle(GPIO_C, 13);
	delay_ms(100);
}

int main(void){
	SystemInit();
	TIM2_Config();
	
	GPIO_Init(GPIO_A, 6, AFIO_OUTPUT);
	TIM_PWM_Init(TIM3, TIM_Channel_1, 72, 100, 100);
	
	
	//GPIO_Reset(GPIO_C, 13);
	TIM_PWM_Start(TIM3, TIM_Channel_1);
	
	
	while(1){
		led_blink();
	}
	
	return 0;
}