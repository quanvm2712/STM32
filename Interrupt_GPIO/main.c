#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"


void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
void EXTI1_IRQHandler(void);


int main(void){
	
	SystemInit();
	TIM2_Config();

	//Config GPIO PC13 as output
	GPIO_EnableClock(GPIO_C);
	GPIO_Mode(GPIO_C, 13, OUTPUT);

	
	//config GPIO EXTI

	//GPIO_EnableClock(GPIO_C);
 	GPIO_Mode(GPIO_C, 15, INPUT);
	
	GPIO_Enable_Interrupt(GPIO_C, EXTI_Line_15, EDGE_FALLING, 0);
	

	
	while(1){

	}
}


void EXTI1_IRQHandler(void){
		if (EXTI->PR & (1 << 1)){
			GPIO_Toggle(GPIO_C, 13); 
			EXTI->PR |= (1 << 1);  //clear pending interrupt flag			
		}
}




void EXTI9_5_IRQHandler(void){
		if (EXTI->PR & (1 << 9)){ 
			GPIO_Toggle(GPIO_C, 13); 
			EXTI->PR |= (1 << 9);  //clear pending interrupt flag			
		}	
}

void EXTI15_10_IRQHandler(void){
		if (EXTI->PR & (1 << 15)){ 
			GPIO_Toggle(GPIO_C, 13); 
			EXTI->PR |= (1 << 15);  //clear pending interrupt flag			
		}		
}





