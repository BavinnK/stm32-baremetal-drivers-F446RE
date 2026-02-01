#include "stm32f446xx.h"
#include <stdint.h>

void clock_init_180Mhz(void){
	RCC->CR|=(1<<16);				//enable external 8mhz oscillator
	while(!(RCC->CR&(1<<17)));		//wait for the HSE clock to be ready
	RCC->APB1ENR|=(1<<28);			//since we are gonna run the chip at 180Mhz, it needs more juice i mean voltage
	PWR->CR|=(3<<14);				//we set the scale mode to 1 max performance
	while(!(PWR->CSR&(1<<16)));		//wait until Over-drive mode is ready
	RCC->PLLCFGR&=~(0b111111);		//clear PLLM bits
	RCC->PLLCFGR|=(8);				//divide the HSE clock by 8, the target clock after division should be between 1 to 2 Mhz
	RCC->PLLCFGR&=~(0b111111111);	//clear PLLN bits
	RCC->PLLCFGR|=(360<<6);			//then multiply the 1 Mhz that we divided in the PLLM to 360, the multiply spot should be between 192Mhz to 432Mhz i want 360 to get 180 easily
	RCC->PLLCFGR&=~(3<<16);			//set the PLLP bits to 00 which means the PLLN freq will be divided by 2, the 360 that we got we divide by 2 and kaboom we got 180Mhz
	/*
	 * the CPU will now run at 180Mhz, but we have a problem
	 * which is the internal perpherials like the flash
	 * cannot keep up with the speed of the CPU so before we switch to PLL mode we have to
	 * configure flash wait states and caches */

}
