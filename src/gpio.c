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

void GPIO_Set_Pin_High(gpio_port_t port, gpio_pin_t pins) {
	*port |= pins;
}
void GPIO_Set_Pin_Low(gpio_port_t port, gpio_pin_t pins) {
	*port &= ~(pins);
}
void GPIO_Toggle_Pin(gpio_port_t port, gpio_pin_t pins) {
	*port ^= pins;
}

unsigned char GPIO_Read_Pin(gpio_port_t port, gpio_pin_t pin) {
	//return ((*(port + GPIO_OFST_IDR)) & (1 << pin)) << pin;

	return *(port + GPIO_OFST_IDR) & pin;
}

unsigned char GPIO_Read_Port(gpio_port_t port) {
	return *(port + GPIO_OFST_IDR);
}
