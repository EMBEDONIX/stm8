#include "stm8s003.h"
#include <string.h> //for strlen()

int uart_write(const char *str) {
	char i;
	for(i = 0; i < strlen(str); i++) {
		while(!(USART1_SR & USART_SR_TXE));
		USART1_DR = str[i];
	}
	return(i); // Bytes sent
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

int main() {
	unsigned long i = 0;
	CLK_CKDIVR = 0x00;
	CLK_PCKENR1 = 0xFF; // Enable peripherals

	PC_DDR = 0x08; // Put TX line on
	PC_CR1 = 0x08;

	USART1_CR2 = USART_CR2_TEN; // Allow TX & RX
	USART1_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
	USART1_BRR2 = 0x03; USART1_BRR1 = 0x68; // 9600 baud@16MHz CLK

	//main loop
	while(1) {
		uart_write("Visit http://embedonix.com/tag/stm8 for more info!\r\n");
		delay_ms(1000);
	}
}
