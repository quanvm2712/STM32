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

//Interrupt edge detection
#define EDGE_RISING		1
#define EDGE_FALLING	0

//External interrupt line
#define EXTI_Line_0			0
#define EXTI_Line_1			1
#define EXTI_Line_2			2
#define EXTI_Line_3			3
#define EXTI_Line_4			4
#define EXTI_Line_5			5
#define EXTI_Line_6			6
#define EXTI_Line_7			7
#define EXTI_Line_8			8
#define EXTI_Line_9			9
#define EXTI_Line_10		10
#define EXTI_Line_11		11
#define EXTI_Line_12		12
#define EXTI_Line_13		13
#define EXTI_Line_14		14
#define EXTI_Line_15		15


void GPIO_Config(void);
void GPIO_EnableClock(uint8_t GPIO_Port);
void GPIO_Mode(uint8_t GPIO_Port, uint8_t GPIO_Pin, uint8_t mode);
void GPIO_Set(uint8_t GPIO_Port, uint8_t GPIO_Pin);
void GPIO_Reset(uint8_t GPIO_Port, uint8_t GPIO_Pin);
void GPIO_Toggle(uint8_t GPIO_Port, uint8_t GPIO_Pin);
void GPIO_Enable_Interrupt(uint8_t port, uint8_t exti_line, uint8_t edge, uint8_t priority);
