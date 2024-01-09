#ifndef	__DELAY_H
#define __DELAY_H

#include "main.h"

void TIM2_Config(void);
void delay_us(uint16_t time_us);
void delay_ms(uint16_t time_ms);

#endif	//__DELAY_H