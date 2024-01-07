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
				//input mode
	      if(mode == INPUT){
					uint32_t config_bit = (GPIO_Pin + 3 * (GPIO_Pin + 1));
					GPIOA->ODR |= (1 << GPIO_Pin);  //Pull up 
					//Input mode with pull up/down
					GPIOA->CRL |= (1<< config_bit); 
					GPIOA->CRL &= ~(1<< (config_bit - 1)); 
					GPIOA->CRL &= ~(1<< (config_bit - 2)); 
					GPIOA->CRL &= ~(1<< (config_bit - 3)); 
				}
				//output mode
				else if (mode == OUTPUT){
					uint32_t config_bit = (GPIO_Pin * 4);
					//10mhz output mode, push-pull
					GPIOA->CRL |= (1 << config_bit);  //10mhz output mode, push-pull
					GPIOA->CRL &= ~(1 << (config_bit + 1));
					GPIOA->CRL &= ~(1 << (config_bit + 2));
					GPIOA->CRL &= ~(1 << (config_bit + 3));
					
				}
			}
			else if ((GPIO_Pin >= 8) & (GPIO_Pin < 16)){
				
				if(mode == INPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8 + 1));
					GPIOA->ODR |= (1 << GPIO_Pin);  //Pull up 
					//Input with pull-up/pull-down
					GPIOA->CRH |= (1 << config_bit); 
					GPIOA->CRH &= ~(1 << (config_bit - 1));
					GPIOA->CRH &= ~(1 << (config_bit - 2));
					GPIOA->CRH &= ~(1 << (config_bit - 3));
					
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8));
					//10mhz output mode, push-pull
					GPIOA->CRH |= (1 << config_bit);  
					GPIOA->CRH &= ~(1 << (config_bit + 1));
					GPIOA->CRH &= ~(1 << (config_bit + 2));
					GPIOA->CRH &= ~(1 << (config_bit + 3));
					
				}			
			}
			break;
			
			
			

		case GPIO_B:
			if(GPIO_Pin < 8){
				//input mode
	      if(mode == INPUT){
					uint32_t config_bit = (GPIO_Pin + 3 * (GPIO_Pin + 1));
					GPIOB->ODR |= (1 << GPIO_Pin);  //Pull up 
					//Input mode with pull up/down
					GPIOB->CRL |= (1<< config_bit); 
					GPIOB->CRL &= ~(1<< (config_bit - 1)); 
					GPIOB->CRL &= ~(1<< (config_bit - 2)); 
					GPIOB->CRL &= ~(1<< (config_bit - 3)); 
				}
				//output mode
				else if (mode == OUTPUT){
					uint32_t config_bit = (GPIO_Pin * 4);
					//10mhz output mode, push-pull
					GPIOB->CRL |= (1 << config_bit);  //10mhz output mode, push-pull
					GPIOB->CRL &= ~(1 << (config_bit + 1));
					GPIOB->CRL &= ~(1 << (config_bit + 2));
					GPIOB->CRL &= ~(1 << (config_bit + 3));
					
				}
			}
			else if ((GPIO_Pin >= 8) & (GPIO_Pin < 16)){
				
				if(mode == INPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8 + 1));
					GPIOB->ODR |= (1 << GPIO_Pin);  //Pull up 
					//Input with pull-up/pull-down
					GPIOB->CRH |= (1 << config_bit); 
					GPIOB->CRH &= ~(1 << (config_bit - 1));
					GPIOB->CRH &= ~(1 << (config_bit - 2));
					GPIOB->CRH &= ~(1 << (config_bit - 3));
					
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8));
					//10mhz output mode, push-pull
					GPIOB->CRH |= (1 << config_bit);  
					GPIOB->CRH &= ~(1 << (config_bit + 1));
					GPIOB->CRH &= ~(1 << (config_bit + 2));
					GPIOB->CRH &= ~(1 << (config_bit + 3));
					
				}			
			}
			break;
			
			
			
			
		case GPIO_C:
			if(GPIO_Pin < 8){
				//input mode
	      if(mode == INPUT){
					uint32_t config_bit = (GPIO_Pin + 3 * (GPIO_Pin + 1));
					GPIOC->ODR |= (1 << GPIO_Pin);  //Pull up 
					//Input mode with pull up/down
					GPIOC->CRL |= (1<< config_bit); 
					GPIOC->CRL &= ~(1<< (config_bit - 1)); 
					GPIOC->CRL &= ~(1<< (config_bit - 2)); 
					GPIOC->CRL &= ~(1<< (config_bit - 3)); 
				}
				//output mode
				else if (mode == OUTPUT){
					uint32_t config_bit = (GPIO_Pin * 4);
					//10mhz output mode, push-pull
					GPIOC->CRL |= (1 << config_bit);  //10mhz output mode, push-pull
					GPIOC->CRL &= ~(1 << (config_bit + 1));
					GPIOC->CRL &= ~(1 << (config_bit + 2));
					GPIOC->CRL &= ~(1 << (config_bit + 3));
					
				}
			}
			else if ((GPIO_Pin >= 8) & (GPIO_Pin < 16)){
				
				if(mode == INPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8 + 1));
					GPIOC->ODR |= (1 << GPIO_Pin);  //Pull up 
					//Input with pull-up/pull-down
					GPIOC->CRH |= (1 << config_bit); 
					GPIOC->CRH &= ~(1 << (config_bit - 1));
					GPIOC->CRH &= ~(1 << (config_bit - 2));
					GPIOC->CRH &= ~(1 << (config_bit - 3));
					
				}
				else if (mode == OUTPUT){
					uint32_t config_bit = ((GPIO_Pin - 8) + 3 * (GPIO_Pin - 8));
					//10mhz output mode, push-pull
					GPIOC->CRH |= (1 << config_bit);  
					GPIOC->CRH &= ~(1 << (config_bit + 1));
					GPIOC->CRH &= ~(1 << (config_bit + 2));
					GPIOC->CRH &= ~(1 << (config_bit + 3));
					
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


void GPIO_Enable_Interrupt(uint8_t port, uint8_t exti_line, uint8_t edge, uint8_t priority){
	EXTI->IMR |= (1 << exti_line);  //disable mask for interrupt request line 1
	
	//Input edge
	if (edge == EDGE_FALLING){
		EXTI->FTSR |= (1 << exti_line);  //falling edge for input line
		EXTI->RTSR &= ~(1 << exti_line); //disable rising edge detection
	}
	else if(edge == EDGE_RISING){
		EXTI->RTSR |= (1 << exti_line);
		EXTI->FTSR &= ~(1 << exti_line);
	}
	
	//external interrupt configuration
	switch(exti_line){
		
		//interrupt line 0-3
		case EXTI_Line_0:
		case EXTI_Line_1:
		case EXTI_Line_2:
		case EXTI_Line_3:
		{
			uint32_t config_bit = exti_line * 4;
			if (port == GPIO_A){
				AFIO->EXTICR[0] &= ~(1 << config_bit);
				AFIO->EXTICR[0] &= ~(1 << (config_bit + 1));
				AFIO->EXTICR[0] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[0] &= ~(1 << (config_bit + 3));
			}
			else if (port == GPIO_B){
				AFIO->EXTICR[0] |= 	(1 << config_bit);
				AFIO->EXTICR[0] &= ~(1 << (config_bit + 1));
				AFIO->EXTICR[0] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[0] &= ~(1 << (config_bit + 3));				
			}
			
			else if (port == GPIO_C){
				AFIO->EXTICR[0] &= ~(1 << config_bit);
				AFIO->EXTICR[0] |= 	(1 << (config_bit + 1));
				AFIO->EXTICR[0] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[0] &= ~(1 << (config_bit + 3));				
			}
			
		}
		break;
		
		
		case EXTI_Line_4:
		case EXTI_Line_5:	
		case EXTI_Line_6:
		case EXTI_Line_7:
		{
			uint32_t config_bit = 4 * (exti_line - 4);
			if (port == GPIO_A){
				AFIO->EXTICR[1] &= ~(1 << config_bit);
				AFIO->EXTICR[1] &= ~(1 << (config_bit + 1));
				AFIO->EXTICR[1] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[1] &= ~(1 << (config_bit + 3));
			}
			else if (port == GPIO_B){
				AFIO->EXTICR[1] |= 	(1 << config_bit);
				AFIO->EXTICR[1] &= ~(1 << (config_bit + 1));
				AFIO->EXTICR[1] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[1] &= ~(1 << (config_bit + 3));				
			}
			
			else if (port == GPIO_C){
				AFIO->EXTICR[1] &= ~(1 << config_bit);
				AFIO->EXTICR[1] |= 	(1 << (config_bit + 1));
				AFIO->EXTICR[1] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[1] &= ~(1 << (config_bit + 3));				
			}			
		}
		break;
		

		case EXTI_Line_8:
		case EXTI_Line_9:
		case EXTI_Line_10:
		case EXTI_Line_11:
		{
			uint32_t config_bit = 4 * (exti_line - 8);
			if (port == GPIO_A){
				AFIO->EXTICR[2] &= ~(1 << config_bit);
				AFIO->EXTICR[2] &= ~(1 << (config_bit + 1));
				AFIO->EXTICR[2] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[2] &= ~(1 << (config_bit + 3));
			}
			else if (port == GPIO_B){
				AFIO->EXTICR[2] |= 	(1 << config_bit);
				AFIO->EXTICR[2] &= ~(1 << (config_bit + 1));
				AFIO->EXTICR[2] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[2] &= ~(1 << (config_bit + 3));				
			}
			
			else if (port == GPIO_C){
				AFIO->EXTICR[2] &= ~(1 << config_bit);
				AFIO->EXTICR[2] |= 	(1 << (config_bit + 1));
				AFIO->EXTICR[2] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[2] &= ~(1 << (config_bit + 3));				
			}			
		}
		break;		
		
		case EXTI_Line_12:
		case EXTI_Line_13:
		case EXTI_Line_14:
		case EXTI_Line_15:
		{
			uint32_t config_bit = 4 * (exti_line - 12);
			if (port == GPIO_A){
				AFIO->EXTICR[3] &= ~(1 << config_bit);
				AFIO->EXTICR[3] &= ~(1 << (config_bit + 1));
				AFIO->EXTICR[3] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[3] &= ~(1 << (config_bit + 3));
			}
			else if (port == GPIO_B){
				AFIO->EXTICR[3] |= 	(1 << config_bit);
				AFIO->EXTICR[3] &= ~(1 << (config_bit + 1));
				AFIO->EXTICR[3] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[3] &= ~(1 << (config_bit + 3));				
			}
			
			else if (port == GPIO_C){
				AFIO->EXTICR[3] &= ~(1 << config_bit);
				AFIO->EXTICR[3] |= 	(1 << (config_bit + 1));
				AFIO->EXTICR[3] &= ~(1 << (config_bit + 2));
				AFIO->EXTICR[3] &= ~(1 << (config_bit + 3));				
			}			
		}
		break;				
	}
	
	
	
	//set piority and enable interrupt
	switch(exti_line){
		case EXTI_Line_0:
			NVIC_SetPriority(EXTI0_IRQn, priority);
			NVIC_EnableIRQ(EXTI0_IRQn);	
			break;
		
		case EXTI_Line_1:
			NVIC_SetPriority(EXTI1_IRQn, priority);
			NVIC_EnableIRQ(EXTI1_IRQn);	
			break;

		case EXTI_Line_2:
			NVIC_SetPriority(EXTI2_IRQn, priority);
			NVIC_EnableIRQ(EXTI2_IRQn);
			break;
		
		case EXTI_Line_3:
			NVIC_SetPriority(EXTI3_IRQn, priority);
			NVIC_EnableIRQ(EXTI3_IRQn);	
			break;
		
		case EXTI_Line_4:
			NVIC_SetPriority(EXTI4_IRQn, priority);
			NVIC_EnableIRQ(EXTI4_IRQn);	
			break;

		case EXTI_Line_5:
			NVIC_SetPriority(EXTI9_5_IRQn, priority);
			NVIC_EnableIRQ(EXTI9_5_IRQn);	
			break;

		case EXTI_Line_6:
			NVIC_SetPriority(EXTI9_5_IRQn, priority);
			NVIC_EnableIRQ(EXTI9_5_IRQn);	
			break;

		case EXTI_Line_7:
			NVIC_SetPriority(EXTI9_5_IRQn, priority);
			NVIC_EnableIRQ(EXTI9_5_IRQn);	
			break;

		case EXTI_Line_8:
			NVIC_SetPriority(EXTI9_5_IRQn, priority);
			NVIC_EnableIRQ(EXTI9_5_IRQn);	
			break;	

		case EXTI_Line_9:
			NVIC_SetPriority(EXTI9_5_IRQn, priority);
			NVIC_EnableIRQ(EXTI9_5_IRQn);	
			break;		

		case EXTI_Line_10:
			NVIC_SetPriority(EXTI15_10_IRQn, priority);
			NVIC_EnableIRQ(EXTI15_10_IRQn);	
			break;

		case EXTI_Line_11:
			NVIC_SetPriority(EXTI15_10_IRQn, priority);
			NVIC_EnableIRQ(EXTI15_10_IRQn);	
			break;

		case EXTI_Line_12:
			NVIC_SetPriority(EXTI15_10_IRQn, priority);
			NVIC_EnableIRQ(EXTI15_10_IRQn);	
			break;

		case EXTI_Line_13:
			NVIC_SetPriority(EXTI15_10_IRQn, priority);
			NVIC_EnableIRQ(EXTI15_10_IRQn);	
			break;	

		case EXTI_Line_14:
			NVIC_SetPriority(EXTI15_10_IRQn, priority);
			NVIC_EnableIRQ(EXTI15_10_IRQn);	
			break;
		
		case EXTI_Line_15:
			NVIC_SetPriority(EXTI15_10_IRQn, priority);
			NVIC_EnableIRQ(EXTI15_10_IRQn);	
			break;
			
	}

}


