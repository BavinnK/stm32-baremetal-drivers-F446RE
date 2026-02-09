#include <MySPI.h>

static inline void set_format(SPI_TypeDef *spi,spi_frame_format format){
	if(format==MSB){
		spi->CR1&=~(1<<7);
	}
	else if(format==LSB){
		spi->CR1|=(1<<7);
	}
}

static inline uint32_t get_spi_freq(SPI_TypeDef *spi,uint32_t freq){
	if(spi==SPI1){
		return 90000000;
	}
	else{
		return 45000000;
	}
}
static inline uint32_t set_freq(SPI_TypeDef *spi,uint32_t freq){
	static const uint16_t psc_table[8]={2,4,8,16,32,64,128,256};

	uint32_t pclk=get_spi_freq(spi, freq);//the user needs to change the freq of both APB1 BUS AND APB2 BUS depending on the cpu speed, mine is 180Mhz
	uint32_t closest=0,baud_value=0,best_PSC=0,best_closest=0xFFFFFFFF;
	for(int i=0;i<=7;i++){
		baud_value=pclk/psc_table[i];
		closest = (baud_value > freq)?(baud_value - freq):(freq - baud_value);
		if(closest<=best_closest){
			best_closest=closest;
			best_PSC=i;
		}

	}
	return best_PSC;
}
static inline void SPI_set(SPI_TypeDef *spi,GPIO_TypeDef *port,uint8_t CS,uint32_t frequency_Mhz,spi_frame_format format){
	if(spi==SPI1){
		gpio_set_up config_spi_MOSI,config_spi_MISO,config_spi_SCLK,config_spi_CS;
		config_spi_MOSI.PINx=7;//PA7
		config_spi_MOSI.MODERx=GPIOx_MODER_AF;
		config_spi_MOSI.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		config_spi_MOSI.OTYPERx=GPIOx_OTYPER_PP;
		config_spi_MOSI.PUPDRx=GPIOx_PUPDR_NONE;

		config_spi_MISO.PINx=6;//PA6
		config_spi_MISO.MODERx=GPIOx_MODER_AF;
		config_spi_MISO.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		config_spi_MISO.OTYPERx=GPIOx_OTYPER_PP;
		config_spi_MISO.PUPDRx=GPIOx_PUPDR_NONE;

		config_spi_SCLK.PINx=5;//PA5
		config_spi_SCLK.MODERx=GPIOx_MODER_AF;
		config_spi_SCLK.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		config_spi_SCLK.OTYPERx=GPIOx_OTYPER_PP;
		config_spi_SCLK.PUPDRx=GPIOx_PUPDR_NONE;

		config_spi_CS.PINx=CS;//user provided pin
		config_spi_CS.MODERx=GPIOx_MODER_OUTPUT;
		config_spi_CS.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		config_spi_CS.OTYPERx=GPIOx_OTYPER_PP;
		config_spi_CS.PUPDRx=GPIOx_PUPDR_NONE;

		gpio_init(GPIOA, &config_spi_MOSI);
		gpio_init(GPIOA, &config_spi_MISO);
		gpio_init(GPIOA, &config_spi_SCLK);
		gpio_init(port, &config_spi_CS);

		GPIOA->AFR[0]&=~((15<<(7*4))|(15<<(6*4))|(15<<(5*4)));
		GPIOA->AFR[0]|=(5<<(7*4))|(5<<(6*4))|(5<<(5*4));
		RCC->APB2ENR|=(1<<12);
	}
	else if(spi==SPI2){
		gpio_set_up config_spi_MOSI,config_spi_MISO,config_spi_SCLK,config_spi_CS;
		config_spi_MOSI.PINx=1;//PC1
		config_spi_MOSI.MODERx=GPIOx_MODER_AF;
		config_spi_MOSI.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		config_spi_MOSI.OTYPERx=GPIOx_OTYPER_PP;
		config_spi_MOSI.PUPDRx=GPIOx_PUPDR_NONE;

		config_spi_MISO.PINx=2;//PC2
		config_spi_MISO.MODERx=GPIOx_MODER_AF;
		config_spi_MISO.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		config_spi_MISO.OTYPERx=GPIOx_OTYPER_PP;
		config_spi_MISO.PUPDRx=GPIOx_PUPDR_NONE;

		config_spi_SCLK.PINx=10;//PB10
		config_spi_SCLK.MODERx=GPIOx_MODER_AF;
		config_spi_SCLK.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		config_spi_SCLK.OTYPERx=GPIOx_OTYPER_PP;
		config_spi_SCLK.PUPDRx=GPIOx_PUPDR_NONE;

		config_spi_CS.PINx=CS;//user provided pin
		config_spi_CS.MODERx=GPIOx_MODER_OUTPUT;
		config_spi_CS.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		config_spi_CS.OTYPERx=GPIOx_OTYPER_PP;
		config_spi_CS.PUPDRx=GPIOx_PUPDR_NONE;

		gpio_init(GPIOC, &config_spi_MOSI);
		gpio_init(GPIOC, &config_spi_MISO);
		gpio_init(GPIOB, &config_spi_SCLK);
		gpio_init(port, &config_spi_CS);

		GPIOC->AFR[0]&=~((0b1111<<4*1)|(0b1111<<4*2));
		GPIOB->AFR[1]&=~(0b1111<<4*(10-8));
		GPIOC->AFR[0]|=((5<<4*1)|(5<<4*2));
		GPIOB->AFR[1]|=(5<<4*(10-8));

		RCC->APB1ENR|=(1<<14);//SPIx CLK EN
	}
}
void SPIx_init(SPI_TypeDef *spi,GPIO_TypeDef *port,uint8_t CS,uint32_t frequency_Mhz,spi_frame_format format){

	SPI_set(spi, port, CS, frequency_Mhz, format);
	spi->CR1&=~((1<<6)|(0b111<<3)|(1<<1));//DISABLE SPIx FIRST,and clear baud control bits, and then set the clock polarity to low
	set_format(spi,format);
	spi->CR1|=(set_freq(spi,frequency_Mhz)<<3)|(1<<2)|(1<<0);//set the spi to master, then set the freq that was provided by the user
	//then set the clock phase so in the second edge the transmission of data beginst the first edge is just a hand shake with the slave device
	spi->CR1|=(3<<8)|(1<<6);//we set both SSM AND SSI to one, basicallly we tell the spi hey i wanna handle the chip select dont worry, then enable the prepherial
	spi->CR1&=~(1<<11);//clear DFF bit to set it to 8 bit format
	spi->CR1|=(1<<2);//set master config
}
uint8_t SPIx_Receive_Transmit(SPI_TypeDef *spi,GPIO_TypeDef *port,uint8_t CS,uint8_t data){
	while(!(spi->SR&(1<<1)));//WAIT UNTIL THE TRANSMIT BUFFER IS EMPTY, afterwards send the data
	spi->DR=data;
	while(!(spi->SR&(1<<0)));//WAIT UNTIL THE RECEIVE BUFFER IS NOT EMPTY, afterwards GET the data
	return spi->DR;
}
void SPIx_CS_select(GPIO_TypeDef *port,uint8_t CS){
	gpio_reset(port, CS);//low
}
void SPIx_CS_deselect(GPIO_TypeDef *port,uint8_t CS){
	gpio_set(port, CS);//high
}
