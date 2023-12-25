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
#define	OUTPUT		0
#define INPUT			1

void GPIO_Config(void);
void GPIO_EnableClock(uint8_t GPIO_Port);
void GPIO_Mode(uint8_t GPIO_Port, uint8_t GPIO_Pin, uint8_t mode);
void GPIO_Set(uint8_t GPIO_Port, uint8_t GPIO_Pin);
void GPIO_Reset(uint8_t GPIO_Port, uint8_t GPIO_Pin);
void GPIO_Toggle(uint8_t GPIO_Port, uint8_t GPIO_Pin);

#endif //GPIO_H