#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "DHT11.h"

DHT11_Instance DHT11;
uint8_t data[2];

int main(void){
	
	DHT11.GPIO_Port = GPIO_A;
	DHT11.GPIO_Pin = 3;
	
	while(1){
		DHT11_GetValue(DHT11, data);
		delay_ms(100);
	}

	return 0;
}