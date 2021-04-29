# Control-Systems-Programming-lab-projects


## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Assignments](#assignments)

## General info
Repo dedicated to tracking lab assignments of the Control Systems Programming module.

A [STM32F407VG](https://www.st.com/en/evaluation-tools/stm32f4discovery.html) board was used during development.

Lab_XXX\Core\Src\main.c is where most of the code was written.
	
## Technologies:
* [Clion 2020.3.2](https://www.jetbrains.com/clion/)
* [XPack's OpenOCD](https://xpack.github.io/openocd/)
* [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
	
## Assignments:
| No | Lab assingment | Directory name | Description |
|---|---|---|---|
| 1 |	LED blink | Lab_LED | All the onboard LED's blinking every second |
| 2 |	LED + button | Lab_LED_Button | Pressing the onboard button lights up all the onboard LED's |
| 3 |	LED Timer | Lab_III_LED_Timer | The blue LED pulses by using TIM4 |
| 4 |	LED + Timer + PWM | Lab_V_PWM_LED_Timer_Button | Pressing and holding the onboard button makes the onboard LED's pulse one after another clockwise |
| 5 |	LED+Button+Interrupt | Lab_VI_PWM_LED_Interrupt_Button | Two LED's on opposite sides are always pulsing, by pressing the button the EXTI0 interrupt is called which changes the flag and makes the other two LED's pulse | 
| 6 |	ADC (pagal tutorial) | None | Didn't have external analog inputs to hook up |
| 7 |	ADC + Interrupt | None | Didn't have external analog inputs to hook up |
| 8 |	UART | Lab_VIII_UART | Didn't have the UART connector, cannot confirm the code works. By using the UART it's possible to turn on one of the onboard LED's on and off |
| 9 |	UART + Interrupt | None | Didn't have the UART connector |
