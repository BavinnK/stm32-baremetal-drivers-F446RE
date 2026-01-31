# STM32 Bare-Metal Drivers for F446RE

## Project Overview

This repository contains a collection of **bare‑metal drivers** for the **STM32F446RE** microcontroller.
All drivers are written in **pure C**, without using HAL, LL, or any external framework.
The goal of this project is to provide **clean, readable, and educational drivers** that show how peripherals
work at the register level.

The code is designed to be **simple, user‑friendly**, and easy to integrate into custom projects.

## Drivers Included

This repository currently provides drivers for:

- GPIO
- DMA
- ADC
- Timers  
  - Timer Base (shared core)
  - Input Capture
  - Output Compare
  - PWM
- I2C
- SPI
- USART
- HC‑SR04 Ultrasonic Sensor (I2C-based usage)


## How to Use

Each driver is located inside the `drivers/` directory.
To use a driver, include its **.c** and **.h** files in your project and make sure the required
core files are included as well.

Every driver folder contains:
- The driver source and header files
- A small README explaining what the driver does
- Clear comments inside the code explaining each step and register usage

## Notes

- All peripherals are configured manually using registers
- No HAL, no LL, no CMSIS helper layers
- Designed for learning, debugging, and full control over hardware
- Suitable for educational projects and custom firmware development
