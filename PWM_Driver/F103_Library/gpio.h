#ifndef GPIO_H
#define	GPIO_H

#include "stm32f10x.h"

//GPIO Port 
#define AFIOEN		0
#define	GPIO_A		2
#define	GPIO_B		3
#define	GPIO_C		4
#define	GPIO_D		5
#define	GPIO_E		6


//IO mode
#define	GPIO_OUTPUT		0
#define GPIO_INPUT		1
#define AFIO_OUTPUT		2





void GPIO_EnableClock(uint8_t GPIO_Port);
void GPIO_Init(uint8_t GPIO_Port, uint8_t GPIO_Pin, uint8_t mode);
void GPIO_Set(uint8_t GPIO_Port, uint8_t GPIO_Pin);
void GPIO_Reset(uint8_t GPIO_Port, uint8_t GPIO_Pin);
void GPIO_Toggle(uint8_t GPIO_Port, uint8_t GPIO_Pin);

#endif //GPIO_H