#include "gpiox.h"
/////////////////////////////////////////////////////////////////////////////
//defines for MODER
#define GPIOx_MODER_INPUT 	0b00
#define GPIOx_MODER_OUTPUT 	0b01
#define GPIOx_MODER_AF 		0b10
#define GPIOx_MODER_ANALOG 	0b11

//defines for OTYPER
#define GPIOx_OTYPER_PP 0b00
#define GPIOx_OTYPER_OD 0b01

//defines for OSPEEDR
#define GPIOx_OSPEEDR_LOW_SP 	0b00
#define GPIOx_OSPEEDR_MED_SP 	0b01
#define GPIOx_OSPEEDR_FAST_SP 	0b10
#define GPIOx_OSPEEDR_HIGH_SP 	0b11

//defines for PUPDR
#define GPIOx_PUPDR_NONE  	0b00
#define GPIOx_PUPDR_UP  	0b01
#define GPIOx_PUPDR_DOWN  	0b10


//////////////////////////////////////////////////////////////////////////////

static inline void port_init(GPIO_TypeDef *ptr){
	if(ptr==GPIOA) RCC->AHB1ENR|=(1<<0);
	else if(ptr==GPIOB) RCC->AHB1ENR|=(1<<1);
	else if(ptr==GPIOC) RCC->AHB1ENR|=(1<<2);
}
void gpio_init(GPIO_TypeDef *port,gpio_set_up *ptr){
	port_init(port);
	port->MODER|=(ptr->MODERx<<ptr->PINx*2);
	port->OTYPER|=(ptr->OTYPERx<<ptr->PINx);
	port->OSPEEDR|=(ptr->OSPEEDRx<<ptr->PINx*2);


}

