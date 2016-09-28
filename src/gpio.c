#include "gpio.h"

void GPIO_Set_Pins_Dir(unsigned char* p_ddr, unsigned char pins,
			unsigned char direction) {
	if(direction) {
		*p_ddr = pins & 0xFF;
	} else {
		*p_ddr = pins & 0x00;
	}
}
void GPIO_Set_CR1(unsigned char* p_cr1, unsigned char pins,
			unsigned char mode) {
	if(mode) { //push-pull = 1
		*p_cr1 = pins & 0xFF;
	} else {
		*p_cr1 = pins & 0x00; 
	}
}
void GPIO_Set_CR2(unsigned char* p_cr2, unsigned char pins,
			unsigned char val) {
	//TODO implement
	if(val) { //push-pull = 1
		*p_cr2 = pins & 0xFF;
	} else {
		*p_cr2 = pins & 0x00; 
	}	
}

void GPIO_Set_Pin_High(unsigned char* p_odr, unsigned char pins) {
	*p_odr = pins & 0xFF;
}
void GPIO_Set_Pin_Low(unsigned char* p_odr, unsigned char pins) {
	*p_odr = pins & 0x00;
}
void GPIO_Toggle_Pin(unsigned char* p_odr, unsigned char pins) {
	*p_odr ^= pins; 
}
