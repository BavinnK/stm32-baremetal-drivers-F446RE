#ifndef GPIOX_H_
#define GPIOX_H_

#include "stdint.h"
#include "stm32f446xx.h"
typedef struct{
	uint8_t PINx;
	uint8_t MODERx;
	uint8_t OTYPERx;
	uint8_t OSPEEDRx;
	uint8_t PUPDRx;
}gpio_set_up;

void gpio_init(GPIO_TypeDef *port,gpio_set_up *ptr);
static inline void port_init(GPIO_TypeDef *ptr);
#endif
