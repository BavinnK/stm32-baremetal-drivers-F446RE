myTimerIC (Input Capture)
This driver builds on the timer base driver.
It configures timer channels in input capture mode.
Used to measure signal timing such as period, frequency, or pulse width.
Capture registers are read directly when events occur.
Polling-based implementation, no interrupts by default.

myTimerOC (Output Compare)
This driver depends on the timer base initialization.
It configures timer channels in output compare mode.
Used to generate timed events or toggled outputs.
Compare values are written directly to CCR registers.
Does not generate PWM signals.

myTimerPWM (PWM)
This driver extends the timer base driver for PWM generation.
Timer channels are configured in PWM mode.
Duty cycle is controlled via compare registers.
Frequency is set using prescaler and auto-reload values.
Used for motor control, LEDs, and general signal generation.
