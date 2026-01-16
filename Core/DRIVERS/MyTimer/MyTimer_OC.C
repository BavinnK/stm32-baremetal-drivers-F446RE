#include "MyTimer_OC.h"
#define arr 0xFFFF
static inline void set_chn_tim(TIM_TypeDef *tim,uint8_t chn,TIMx_OC_MODE mode){
	if(chn==1 && mode==SET){
		tim->CCMR1&=~((7<<4)|(2<<0));//clear bits 4 till 7
		tim->CCMR1|=(1<<4)|(1<<3);// Set channel 1 to active level on match
		tim->CCER|=(1);
	}
	else if(chn==1 && mode==RESET){
		tim->CCMR1&=~((7<<4)|(2<<0));//clear bits 4 till 7
		tim->CCMR1|=(2<<4)|(1<<3);// Set channel 1 to active level on match. preload enable
		tim->CCER|=(1);
	}
	else if(chn==1 && mode==TOGGLE){
		tim->CCMR1&=~((7<<4)|(2<<0));//clear bits 4 till 7
		tim->CCMR1|=(3<<4)|(1<<3);// Set channel 1 to active level on match. preload enable
		tim->CCER|=(1);
	}
	else if(chn==2 && mode==SET){
		tim->CCMR1&=~((7<<12)|(2<<0));//clear bits 12 till 14
		tim->CCMR1|=(1<<12)|(1<<11);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<4);
	}
	else if(chn==2 && mode==RESET){
		tim->CCMR1&=~((7<<12)|(2<<0));//clear bits 12 till 14
		tim->CCMR1|=(2<<12)|(1<<11);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<4);
	}
	else if(chn==2 && mode==TOGGLE){
		tim->CCMR1&=~((7<<12)|(2<<0));//clear bits 12 till 14
		tim->CCMR1|=(3<<12)|(1<<11);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<4);
	}
	else if(chn==3 && mode==SET){
		tim->CCMR2&=~((7<<4)|(2<<0));//clear bits 4 till 7
		tim->CCMR2|=(1<<4)|(1<<3);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<8);
	}
	else if(chn==3 && mode==RESET){
		tim->CCMR2&=~((7<<4)|(2<<0));//clear bits 4 till 7
		tim->CCMR2|=(2<<4)|(1<<3);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<8);
	}
	else if(chn==3 && mode==TOGGLE){
		tim->CCMR2&=~((7<<4)|(2<<0));//clear bits 4 till 7
		tim->CCMR2|=(3<<4)|(1<<3);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<8);
	}
	else if(chn==4 && mode==SET){
		tim->CCMR2&=~((7<<12)|(2<<0));//clear bits 12 till 14
		tim->CCMR2|=(1<<12)|(1<<11);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<12);
	}
	else if(chn==4 && mode==RESET){
		tim->CCMR2&=~((7<<12)|(2<<0));//clear bits 12 till 14
		tim->CCMR2|=(2<<12)|(1<<11);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<12);
	}
	else if(chn==4 && mode==TOGGLE){
		tim->CCMR2&=~((7<<12)|(2<<0));//clear bits 12 till 14,also bit 0 and 1
		tim->CCMR2|=(3<<12)|(1<<11);// Set channel 2 to active level on match. preload enable
		tim->CCER|=(1<<12);
	}
	else{
		while(1);//error
	}

}
void TIMx_OC_init(TIM_TypeDef *TIMx,GPIO_TypeDef *port,uint8_t pin,uint8_t channel,TIMx_OC_MODE mode,uint16_t pcs){
	gpio_set_up config;
	config.PINx=pin;
	config.MODERx=GPIOx_MODER_AF;
	config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
	config.OTYPERx=GPIOx_OTYPER_PP;
	config.PUPDRx=GPIOx_PUPDR_NONE;
	gpio_init(port, &config);
	pin_set_tim_chn(TIMx, port, pin, channel);
	TIMx_base_init(TIMx, pcs, arr);
}
