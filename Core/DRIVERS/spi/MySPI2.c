#include "MySPI2.h"

void SPI2_init(){

	gpio_set_up config_spi_MOSI,config_spi_MISO,config_spi_SCLK;
	config_spi_MOSI.PINx=1;//PC1
	config_spi_MOSI.MODERx=GPIOx_MODER_AF;
	config_spi_MOSI.OSPEEDRx=GPIOx_OSPEEDR_FAST_SP;
	config_spi_MOSI.OTYPERx=GPIOx_OTYPER_PP;
	config_spi_MOSI.PUPDRx=GPIOx_PUPDR_NONE;

	config_spi_MISO.PINx=2;//PC2
	config_spi_MISO.MODERx=GPIOx_MODER_AF;
	config_spi_MISO.OSPEEDRx=GPIOx_OSPEEDR_FAST_SP;
	config_spi_MISO.OTYPERx=GPIOx_OTYPER_PP;
	config_spi_MISO.PUPDRx=GPIOx_PUPDR_NONE;

	config_spi_SCLK.PINx=10;//PB10
	config_spi_SCLK.MODERx=GPIOx_MODER_AF;
	config_spi_SCLK.OSPEEDRx=GPIOx_OSPEEDR_FAST_SP;
	config_spi_SCLK.OTYPERx=GPIOx_OTYPER_PP;
	config_spi_SCLK.PUPDRx=GPIOx_PUPDR_NONE;

	gpio_init(GPIOC, &config_spi_MOSI);
	gpio_init(GPIOC, &config_spi_MISO);
	gpio_init(GPIOB, &config_spi_SCLK);

	GPIOC->AFR[0]&=~((0b1111<<4*1)|(0b1111<<4*2));
	GPIOB->AFR[1]&=~(0b1111<<4*(10-8));
	GPIOC->AFR[0]|=((5<<4*1)|(5<<4*2));
	GPIOB->AFR[1]|=(5<<4*(10-8));



}
