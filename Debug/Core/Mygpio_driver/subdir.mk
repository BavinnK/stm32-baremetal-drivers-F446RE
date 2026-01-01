################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Mygpio_driver/gpiox.c 

OBJS += \
./Core/Mygpio_driver/gpiox.o 

C_DEPS += \
./Core/Mygpio_driver/gpiox.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Mygpio_driver/%.o Core/Mygpio_driver/%.su Core/Mygpio_driver/%.cyclo: ../Core/Mygpio_driver/%.c Core/Mygpio_driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/Mygpio_driver" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Mygpio_driver

clean-Core-2f-Mygpio_driver:
	-$(RM) ./Core/Mygpio_driver/gpiox.cyclo ./Core/Mygpio_driver/gpiox.d ./Core/Mygpio_driver/gpiox.o ./Core/Mygpio_driver/gpiox.su

.PHONY: clean-Core-2f-Mygpio_driver

