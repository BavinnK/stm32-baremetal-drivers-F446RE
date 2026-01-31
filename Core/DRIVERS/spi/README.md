Bare-metal SPI2 driver for STM32.
Configures GPIO pins for MOSI, MISO, SCLK, and user-provided CS.
Sets alternate function, speed, type, and pull-up/down for SPI pins.
Enables SPI2 peripheral clock and sets master mode.
Configures clock polarity, phase, data frame format (MSB/LSB), and frequency.
Uses SSM/SSI to handle software-managed chip select.
Transmit and receive handled with polling via SR flags.
CS pin can be manually selected/deselected via helper functions.
No interrupts or DMA; simple polling-based SPI communication.
