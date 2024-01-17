#include "stm32f10x.h"
#include "delay.h"
#include "gpio.h"
#include "spi.h"
#include "MAX7219.h"
#include "Timer.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "i2c_drive.h"
#include "gp_drive.h"


#define ENCODER_PPR 30

int counterVal;
uint16_t position = 0;
uint16_t old_position = 0;
uint16_t encoderPPS = 0;
uint16_t currentFanRPM = 0;
uint16_t ms_count = 0;
uint8_t rx_data = 55;

uint8_t temperature_data = 25;

float control_signal;
uint8_t* fanRPMData;
char rpm_buffer[9]; 


/*AHT20 variables*/
uint8_t data[6];
float actualTemperature;
float actualHumidity;
uint8_t AHT20_Data[2];


void TIM1_UP_IRQHandler(){
	if(TIM1->SR & 0x1){  //Check if interrupt flag is set
		ms_count += 1;
		if(ms_count >= 200){
			position = counterVal / 4;  //Get current position of encoder
			if (position >= old_position){
				encoderPPS = (position - old_position) * 5;  
			}
			currentFanRPM = (encoderPPS * 60) / ENCODER_PPR;
			old_position = position;
			ms_count = 0;
		}
		TIM1->SR &= ~1;  //Reset interrupt flag
	}
}

 
void TIM1_Config(){
	TIM_EnableTimerClock(TIM1);
	
	//Set prescaler and ARR value (Timer 1 generate interrupt every 1ms)
	TIM1->PSC = 72-1;
	TIM1->ARR = 1000 - 1;
	
	//Enable update interrupt
	TIM1->DIER |= (1 << 0);
	
	NVIC_EnableIRQ(TIM1_UP_IRQn);
	NVIC_SetPriority(TIM1_UP_IRQn, 2);
	
	TIM1->CR1 |= (1 << 0);  //Enable timer 1
}

void led_blink(){
	GPIO_Toggle(GPIO_C, 13);
	delay_ms(100);
}


void Set_DutyCycle(uint8_t DutyCycle){
	TIM_SetCCRxReg(TIM3,DutyCycle, TIM_Channel_3);
}

void AHT20_Init(){
	delay_ms(40);
	
	//Send Init command to AHT20
	uint8_t status;
	I2C_read1(0x38, &status, 1);
	
	if (!(status & (1 << 3)))
	{
		uint8_t init_command[] = {0xBE, 0x08, 0x00};
		I2C_write(0x38, init_command, 3);
		delay_ms(10);
	}

}

void AHT20_GetData(uint8_t *sensor_data){
	//Send trigger measurement command
	uint8_t trigger_command[] = {0xAC, 0x38, 0x00};
	I2C_write(0x38, trigger_command, 3);
	delay_ms(80);

	
	//Wait for measurement to be completed
	uint8_t status;
	do 
	{
		I2C_read1(0x38, &status, 1);
	}while(status & (1 << 7));

	//get data
	I2C_read(0x38,sensor_data, 6);
}


void AHT20_GetValue(uint8_t* value){
	AHT20_GetData(data);
	uint32_t humidity = ((data[1] << 16) | (data[2] << 8) | data[3]) >> 4;
	uint32_t temperature = ((data[3] & 0x0F) << 16) | (data[4] << 8) | data[5];
	
	actualTemperature = (temperature * 200.0 / 1048576.0) - 50.0;
	actualHumidity = (humidity * 100.0 / 1048576.0);

	value[0] = (uint8_t) actualTemperature;
	value [1] = (uint8_t) actualHumidity;
}

uint16_t GetCounterValue(){
	return TIM4->CNT;
}

int main(void){
	SystemInit();
	TIM1_Config(); //Init timer 1 to generate interrupt every 1ms
	
	//Init SPI and MAX7219
	SPI_Init(SPI1, SPI_Master);
	MAX7219_Init(10, DIGIT_0_TO_7, DECODE_MODE_DISABLE);

	
	//Init Timer 3 channel 3 IO for PWM functionality
	GPIO_Init(GPIO_B, 0, AFIO_OUTPUT);	
	//PWM Init and run
	TIM_PWM_Init(TIM3, TIM_Channel_3, 72, 100, 50);
	TIM_PWM_Start(TIM3, TIM_Channel_3);
	
	//Encoder Mode Init and run
	TIM_Encoder_Init(TIM4, SLAVE_EncoderMode_3);
	TIM_EncoderStart(TIM4);
	
	//Init I2C and AHT20
	I2C_init(I2C1_REMAP_ENABLE);
	AHT20_Init();
	
	while(1){	
		counterVal = GetCounterValue(); //Get current counter value from timer 3	
		Set_DutyCycle(rx_data);
		
		AHT20_GetValue(AHT20_Data);
		
		delay_ms(10);
	}
	return 0;
}









