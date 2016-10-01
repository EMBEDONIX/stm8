#ifndef DANCE_H
#define DANCE_H

#include "gpio.h"

#define DANCE_DIR_FORWARD		1
#define DANCE_DIR_BACKWARD		0

typedef struct DANCE {
	gpio_port_t 	port;
	gpio_pin_t	 	pin;
	struct DANCE*	next;
	struct DANCE*	prev;
} dance_t;

extern dance_t* d_head;
extern dance_t* d_tail; 

/**
*@brief Generate a
*
*
*/
dance_t* DNC_Gen_Struct(gpio_port_t port, gpio_pin_t pin, dance_t* prev);

void DNC_Toggling(dance_t* from, dance_t* to, unsigned char dir,
	unsigned char skip, int* baseDelay, int incDelay,
	int endDelay);

void DNC_On(dance_t* from, dance_t* to, unsigned char dir,
	unsigned char skip, int* baseDelay, int incDelay,
	int endDelay);

void DNC_Off(dance_t* from, dance_t* to, unsigned char dir,
	unsigned char skip, int* baseDelay, int incDelay,
	int endDelay);

void DNC_AllOnOff(dance_t* head, unsigned char cycles, int* baseDelay,
	int incDelay);

void DNC_AllOffOn(dance_t* head, unsigned char cycles, int* baseDelay,
	int incDelay);	

#endif