#include "gpio.h"


void GPIO_Config(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; //enable gpio port C clock
	GPIOC->CRH |= (0<<21) | (1<<20);  //output mode 10mhz, push pull
	
}

void GPIO_EnableClock(uint8_t GPIO_Port){
		RCC->APB2ENR |= (1<<GPIO_Port);
}

void GPIO_Mode(uint8_t GPIO_Port, uint8_t GPIO_Pin, uint8_t mode){
	RCC->APB2ENR |= (1 << 0); //ENABLE AFIO clock
	AFIO->MAPR |= (1 << 25);//JTAG-DP Disabled and SW-DP Enabled 010 
	switch(GPIO_Port){
		
		
		case GPIO_A:
			if(GPIO_Pin < 8){
	      if(mode == INPUT){
					GPIOA->CRL |= (1<< (GPIO_Pin + 3 * (GPIO_Pin + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = (GPIO_Pin * 4);
					//10mhz output mode, push-pull
					GPIOA->CRL |= (1 << config_bit);  //10mhz output mode, push-pull
					GPIOA->CRL &= ~(1 << (config_bit + 1));
					GPIOA->CRL &= ~(1 << (config_bit + 2));
					
				}
			}
			else if ((GPIO_Pin >= 8) & (GPIO_Pin < 16)){
				
				if(mode == INPUT){
					GPIOA->CRH |= (1<<((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8 + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8));
					//10mhz output mode, push-pull
					GPIOA->CRH |= (1 << config_bit);  
					GPIOA->CRH &= ~(1 << (config_bit + 1));
					GPIOA->CRH &= ~(1 << (config_bit + 2));
					
				}			
			}
			break;
			
			
			

		case GPIO_B:
			if(GPIO_Pin < 8){
	      if(mode == INPUT){
					GPIOB->CRL |= (1<< (GPIO_Pin + 3 * (GPIO_Pin + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = (GPIO_Pin * 4);
					//10mhz output mode, push-pull
					GPIOB->CRL |= (1 << config_bit);  //10mhz output mode, push-pull
					GPIOB->CRL &= ~(1 << (config_bit + 1));
					GPIOB->CRL &= ~(1 << (config_bit + 2));
					
				}
			}
			else if ((GPIO_Pin >= 8) & (GPIO_Pin < 16)){
				
				if(mode == INPUT){
					GPIOB->CRH |= (1<<((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8 + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8));
					//10mhz output mode, push-pull
					GPIOB->CRH |= (1 << config_bit);  
					GPIOB->CRH &= ~(1 << (config_bit + 1));
					GPIOB->CRH &= ~(1 << (config_bit + 2));
					
				}			
			}
			break;
			
			
			
			
		case GPIO_C:
			if(GPIO_Pin < 8){
	      if(mode == INPUT){
					GPIOC->CRL |= (1<< (GPIO_Pin + 3 * (GPIO_Pin + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = (GPIO_Pin * 4);
					//10mhz output mode, push-pull
					GPIOC->CRL |= (1 << config_bit);  //10mhz output mode, push-pull
					GPIOC->CRL &= ~(1 << (config_bit + 1));
					GPIOC->CRL &= ~(1 << (config_bit + 2));
					
				}
			}
			else if ((GPIO_Pin >= 8) & (GPIO_Pin < 16)){
				
				if(mode == INPUT){
					GPIOC->CRH |= (1<<((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8 + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8));
					//10mhz output mode, push-pull
					GPIOC->CRH |= (1 << config_bit);  
					GPIOC->CRH &= ~(1 << (config_bit + 1));
					GPIOC->CRH &= ~(1 << (config_bit + 2));
					
				}			
			}
			break;
			
			
			
		case GPIO_D:
			if(GPIO_Pin < 8){
	      if(mode == INPUT){
					GPIOD->CRL |= (1<< (GPIO_Pin + 3 * (GPIO_Pin + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = (GPIO_Pin * 4);
					//10mhz output mode, push-pull
					GPIOD->CRL |= (1 << config_bit);  //10mhz output mode, push-pull
					GPIOD->CRL &= ~(1 << (config_bit + 1));
					GPIOD->CRL &= ~(1 << (config_bit + 2));
					
				}
			}
			else if ((GPIO_Pin >= 8) & (GPIO_Pin < 16)){
				
				if(mode == INPUT){
					GPIOD->CRH |= (1<<((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8 + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8));
					//10mhz output mode, push-pull
					GPIOD->CRH |= (1 << config_bit);  
					GPIOD->CRH &= ~(1 << (config_bit + 1));
					GPIOD->CRH &= ~(1 << (config_bit + 2));
					
				}			
			}
			break;
			
			
			
			
		case GPIO_E:
			if(GPIO_Pin < 8){
	      if(mode == INPUT){
					GPIOE->CRL |= (1<< (GPIO_Pin + 3 * (GPIO_Pin + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = (GPIO_Pin * 4);
					//10mhz output mode, push-pull
					GPIOE->CRL |= (1 << config_bit);  //10mhz output mode, push-pull
					GPIOE->CRL &= ~(1 << (config_bit + 1));
					GPIOE->CRL &= ~(1 << (config_bit + 2));
					
				}
			}
			else if ((GPIO_Pin >= 8) & (GPIO_Pin < 16)){
				
				if(mode == INPUT){
					GPIOE->CRH |= (1<<((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8 + 1))); //Input with pull-up/pull-down
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8));
					//10mhz output mode, push-pull
					GPIOE->CRH |= (1 << config_bit);  
					GPIOE->CRH &= ~(1 << (config_bit + 1));
					GPIOE->CRH &= ~(1 << (config_bit + 2));
					
				}			
			}
			break;
			
	}
}


void GPIO_Set(uint8_t GPIO_Port, uint8_t GPIO_Pin){
	switch (GPIO_Port){
		case GPIO_A: 
			GPIOA->BSRR |= (1 << GPIO_Pin);
			break;
		
		case GPIO_B:
			GPIOB->BSRR |= (1 << GPIO_Pin);
			break;
		
		case GPIO_C:
			GPIOC->BSRR |= (1 << GPIO_Pin);
			break;		

		case GPIO_D:
			GPIOD->BSRR |= (1 << GPIO_Pin);
			break;
		
	}
}

void GPIO_Reset(uint8_t GPIO_Port, uint8_t GPIO_Pin){
	switch (GPIO_Port){
		case GPIO_A: 
			GPIOA->BSRR |= (1 << (GPIO_Pin + 16));
			break;
		
		case GPIO_B:
			GPIOB->BSRR |= (1 << (GPIO_Pin + 16));
			break;
		
		case GPIO_C:
			GPIOC->BSRR |= (1 << (GPIO_Pin + 16));
			break;		

		case GPIO_D:
			GPIOD->BSRR |= (1 << (GPIO_Pin + 16));
			break;
		
	}
}

void GPIO_Toggle(uint8_t GPIO_Port, uint8_t GPIO_Pin){
    switch (GPIO_Port){
			case GPIO_A:
				{
						uint32_t value = GPIOA->IDR & (1 << GPIO_Pin); //read gpio input data reg
						if (value == 0){
							GPIOA->BSRR |= (1 << GPIO_Pin); //set pin when its state is low
						}
						else if (value != 0){
							GPIOA->BSRR |= (1 << (GPIO_Pin + 16)); 	//reset pin when its state is high
						}
						
				}
				break; // End the case
				
			case GPIO_B:
				{
						uint32_t value = GPIOB->IDR & (1 << GPIO_Pin); //read gpio input data reg
						if (value == 0){
							GPIOB->BSRR |= (1 << GPIO_Pin); //set pin when its state is low
						}
						else if (value != 0){
							GPIOB->BSRR |= (1 << (GPIO_Pin + 16)); 	//reset pin when its state is high
						}
						
				}
				break; // End the case			
				
			case GPIO_C:
				{
						uint32_t value = GPIOC->IDR & (1 << GPIO_Pin); //read gpio input data reg
						if (value == 0){
							GPIOC->BSRR |= (1 << GPIO_Pin); //set pin when its state is low
						}
						else if (value != 0){
							GPIOC->BSRR |= (1 << (GPIO_Pin + 16)); 	//reset pin when its state is high
						}
						
				}
				break; // End the case	
        
    }
}


