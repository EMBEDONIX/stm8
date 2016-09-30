#include "gpio.h"


void GPIO_Config_Pin(gpio_port_t port, gpio_pin_t pins,
	unsigned char pin_mode) {

	if(pin_mode > 0x07) {
		//TODO figure out to implement PIN_MODE_OUTPUT_TRUE_OD
		return; //for now, supported modes are 0 to 7
	}

	//set DDR, CR1 and CR2 registers
	//DDR is the 3rd bit of pin_mode
	((pin_mode & ( 1 << 2)) >> 2) == 1 ? 
	*(port + GPIO_OFST_DDR) = pins & 0xFF :
								pins & 0x00;

	//CR1 is the 2nd bit of pin_mode
	((pin_mode & ( 1 << 1)) >> 1) == 1 ? 
	*(port + GPIO_OFST_CR1) = pins & 0xFF :
									pins & 0x00;
	//CR2 is the 1st bit of pin_mode
	((pin_mode & ( 1 << 0)) >> 0) == 1 ? 
	*(port + GPIO_OFST_CR2) = pins & 0xFF :
									pins & 0x00;
}

// void GPIO_Set_Pins_Dir(unsigned char* p_ddr, unsigned char pins,
// 			unsigned char direction) {
// 	if(direction) {
// 		*p_ddr = pins & 0xFF;
// 	} else {
// 		*p_ddr = pins & 0x00;
// 	}
// }
// void GPIO_Set_CR1(unsigned char* p_cr1, unsigned char pins,
// 			unsigned char mode) {
// 	if(mode) { //push-pull = 1
// 		*p_cr1 = pins & 0xFF;
// 	} else {
// 		*p_cr1 = pins & 0x00; 
// 	}
// }
// void GPIO_Set_CR2(unsigned char* p_cr2, unsigned char pins,
// 			unsigned char val) {
// 	//TODO implement
// 	if(val) { //push-pull = 1
// 		*p_cr2 = pins & 0xFF;
// 	} else {
// 		*p_cr2 = pins & 0x00; 
// 	}	
// }

void GPIO_Set_Pin_High(gpio_port_t port, gpio_pin_t pins) {
	*port |= pins & 0xFF;
}
void GPIO_Set_Pin_Low(gpio_port_t port, gpio_pin_t pins) {
	*port &= ~(pins);
}
void GPIO_Toggle_Pin(gpio_port_t port, gpio_pin_t pins) {
	*port ^= pins;
}

unsigned char GPIO_Read_Pin(gpio_port_t port, gpio_pin_t pin) {
	return ((*(port + GPIO_OFST_IDR)) & (1 << pin)) << pin;
}

unsigned char GPIO_Read_Port(gpio_port_t port) {
	return *(port + GPIO_OFST_IDR);
}