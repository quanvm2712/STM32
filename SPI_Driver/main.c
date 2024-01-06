#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "spi.h"

#define CS_Set()		GPIO_Reset(GPIO_A, 4)
#define CS_Reset()	GPIO_Set(GPIO_A, 4)

#define DIGIT_0_ONLY		0
#define DIGIT_0_TO_1		1
#define DIGIT_0_TO_2		2
#define DIGIT_0_TO_3		3
#define DIGIT_0_TO_4		4
#define DIGIT_0_TO_5		5
#define DIGIT_0_TO_6		6
#define DIGIT_0_TO_7		7


void SPI_SendData(uint8_t* data){
	CS_Set();
	SPI_Transmit(SPI1, data, 1);
	CS_Reset();
}

void MAX7219_SendData(uint8_t address, uint8_t data){
	SPI_SendData(&address);
	SPI_SendData(&data);
}

void MAX7219_PowerOn(){
	MAX7219_SendData(0x0C, 0x01);
}

void MAX7219_SetIntensity(uint8_t Intensity){
		MAX7219_SendData(0x0A, Intensity);
}

void MAX7219_SetScanLimit(uint8_t ScanLimit){
	MAX7219_SendData(0x0B, ScanLimit);
}

void MAX7219_Init(uint8_t Intensity, uint8_t ScanLimit){
	MAX7219_PowerOn();
	MAX7219_SetIntensity(Intensity);
	MAX7219_SetScanLimit(ScanLimit);
}

int main(void){
	SystemInit();
	TIM2_Config();
	
	SPI_IO_Init();
	SPI_Init(SPI1, SPI_Master);

	MAX7219_Init(10, DIGIT_0_TO_3);
	/*
	GPIO_Reset(GPIO_A, 4);
	SPI_Transmit(SPI1, &data, 1);
	GPIO_Set(GPIO_A, 4);
	*/
	
	
	while(1){
		
	}
}









