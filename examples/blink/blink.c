/*
//BLINK Example for STM8S003F3

//In this example, I assume there is one LED's available on PD3
*/

#include "stm8s003.h"
#include "gpio.h"
#include "clock.h"


/**
*@brief Port D init routine
*/
void init_gpio() {
	GPIO_Config_Pin(GPIO_PORT_D, GPIO_PIN_3, PIN_MODE_OUTPUT_PP);
}

/**
*@brief Main function.
*/
int main() {
	CLK_Init(CLK_SRC_HSI, CLK_HSI_DIV_NONE, CLK_CPU_DIV_MASTER_NONE);
	init_gpio();

	//main loop
	while(1) {
		GPIO_Toggle_Pin(GPIO_PORT_D, GPIO_PIN_3);
		CLK_Delay_ms(1000);
		GPIO_Toggle_Pin(GPIO_PORT_D, GPIO_PIN_3);
		CLK_Delay_ms(500);
		GPIO_Toggle_Pin(GPIO_PORT_D, GPIO_PIN_3);
		CLK_Delay_ms(250);

	}
}
