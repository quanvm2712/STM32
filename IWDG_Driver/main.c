#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "IWDG.h"

void IWDG_Config(void){
	//SW Reset every 500ms
	IWDG_SetPrescaler(IWDG_DIV_8);
	IWDG_SetReloadValue(2500);
}

void LED_Blink(void){
	GPIO_Toggle(GPIO_C, 13);
	delay_ms(50);
	GPIO_Toggle(GPIO_C, 13);
	delay_ms(50);	
}
int main(void){
	SystemInit();
	TIM2_Config();
	
	//Init GPIO
	GPIO_Init(GPIO_C, 13, GPIO_OUTPUT);
	
	
	//Init watchdog
	IWDG_Config();
	IWDG_Start();
	
	LED_Blink();

	while(1){
		
	}
}