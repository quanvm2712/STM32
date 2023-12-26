#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "pwm.h"
	

int main(void){
	SystemInit();
	
	//Timer2 Config
	TIM2_Config();

	//GPIO config
	GPIO_Init(GPIO_A, 6, AFIO_OUTPUT);
	
	//PWM Config
	PWM_Init(TIM3, PWM_Channel_1, 72, 100, 1);
	
	//Init CCRxVal
	uint8_t CCRxVal = 0;
	
	while(1){
		//Run PWM with specific duty cycle value
		PWM_SetCCRxReg(CCRxVal, PWM_Channel_1);
		PWM_Start(TIM3);
		
		//Update duty cycle
		CCRxVal += 10;
		if(CCRxVal > 100) CCRxVal = 0;
		
		delay_ms(200);


		
		
	}
	return 0;
}