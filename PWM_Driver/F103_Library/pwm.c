#include "pwm.h"
#include "gpio.h"

TIM_TypeDef* Timer_global;



/**
 * @brief Enables the clock for the APB bus containing the selected timer.
 * @param Timer: Pointer to the TIM_TypeDef structure representing the timer.
 */
void PWM_enableTimerClock(TIM_TypeDef* Timer){
	if (Timer == TIM1) RCC->APB2ENR |= (1 << 11);
	else if (Timer == TIM2) RCC->APB1ENR |= (1 << 0);
	else if (Timer == TIM3) RCC->APB1ENR |= (1 << 1);
	else if (Timer == TIM4) RCC->APB1ENR |= (1 << 2);
}


/**
 * @brief Enables the counter for the specified timer and waits until the counter overflows.
 *
 * This function sets the Counter Enable (CEN) bit in the Control Register 1 (CR1) of the
 * selected timer to enable the counter. It then waits in a loop until the counter overflows
 * by monitoring the UIF (Update Interrupt Flag) in the Status Register (SR).
 *
 * @param Timer: Pointer to the TIM_TypeDef structure representing the timer.
 */
void PWM_enableCounter(TIM_TypeDef* Timer){
	Timer->CR1 |= (1 << 0); //enable counter
	while (!(Timer->SR & (1<<0))); //wait until counter is overflow
}

/**
	*@brief Init PWM module of STM32
	*@param Timer: Pointer to the TIM_TypeDef structure representing the timer.
					channel: Target PWM output channel
	*/
void PWM_Init(TIM_TypeDef* Timer, uint16_t channel, uint16_t prescaler, uint16_t arrValue, uint16_t CCRxValue){
	Timer_global = Timer;
	PWM_enableTimerClock(Timer);
	GPIO_EnableClock(GPIO_A);
	
	
	switch(channel){
		case PWM_Channel_1:
			Timer->PSC = prescaler - 1;
			Timer->ARR = arrValue;
			Timer->CCR1 = CCRxValue;
			break;
		
		case PWM_Channel_2:
			Timer->PSC = prescaler - 1;
			Timer->ARR = arrValue;
			Timer->CCR2 = CCRxValue;	
			break;
		
		case PWM_Channel_3:
			Timer->PSC = prescaler - 1;
			Timer->ARR = arrValue;
			Timer->CCR3 = CCRxValue;	
			break;

		case PWM_Channel_4:
			Timer->PSC = prescaler - 1;
			Timer->ARR = arrValue;
			Timer->CCR4 = CCRxValue;	
			break;
	}
	

	PWM_ChannelConfig(channel);
}



void PWM_ChannelMode_1(uint8_t channel){
	//PWM Mode 1 for selected channel
	if (channel == PWM_Channel_1) Timer_global->CCMR1 |= (1 << 5) | (1 << 6);
	else if (channel == PWM_Channel_2) Timer_global->CCMR1 |= (1 << 13) | (1 << 14);
	else if (channel == PWM_Channel_3) Timer_global->CCMR2 |= (1 << 5) | (1 << 6);
	else if (channel == PWM_Channel_4) Timer_global->CCMR2 |= (1 << 13) | (1 << 14);
}

void PWM_EnableCCOutput(uint8_t channel){
	if(channel == PWM_Channel_1) Timer_global->CCER |= (1 << 0);
	else if (channel == PWM_Channel_2) Timer_global->CCER |= (1 << 4);
	else if (channel == PWM_Channel_3) Timer_global->CCER |= (1 << 8);
	else if (channel == PWM_Channel_4) Timer_global->CCER |= (1 << 12);
}

void PWM_ChannelConfig(uint8_t channel){
	//PWM Mode 1 for selected channel
	PWM_ChannelMode_1(channel);
	
	//Enable capture/compare output
	PWM_EnableCCOutput(channel);
	
}

void PWM_EnableUpdateGeneration(){
	Timer_global->EGR |= (1 << 0);
}


void PWM_Start(TIM_TypeDef* Timer){
	PWM_EnableUpdateGeneration();
	
	PWM_enableCounter(Timer);
	
	//Enable GPIIO Alternative function
	GPIOA->CRL |= (1 << 25) | (1 << 27);
	GPIOA->CRL &= ~(1 << 26);
	//Timer -> CNT = 0;  //set counter to 0
}

void PWM_SetPrescaler(uint16_t prescalerValue){
	Timer_global->PSC = prescalerValue - 1;
}

void PWM_SetARRReg(uint16_t ARRValue){
	Timer_global->ARR = ARRValue;
}

void PWM_SetCCRxReg(uint16_t CCRxValue, uint16_t channel){
	switch(channel){
		case PWM_Channel_1:
			Timer_global->CCR1 = CCRxValue;
			break;
		
		case PWM_Channel_2:
			Timer_global->CCR2 = CCRxValue;
			break;

		case PWM_Channel_3:
			Timer_global->CCR3 = CCRxValue;
			break;

		case PWM_Channel_4:
			Timer_global->CCR4 = CCRxValue;
			break;		
	}
}
