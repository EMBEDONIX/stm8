#include "dance.h"
#include "clock.h"
#include "stdlib.h" //for malloc

dance_t* d_head = 0;
dance_t* d_tail = 0;

dance_t* DNC_Gen_Struct(gpio_port_t port, gpio_pin_t pin, dance_t* prev) {
	dance_t* dnc = malloc(sizeof(*dnc));
	if(!dnc) { //check malloc result
		return 0; //malloc failed, return null pointer
	}
	//malloc success, continue!
	dnc->port = port;
	dnc->pin = pin;

	//even null pointer will be assigned to prev, so clear up your mind!
	dnc->prev = prev;
	return dnc;
}

void DNC_Toggling(dance_t* from, dance_t* to, unsigned char dir,
	unsigned char skip, int* baseDelay, int incDelay,
	int endDelay) {

	unsigned char si;
	dance_t* tmp = from;

	if(dir == DANCE_DIR_FORWARD) {
		do {
			//toggle, delay, toggle
			GPIO_Toggle_Pin(tmp->port, tmp->pin);
			CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));
			GPIO_Toggle_Pin(tmp->port, tmp->pin);

			//skip pins
			for(si = 0; si < skip + 1; si++) {
				if(tmp->next)
					tmp = tmp->next;
				else
					return;
			}
		} while(tmp  != to->next); 
	} else { //backward
		do {
			//toggle, delay, toggle
			GPIO_Toggle_Pin(tmp->port, tmp->pin);
			CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));
			GPIO_Toggle_Pin(tmp->port, tmp->pin);

			//skip pins
			for(si = 0; si < skip + 1; si++) {
				if(tmp->prev)
					tmp = tmp->prev;
				else
					return;
			}

		} while(tmp  != to->prev); 
	}

	*baseDelay += endDelay;
}

void DNC_On(dance_t* from, dance_t* to, unsigned char dir,
	unsigned char skip, int* baseDelay, int incDelay,
	int endDelay) {

	unsigned char si;
	dance_t* tmp = from;

	if(dir == DANCE_DIR_FORWARD) {
		do {
			//toggle, delay, toggle
			GPIO_Set_Pin_High(tmp->port, tmp->pin);
			CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));

			//skip pins
			for(si = 0; si < skip + 1; si++) {
				if(tmp->next)
					tmp = tmp->next;
				else
					return;
			}
		} while(tmp  != to->next); 
	} else { //backward
		do {
			//toggle, delay, toggle
			GPIO_Set_Pin_High(tmp->port, tmp->pin);
			CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));

			//skip pins
			for(si = 0; si < skip + 1; si++) {
				if(tmp->prev)
					tmp = tmp->prev;
				else
					return;
			}

		} while(tmp  != to->prev); 
	}

	*baseDelay += endDelay;
}

void DNC_Off(dance_t* from, dance_t* to, unsigned char dir, 
	unsigned char skip, int* baseDelay, int incDelay,
	int endDelay) {
	
	unsigned char si;
	dance_t* tmp = from;

	if(dir == DANCE_DIR_FORWARD) {
		do {
			//toggle, delay, toggle
			GPIO_Set_Pin_Low(tmp->port, tmp->pin);
			CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));

			//skip pins
			for(si = 0; si < skip + 1; si++) {
				if(tmp->next)
					tmp = tmp->next;
				else
					return;
			}
		} while(tmp  != to->next); 
	} else { //backward
		do {
			//toggle, delay, toggle
			GPIO_Set_Pin_Low(tmp->port, tmp->pin);
			CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));

			//skip pins
			for(si = 0; si < skip + 1; si++) {
				if(tmp->prev)
					tmp = tmp->prev;
				else
					return;
			}

		} while(tmp  != to->prev); 
	}

	*baseDelay += endDelay;
}

void DNC_AllOnOff(dance_t* head, unsigned char cycles, int* baseDelay,
	int incDelay) {

	dance_t* tmp;
	if(cycles == 0) {
		cycles++; //make sure we have at least one cycle!
	}	

	do {
		tmp = head;
		while(tmp) {
			GPIO_Set_Pin_High(tmp->port, tmp->pin);
			tmp = tmp->next;
		}

		CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));
		
		tmp = head;
		while(tmp) {
			GPIO_Set_Pin_Low(tmp->port, tmp->pin);
			tmp = tmp->next;
		}
		
		CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));
		cycles--;
	} while(cycles > 0);
}

void DNC_AllOffOn(dance_t* head, unsigned char cycles, int* baseDelay,
	int incDelay) {

	dance_t* tmp;
	if(cycles == 0) {
		cycles++; //make sure we have at least one cycle!
	}

	do {
		tmp = head;
		while(tmp) {
			GPIO_Set_Pin_Low(tmp->port, tmp->pin);			
			tmp = tmp->next;
		}

		CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));
		
		tmp = head;
		while(tmp) {
			GPIO_Set_Pin_High(tmp->port, tmp->pin);
			tmp = tmp->next;
		}
		
		CLK_Delay_ms((unsigned long)(*baseDelay += incDelay));
		cycles--;
	} while(cycles > 0);	
}