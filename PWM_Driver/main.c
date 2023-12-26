#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "pwm.h"

void blink_led(){
	GPIO_Toggle(GPIO_A, 6);
	delay_ms(100);
}
	
void PWM_Config(){
	/*
	PWM_ConfigPrescaler(72);	//scaled clock for timer 3 to 1MHz
	PWM_ConfigARRReg(100); 		//PWM Freq = 10kHz
	PWM_ConfigCCRxReg(90);
	*/
	PWM_Init(TIM3, PWM_Channel_1, 72, 100, 1);
}

void PWM_ConfigPin(){
	GPIO_EnableClock(GPIO_A);
	GPIO_Mode(GPIO_A, 6, OUTPUT);	
}


int main(void){
	SystemInit();
	
	//GPIO Config
	GPIO_EnableClock(GPIO_C);
	GPIO_Mode(GPIO_C, 13, OUTPUT);
	//PWM_ConfigPin();
	
	//Timer2 Config
	TIM2_Config();
	
	//PWM Config
	PWM_Config();
	PWM_Start(TIM3);
	
	
	uint8_t CCRxVal = 0;
	
	while(1){
		PWM_SetCCRxReg(CCRxVal, PWM_Channel_1);
		PWM_Start(TIM3);
		CCRxVal += 10;
		
		if(CCRxVal > 100) CCRxVal = 0;
		delay_ms(200);
		
	}
	return 0;
}