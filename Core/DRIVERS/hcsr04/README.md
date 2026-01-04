Bare-metal driver for HCSR04 ultrasonic sensor on STM32F4.

	-Automatically sets up trigger and echo pins
	-Uses TIM1 input capture to measure pulse width
	-Includes overflow handling
	-Simple trigger and read functions

Usage:

	1-Call hcsr04_init(trig_port, echo_port, trig_pin, echo_pin)
	2-Trigger with hcsr04_trig_hc(trig_port, trig_pin)
	3-Read pulse width with hcsr04_get_pulse_width()