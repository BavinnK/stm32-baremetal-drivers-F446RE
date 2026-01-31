DMA bare-metal driver for STM32 (DMA1 / DMA2).
This driver initializes a DMA stream without using HAL or LL.
It enables the DMA clock, disables the stream, and clears all pending flags.
The stream is configured using a DMA_config_t structure provided by the user.
Channel, priority, data sizes, mode, and direction are written directly to CR.
Transfer length and addresses are loaded into NDTR, PAR, and M0AR.
Memory increment mode is enabled by default.
Double buffer mode and interrupts are not used.
After configuration, the DMA stream is enabled and ready to run.
