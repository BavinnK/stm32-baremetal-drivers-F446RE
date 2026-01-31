Bare-metal I2C driver for STM32 (I2C1 / I2C2 / I2C3).
This driver configures I2C GPIO pins manually and enables the I2C peripheral clock.
Pins are set to AF open-drain with pull-ups according to the selected I2C instance.
I2C timing is configured for standard mode using CR2, CCR, and TRISE.
Start and stop conditions are generated directly via CR1.
Write operation sends slave address, register address, then data.
Read operation uses repeated start and supports 1, 2, or multiple bytes.
ADDR, TXE, and RXNE flags are handled explicitly by reading SR1 and SR2.
No interrupts or DMA are used; polling-based implementation only.
