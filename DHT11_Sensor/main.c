#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "DHT11.h"

DHT11_Instance DHT11;

int main(void){
	
	DHT11.GPIO_Port = GPIO_A;
	DHT11.GPIO_Pin = 3;
	
	//DHT11_SendStartSignal(DHT11);
	
	
	uint8_t data;
	DHT11_GetData(DHT11, &data);
	
	
	return 0;
}