#include "MyTimer_IC.h"
#define arr 0xFFFF

static inline void set_chn(TIM_TypeDef *tim,uint8_t chn,edge_captcure edge){
	if(chn==1 && edge==RISING_EDGE){
		tim->CCMR1&=~(3<<1);
		tim->CCMR1|=(1);
		tim->CCER|=(1);
	}
	else if(chn==1 && edge==FALLING_EDGE){
		tim->CCMR1&=~(3<<1);
		tim->CCMR1|=(1);
		tim->CCER|=3;
	}
	else if(chn==1 && edge==BOTH_EDGES){//both edge feature is only for TIM1&TIM8 which they are advanced timers
		tim->CCMR1&=~(3<<1);
		tim->CCMR1|=(1);
		tim->CCER|=(3<<0)|(1<<3);
	}

	else if(chn==2 && edge==RISING_EDGE){
		tim->CCMR1&=~(3<<8);
		tim->CCMR1|=(1<<8);
		tim->CCER|=(1<<4);
	}
	else if(chn==2 && edge==FALLING_EDGE){
		tim->CCMR1&=~(3<<8);
		tim->CCMR1|=(1<<8);
		tim->CCER|=(1<<4)|(1<<5);
	}
	else if(chn==2 && edge==BOTH_EDGES){
		tim->CCMR1&=~(3<<8);
		tim->CCMR1|=(1<<8);
		tim->CCER|=(1<<4)|(1<<5)|(1<<7);
	}
	else if(chn==3 && edge==RISING_EDGE){
		tim->CCMR2&=~(3<<1);
		tim->CCMR2|=(1);
		tim->CCER|=(1<<8);//enable capture
	}
	else if(chn==3 && edge==FALLING_EDGE){
		tim->CCMR2&=~(3<<1);
		tim->CCMR2|=(1);
		tim->CCER|=(1<<8)|(1<<9);//enable capture
	}
	else if(chn==3 && edge==BOTH_EDGES){
		tim->CCMR2&=~(3<<1);
		tim->CCMR2|=(1);
		tim->CCER|=(1<<8)|(1<<9)|(1<<11);//enable capture
	}
	else if(chn==4 && edge==RISING_EDGE){
		tim->CCMR2&=~(3<<8);
		tim->CCMR2|=(1<<8);
		tim->CCER|=(1<<12);
	}
	else if(chn==4 && edge==FALLING_EDGE){
		tim->CCMR2&=~(3<<8);
		tim->CCMR2|=(1<<8);
		tim->CCER|=(1<<12)|(1<<13);
	}
	else if(chn==4 && edge==BOTH_EDGES){
		tim->CCMR2&=~(3<<8);
		tim->CCMR2|=(1<<8);
		tim->CCER|=(1<<12)|(1<<13)|(1<<15);
	}
}
static inline uint32_t chn_data(TIM_TypeDef *tim,uint8_t chn){
	if(chn==1) 		return tim->CCR1;
	else if(chn==2) return tim->CCR2;
	else if(chn==3) return tim->CCR3;
	else if(chn==4) return tim->CCR4;
	else 			return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMx_IC_init(TIM_TypeDef *TIMx,GPIO_TypeDef *port,uint8_t channel,edge_captcure edge,uint8_t pin,uint16_t pcs ){
	gpio_set_up config;
	config.PINx=pin;
	config.MODERx=GPIOx_MODER_AF;
	config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
	config.OTYPERx=GPIOx_OTYPER_PP;
	config.PUPDRx=GPIOx_PUPDR_NONE;

	gpio_init(port, &config);
	pin_set_tim_chn(TIMx, port, pin, channel);
	TIMx_base_init(TIMx, pcs, arr);
	set_chn(TIMx, channel,edge);

	TIMx->EGR|=(1);
	TIMx_base_start(TIMx);

}
uint32_t TIMx_get_data(TIM_TypeDef *TIMx,uint8_t channel){
	return chn_data(TIMx, channel);
}
