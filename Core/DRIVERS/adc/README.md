ADC Driver (Bare-Metal)

This is a lightweight bare-metal ADC driver for STM32 microcontrollers F446RE nucleo. 
It supports ADC1, ADC2, and ADC3, and works with any channel from 0 to 15. 
The driver is designed to be simple and efficient, without using HAL or other libraries.

Before reading values, make sure the corresponding GPIO pin is set to analog mode using the  GPIO driver. 
You can initialize the ADC by calling adc_init(ADCx, &config) with the desired channel and configuration. 
To adjust the sample time for each channel, use channel_adc(ADCx, channel, sample).

To read data, use the blocking function adc_read(ADCx, channel). 
The example folder contains a simple main.c demonstrating how to set up a pin, initialize the ADC, and read values in a loop. 
This driver is intended for bare-metal projects where full control of the hardware is needed.