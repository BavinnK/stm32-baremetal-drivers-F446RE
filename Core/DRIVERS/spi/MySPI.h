#ifndef MYSPI_H
#define MYSPI_H
#include "stdint.h"
#include "stm32f446xx.h"
#include "gpiox.h"
#include "stdlib.h"

typedef enum{
	MSB=1,
	LSB
}spi_frame_format;
void SPIx_init(SPI_TypeDef *spi,GPIO_TypeDef *port,uint8_t CS,uint32_t frequency_Mhz,spi_frame_format format);
uint8_t SPIx_Receive_Transmit(SPI_TypeDef *spi,GPIO_TypeDef *port,uint8_t CS,uint8_t data);
void SPIx_CS_select(GPIO_TypeDef *port,uint8_t CS);
void SPIx_CS_deselect(GPIO_TypeDef *port,uint8_t CS);

#endif
