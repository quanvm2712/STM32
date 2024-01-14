#ifndef	__DHT11_H
#define	__DHT11_H

#include "gpio.h"
#include "delay.h"

typedef struct{
	uint8_t GPIO_Port;
	uint8_t GPIO_Pin;
}DHT11_Instance;


void DHT11_SendStartSignal(DHT11_Instance DHT11);
void DHT11_GetData(DHT11_Instance DHT11, uint8_t* data);
#endif	//__DHT11_H