#include "stm8s.h"

void init_clk() {
	CLK_CKDIVR = 0x00; //16MHZ
	CLK_PCKENR1 = 0xFF; // Enable peripherals
}

void init_port_d() {
	//In this example, I assume there are 3 LED's available.
	//PD2, PD3 and PD4

	//remember that PD1 is the SWIM pin, so if we have an LED between this pin
	//and ground, we can not flash the chip!

	//set OutputDataRegister to 0 for all pins of PortD
	PD_ODR = 0; //turn off all pins

	//set DataDirectionRegister for PD1, PD2 and PD3 to 1
	PD_DDR |= 1 << 2; //now PD_DDR is 0x00000100
	PD_DDR |= 1 << 3; //now PD_DDR is 0x00001100
	PD_DDR |= 1 << 4; //now PD_DDR is 0x00011100

	//same as above but for ControlRegister1
	PD_CR1 |= 1 << 2;
	PD_CR1 |= 1 << 3;
	PD_CR1 |= 1 << 4; 
}

void delay_ms(unsigned long ms) {
	//The best naive delay @16MHz
	//the 960 comes from the number of instructions to perform the do/while loop
	//to figure it out, have a look at the generated ASM file after compilation
	unsigned long cycles = 960 * ms;
	int i = 0;
	do
	{
		cycles--;
	}
	while(cycles > 0);
}

void toggle_port_d_pin(unsigned int pin) {
	PD_ODR ^= 1 << pin;
}


int main() {
	init_clk();
	init_port_d();

	//main loop
	while(1) {
		toggle_port_d_pin(2);
		delay_ms(1000);
		toggle_port_d_pin(2);
		toggle_port_d_pin(4);
		delay_ms(1000);
		toggle_port_d_pin(4);
		toggle_port_d_pin(3);
		delay_ms(1000);		
		toggle_port_d_pin(3);
	}
}
