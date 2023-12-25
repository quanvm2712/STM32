#ifndef __PWM_H
#define __PWM_H

#include "stm32f10x.h"

#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */
#define   	__I     volatile const       /*!< Defines 'read only' permissions */
	
#define	PWM_Channel_1	1
#define	PWM_Channel_2	2
#define	PWM_Channel_3	3
#define	PWM_Channel_4	4


/*-----------Timer-------------*/
/*
- Enable clock for bus line of timer
- PWM internal source
- Select clock prescaler
- Config pwm mode (upcounting)
- PWM Mode 1 for channel
- Config auto reload register (for frequency)
- Config TIMx_CRx for duty cycle
- Enable counter
- Reset counter to 0 before starting PWM

*/

void PWM_ChannelConfig(uint8_t channel);
void PWM_ChannelMode_1(uint8_t channel);
void PWM_EnableCCOutput(uint8_t channel);
void PWM_enableTimerClock(TIM_TypeDef* Timer);


/*-----------------User API---------------------*/
void PWM_Init(TIM_TypeDef* Timer, uint16_t channel, uint16_t prescaler, uint16_t arrValue, uint16_t CCRxValue);
void PWM_ConfigPrescaler(uint16_t value);
void PWM_ConfigARRReg(uint16_t ARRValue);
void PWM_ConfigCCRxReg(uint16_t CCRxvalue);
void PWM_Start(TIM_TypeDef* Timer);



#endif //__PWM_H