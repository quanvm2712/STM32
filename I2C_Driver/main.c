#include "stm32f10x.h"                
#include "gp_drive.h"
#include "i2c_drive.h"
#include "systick_time.h"


void AHT20_Init();
void AHT20_GetData(uint8_t *sensor_data);

uint8_t data[6];
float actualTemperature;
float actualHumidity;

void AHT20_Init(){
	DelayMs(40);
	//Send Init command to AHT20
	
	
	uint8_t status;
	I2C_read1(0x38, &status, 1);
	
	if (!(status & (1 << 3)))
	{
		uint8_t init_command[] = {0xBE, 0x08, 0x00};
		I2C_write(0x38, init_command, 3);
		DelayMs(10);
	}

}

void AHT20_GetData(uint8_t *sensor_data){
	//Send trigger measurement command

	uint8_t trigger_command[] = {0xAC, 0x38, 0x00};
	I2C_write(0x38, trigger_command, 3);
	//
	DelayMs(80);

	
	//Wait for measurement to be completed
	uint8_t status;
	do 
	{
		I2C_read1(0x38, &status, 1);
	}while(status & (1 << 7));

	//get data
	I2C_read(0x38,sensor_data, 6);
}

int main(void)
{
	systick_init();
	I2C_init(I2C1_REMAP_ENABLE);
	AHT20_Init();
	
	
	uint8_t status;
	
	
	while (1)
	{
		AHT20_GetData(data);
		uint32_t temperature = ((data[1] << 16) | (data[2] << 8) | data[3]) >> 4;
		uint32_t humidity = ((data[3] & 0x0F) << 16) | (data[4] << 8) | data[5];
		
		actualTemperature = (temperature * 200.0 / 1048576.0) - 50.0;
    actualHumidity = (humidity * 100.0 / 1048576.0);
	}
}
