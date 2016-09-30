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

#include "stdlib.h"

typedef struct LEDS {
	gpio_port_t 	port;
	gpio_pin_t	 	pin;
	struct LEDS*	next;
	struct LEDS*	prev;
} leds_t;

leds_t* head;
leds_t* tail;

unsigned char pinsC = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 
			| GPIO_PIN_6 | GPIO_PIN_7;
unsigned char pinsD = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;

leds_t* generateLed(gpio_port_t port, gpio_pin_t pin, leds_t* prev) {
	leds_t* led = malloc(sizeof(*led));
	led->port = port;
	led->pin = pin;
	if(prev) {
		led->prev = prev;
	}
	return led;
}

unsigned int goForwardToggling(leds_t* from, leds_t* to, unsigned int baseDelay,
	int delayInc){
	leds_t* tmp = from;
	
	do {
		GPIO_Toggle_Pin(tmp->port, tmp->pin);
		CLK_Delay_ms(baseDelay += delayInc);
		GPIO_Toggle_Pin(tmp->port, tmp->pin);
		tmp = tmp->next;
	} while(tmp != to->next);

	return baseDelay;
}

unsigned int goBackwardToggling(leds_t* from, leds_t* to, unsigned int baseDelay,
	int delayInc){
	leds_t* tmp = from;

	do {
		GPIO_Toggle_Pin(tmp->port, tmp->pin);
		CLK_Delay_ms(baseDelay += delayInc);
		GPIO_Toggle_Pin(tmp->port, tmp->pin);
		tmp = tmp->prev;
	} while(tmp != to->prev);

	return baseDelay;
}

unsigned int goForwardOn(leds_t* from, leds_t* to, unsigned int baseDelay,
	int delayInc){
	leds_t* tmp = from;

	do {
		GPIO_Set_Pin_High(tmp->port, tmp->pin);
		CLK_Delay_ms(baseDelay += delayInc);
		tmp = tmp->next;
	} while(tmp != to->next);	

	return baseDelay;
}

unsigned int goForwardOff(leds_t* from, leds_t* to, unsigned int baseDelay,
	int delayInc){
	leds_t* tmp = from;

	do {
		GPIO_Set_Pin_Low(tmp->port, tmp->pin);
		CLK_Delay_ms(baseDelay += delayInc);
		tmp = tmp->next;
	} while(tmp != to->next);	

	return baseDelay;
}


void dance() {

	volatile unsigned short delay = 20;
	while(delay < 1000) {
		goForwardToggling(head, tail, delay, 0);
		CLK_Delay_ms(100);
		goBackwardToggling(tail, head, delay, 0);
		CLK_Delay_ms(100);
		goBackwardToggling(tail, head, delay, 0);
		goForwardOn(head, tail, delay, 0);
		CLK_Delay_ms(100);
		goForwardOff(head, tail, delay, 0);
		CLK_Delay_ms(100);
		// goForwardOn(head, tail, delay, 0);
		// CLK_Delay_ms(400);

		// GPIO_Set_Pin_High(GPIO_PORT_C, GPIO_PIN_3);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_High(GPIO_PORT_C, GPIO_PIN_4);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_High(GPIO_PORT_C, GPIO_PIN_5);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_High(GPIO_PORT_C, GPIO_PIN_6);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_High(GPIO_PORT_C, GPIO_PIN_7);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_High(GPIO_PORT_D, GPIO_PIN_1);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_High(GPIO_PORT_D, GPIO_PIN_2);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_High(GPIO_PORT_D, GPIO_PIN_3);

		// CLK_Delay_ms(400);												

		// GPIO_Set_Pin_Low(GPIO_PORT_C, GPIO_PIN_3);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_Low(GPIO_PORT_C, GPIO_PIN_4);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_Low(GPIO_PORT_C, GPIO_PIN_5);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_Low(GPIO_PORT_C, GPIO_PIN_6);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_Low(GPIO_PORT_C, GPIO_PIN_7);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_Low(GPIO_PORT_D, GPIO_PIN_1);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_Low(GPIO_PORT_D, GPIO_PIN_2);
		// CLK_Delay_ms(100);
		// GPIO_Set_Pin_Low(GPIO_PORT_D, GPIO_PIN_3);
		
		// CLK_Delay_ms(400);		
	}
}

/**
*@brief Port D init routine
*/
void init_gpio() {

	//set LED pins
	GPIO_Config_Pin(GPIO_PORT_C, pinsC , PIN_MODE_OUTPUT_PP_FAST);
	GPIO_Config_Pin(GPIO_PORT_D, pinsD , PIN_MODE_OUTPUT_PP_FAST);
}

/**
*@brief Main function.
*/
int main() {
	CLK_Init(CLK_SRC_HSE, 0x00, 0x00);
	init_gpio();

	//create circular connection
	//led 1
	head = generateLed(GPIO_PORT_C, GPIO_PIN_3,
		0);
	
	//led 2
	head->next = generateLed(GPIO_PORT_C, GPIO_PIN_4,
		head);

	//led 3
	head->next->next = generateLed(GPIO_PORT_C, GPIO_PIN_5,
		head->next);
	
	//led 4
	head->next->next->next = generateLed(GPIO_PORT_C, GPIO_PIN_6,
		head->next->next);

	//led 5
	head->next->next->next->next = generateLed(GPIO_PORT_C, GPIO_PIN_7,
		head->next->next->next);

	//led 6
	head->next->next->next->next->next = generateLed(GPIO_PORT_D, GPIO_PIN_1,
		head->next->next->next->next);

	//led 7
	head->next->next->next->next->next->next = generateLed(GPIO_PORT_D, GPIO_PIN_2,
		head->next->next->next->next->next);

	//led 8
	tail = generateLed(GPIO_PORT_D, GPIO_PIN_3,
		head->next->next->next->next->next->next);

	//connect led 1 and 8
	head->prev = tail;
	tail->next = head;
	
	//main loop
	while(1) {
		dance();
	}
}
