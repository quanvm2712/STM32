#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "IWDG.h"



void LED_Blink(void){
	GPIO_Toggle(GPIO_C, 13);
	delay_ms(100);
	GPIO_Toggle(GPIO_C, 13);
	delay_ms(100);	
}
int main(void){
	SystemInit();
	
	//Init GPIO
	GPIO_Init(GPIO_C, 13, GPIO_OUTPUT);
	
	
	//Init watchdog
	IWDG_Init(IWDG_DIV_64, 1250);
	
	LED_Blink();

	while(1){
		
	}
}