#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"
#include "Timer.h"
#include "stdlib.h"
#include "math.h"

#define ENCODER_PPR 30

#define Kp	0.1


int counterVal = 0;
uint16_t position = 0;
uint16_t old_position = 0;
uint16_t encoderPPS = 0;
uint16_t currentFanRPM = 0;
uint16_t ms_count = 0;
int16_t duty_cycle = 100;
float current_error;
float control_signal;


float a = -0.52;
float b = 197.43;
float c = -7992;


void TIM1_UP_IRQHandler(){
	if(TIM1->SR & 0x1){  //Check if interrupt flag is set
		ms_count += 1;
		if(ms_count >= 200){
			position = counterVal / 4;  //Get current position of encoder
			if (position >= old_position){
				encoderPPS = (position - old_position) * 5;  
			}
			currentFanRPM = (encoderPPS * 60) / ENCODER_PPR;
			old_position = position;
			ms_count = 0;
		}
		TIM1->SR &= ~1;  //Reset interrupt flag
	}
}


void TIM1_Config(){
	TIM_EnableTimerClock(TIM1);
	
	//Set prescaler and ARR value (Timer 1 generate interrupt every 1ms)
	TIM1->PSC = 72-1;
	TIM1->ARR = 1000 - 1;
	
	//Enable update interrupt
	TIM1->DIER |= (1 << 0);
	
	NVIC_EnableIRQ(TIM1_UP_IRQn);
	NVIC_SetPriority(TIM1_UP_IRQn, 2);
	
	TIM1->CR1 |= (1 << 0);  //Enable timer 1
}

void led_blink(){
	GPIO_Toggle(GPIO_C, 13);
	delay_ms(100);
}

void Set_InputFilter(){
	TIM3->CCMR1 |= (0b1010 << 4);
	TIM3->CCMR1 |= (0b1010 << 12);
}

void Set_FanSpeed(uint16_t DesiredFanRPM){
	control_signal = (b*(-1) + sqrt(pow(b,2) - 4*a*(c - DesiredFanRPM))) / (2*a);
	
	if(control_signal > 100.0) control_signal = 100.0;
	else if(control_signal < 0.0) control_signal = 0.0;
	
	TIM_SetCCRxReg(TIM3,control_signal, TIM_Channel_1);
}

int main(void){
	SystemInit();
	TIM2_Config();
	TIM1_Config(); //Use timer 1 to generate interrupt every 1ms
	
	//LED Pin init
	GPIO_Init(GPIO_C, 13, GPIO_OUTPUT);
	
	//Init Timer 3 channel 1 IO for PWM functionality
	GPIO_Init(GPIO_A, 6, AFIO_OUTPUT);
	
	//PWM Init and run
	TIM_PWM_Init(TIM3, TIM_Channel_1, 72, 100, 50);
	TIM_PWM_Start(TIM3, TIM_Channel_1);
	
	//Encoder Mode Init and run
	TIM_Encoder_Init(TIM4, SLAVE_EncoderMode_3);
	Set_InputFilter();
	TIM_EncoderStart(TIM4);
	
	while(1){
		counterVal = TIM4->CNT; //Get current counter value from timer 3
		Set_FanSpeed(3000);
		//delay_us(100);
		//led_blink();
	}
	
	return 0;
}