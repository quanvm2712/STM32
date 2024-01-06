#include "MAX7219.h"
#include "string.h"

uint8_t DigitCodes[10] = {
    0x7E, // Hex code for 0
    0x30, // Hex code for 1
    0x6D, // Hex code for 2
    0x79, // Hex code for 3
    0x27, // Hex code for 4
    0x5B, // Hex code for 5
    0x5F, // Hex code for 6
    0x70, // Hex code for 7
    0x7F, // Hex code for 8
    0x7B  // Hex code for 9
};

void MAX7219_SendData(uint8_t address, uint8_t data){
	CS_Set();
	SPI_Transmit(SPI1, &address, 1);
	SPI_Transmit(SPI1, &data, 1);
	CS_Reset();
}

void MAX7219_PowerOn(void){
	MAX7219_SendData(0x0C, 0x01);
}

void MAX7219_SetIntensity(uint8_t Intensity){
		MAX7219_SendData(0x0A, Intensity);
}

void MAX7219_SetScanLimit(uint8_t ScanLimit){
	MAX7219_SendData(0x0B, ScanLimit);
}

void MAX7219_Clean(void){
	for(int count = 0; count <= 0xC; count++){
		MAX7219_SendData(count, 0);
	}
	MAX7219_SendData(0xF, 0);
}

void MAX7219_SetDecodeMode(uint8_t DecodeMode){
	MAX7219_SendData(0x9, DecodeMode);
}

void MAX7219_Init(uint8_t Intensity, uint8_t ScanLimit, uint8_t DecodeMode){
	MAX7219_PowerOn();
	MAX7219_SetIntensity(Intensity);
	MAX7219_SetScanLimit(ScanLimit);
	MAX7219_SetDecodeMode(DecodeMode);
}

void MAX7219_PrintString(char* StringToPrint, uint8_t StartPosition){
	uint8_t stringSize = strlen(StringToPrint);
	uint8_t count = 1;
	while(count <= stringSize){
		uint8_t dataInt = StringToPrint[stringSize - count] - '0';
		MAX7219_SendData(count, DigitCodes[dataInt]);
		count++; 
	}
	while(count <= 8){
		MAX7219_SendData(count++, 0);
	}
}

void MAX7219_PrintInt(uint32_t IntToPrint){
	uint8_t position = 1;
	while(IntToPrint){
		uint8_t digitToPrint = IntToPrint % 10;
		MAX7219_SendData(position++, DigitCodes[digitToPrint]);
		IntToPrint /= 10;
	}
	while(position <= 8){
		MAX7219_SendData(position++, 0);
	}
}