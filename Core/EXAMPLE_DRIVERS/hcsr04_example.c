#include "Myhcsr04.h"
#include "stm32f446xx.h"


int example_hcsr04_main(void) {
    //becareful for one thing my driver is hardcoded for TIM1
	GPIO_TypeDef *trig_port= GPIOA;//echo port
	uint8_t echo_pin=10;

	GPIO_TypeDef *echo_port= GPIOB;
	uint8_t trig_pin=8;

	hcsr04_init(trig_port, echo_port, trig_pin, echo_pin);


    while(1) {
       uint32_t distance_cm=hcsr04_get_pulse_width()/58;

       //then give it to usart and ur good togo :)
    }
}
