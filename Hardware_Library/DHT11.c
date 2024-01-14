#include "DHT11.h"


void DHT11_SendStartSignal(DHT11_Instance DHT11){
	GPIO_Init(DHT11.GPIO_Port, DHT11.GPIO_Pin, GPIO_OUTPUT);
	
	GPIO_Reset(DHT11.GPIO_Port, DHT11.GPIO_Pin);
	delay_ms(18);
	
	GPIO_Set(DHT11.GPIO_Port, DHT11.GPIO_Pin);
	delay_us(20);
	
	
	/*Process signal from DHT11*/
	GPIO_Init(DHT11.GPIO_Port, DHT11.GPIO_Pin, GPIO_INPUT);
	//Wait until DHT11's start signal end
	uint8_t pin_state;
	do{
		pin_state = GPIO_ReadPin(DHT11.GPIO_Port, DHT11.GPIO_Pin);
	}while(!pin_state);
	
	
	//Wait for DHT11 preparation to send data
	do{
		pin_state = GPIO_ReadPin(DHT11.GPIO_Port, DHT11.GPIO_Pin);
	}while(pin_state);		
}


void DHT11_GetData(DHT11_Instance DHT11, uint8_t* data){
	DHT11_SendStartSignal(DHT11);
	
	//Get first 8 bit 
	for(int count = 0; count < 8; count++){
		
		//Wait for 1 bit's start signal to end
		uint8_t pin_state;
		do{
			pin_state = GPIO_ReadPin(DHT11.GPIO_Port, DHT11.GPIO_Pin);
		}while(!pin_state);			
		delay_us(30);
		
		//Read data
		pin_state = GPIO_ReadPin(DHT11.GPIO_Port, DHT11.GPIO_Pin);
		if(!pin_state)	*data |= (0 << (7-count));
		else	*data |= (1 << (7-count));
		
		//Wait for next 1-bit start signal
		do{
			pin_state = GPIO_ReadPin(DHT11.GPIO_Port, DHT11.GPIO_Pin);
		}while(pin_state);					
	}	
	
}