#ifndef MYTIMER_H_
#define MYTIMER_H_

#include "stm32f446xx.h"
#include <stdint.h>
#include "gpiox.h"//we might need this lib too but not sure yet

void TIM_init(void);
void TIM_start(void);
void TIM_stop(void);






#endif
