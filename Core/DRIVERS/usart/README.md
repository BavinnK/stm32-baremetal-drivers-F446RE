Bare-metal USART2 driver for STM32 with ring buffer support.
Configures TX/RX GPIO pins and enables USART2 clock.
AF settings, speed, and pull-ups are configured for TX/RX pins.
Baud rate is set using pre-calculated BRR values to avoid floating-point math.
USART2 is initialized with TX, RX, and RX interrupt enabled.
Supports sending a single byte or string using TX ring buffer.
RX data is stored in RX ring buffer via USART2 IRQ handler.
TX ring buffer data is transmitted automatically when TXE flag is set.
Polling is not required; IRQ-driven communication with software-managed ring buffers.
