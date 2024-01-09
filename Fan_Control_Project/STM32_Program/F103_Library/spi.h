#ifndef	__SPI_H
#define	__SPI_H

#include "stm32f10x.h"

#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */
#define   	__I     volatile const       /*!< Defines 'read only' permissions */
	

#define 	SPI_BASE_1	0x40013000
#define		SPI_BASE_2	0x40003800
#define		SPI_BASE_3	0x40003C00

typedef struct{
  __IO uint16_t CR1;
  uint16_t  RESERVED0;
  __IO uint16_t CR2;
  uint16_t  RESERVED1;
  __IO uint16_t SR;
  uint16_t  RESERVED2;
  __IO uint16_t DR;
  uint16_t  RESERVED3;
  __IO uint16_t CRCPR;
  uint16_t  RESERVED4;
  __IO uint16_t RXCRCR;
  uint16_t  RESERVED5;
  __IO uint16_t TXCRCR;
  uint16_t  RESERVED6;
  __IO uint16_t I2SCFGR;
  uint16_t  RESERVED7;
  __IO uint16_t I2SPR;
  uint16_t  RESERVED8;  
}SPI1_Typedef;


void SPI1_Transmit(uint16_t data);
void SPI_Config(void);


#define	SPI	((SPI1_Typedef*)SPI_BASE_1)
#endif	//__SPI_H
