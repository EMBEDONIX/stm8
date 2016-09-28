/*
//BLINK Example for STM8S003F3

//In this example, I assume there are 8 LED's available.
//sorted by use in dance routine:
//PC3 -> PC4 -> PC5 -> PC6 -> PC7 -> PD1 -> PD2 -> PD3

//Remember that PD1 is the SWIM pin, so if we have an LED between this pin
//and ground, we can not flash the chip! so unconnect the LED from PD1 prior
//to flashing!
*/

#include "stm8s003.h"
#include "clock.h"
#include "gpio.h"

unsigned char pinsC = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 
			| GPIO_PIN_6 | GPIO_PIN_7;
unsigned char pinsD = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;

/**
*@brief Port D init routine
*/
void init_gpio() {

	//set LED pins
	GPIO_Set_Pins_Dir(&PC_DDR, pinsC , PIN_DIR_OUT);
	GPIO_Set_CR1(&PC_CR1, pinsC, PIN_MODE_PP);

	GPIO_Set_Pins_Dir(&PD_DDR, pinsD , PIN_DIR_OUT);
	GPIO_Set_CR1(&PD_CR1, pinsD, PIN_MODE_PP);
}

void dance() {

	unsigned short delay = 1;
	while(delay < 1000) {

		GPIO_Toggle_Pin(&PC_ODR, GPIO_PIN_3);
		CLK_Delay_ms(delay++);

		GPIO_Toggle_Pin(&PC_ODR, GPIO_PIN_4);
		CLK_Delay_ms(delay++);

		GPIO_Toggle_Pin(&PC_ODR, GPIO_PIN_5);
		CLK_Delay_ms(delay++);

		GPIO_Toggle_Pin(&PC_ODR, GPIO_PIN_6);
		CLK_Delay_ms(delay++);

		GPIO_Toggle_Pin(&PC_ODR, GPIO_PIN_7);
		CLK_Delay_ms(delay++);

		GPIO_Toggle_Pin(&PD_ODR, GPIO_PIN_1);
		CLK_Delay_ms(delay++);

		GPIO_Toggle_Pin(&PD_ODR, GPIO_PIN_2);
		CLK_Delay_ms(delay++);

		GPIO_Toggle_Pin(&PD_ODR, GPIO_PIN_3);
		CLK_Delay_ms(delay++);

		GPIO_Toggle_Pin(&PC_ODR, pinsC);
		GPIO_Toggle_Pin(&PD_ODR, pinsD);

		CLK_Delay_ms(delay);

		GPIO_Toggle_Pin(&PC_ODR, pinsC);
		GPIO_Toggle_Pin(&PD_ODR, pinsD);

		delay += 10;
	}
}


/**
*@brief Main function.
*/
int main() {
	CLK_Init(CLK_SRC_HSE, 0x00, 0x00);
	init_gpio();

	//main loop
	while(1) {
		dance();
	}
}
