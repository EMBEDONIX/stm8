#include "clock.h"


void CLK_Init(unsigned char clk_src, unsigned char ps
	, unsigned char cpu_div) {
	/*
	DocID13587 Rev 12 P.82
	1. settin SWEN bit in CLK_SWCR
	2. write8bit value used to select the target clock src in CLK_SWR
	3. CLK_SWCR register is set by hardware
	*/

	//return if settings are already what user wants
	if(CLK_SWCR == clk_src) {
		//TODO simplify this for less instructions!
		//check if CPU_DIV is bigger than Fmaster/8
		//check if 2nd but if CPU_CLKDIVR is 1 it means Fcpu is 
		//divided by bigger than 8
		return;
	}

	if(clk_src == CLK_SRC_HSI) {
		//set dividers
		CLK_CKDIVR = (ps << 3) | (cpu_div << 0);
		return;
	}

	if(clk_src == CLK_SRC_HSE) {

		CLK_ECKRR |= 0x1 >> 0;
		CLK_SWCR |= 1 << 1;
		CLK_SWR = clk_src;
	}
	//wait for clock source to change
	while(CLK_SWR != CLK_CMSR) { /* DO NOTHING */};
}


/**
*@brief Delay routine for milliseconds for 16MHz clock.
*The 960 comes from the number of instructions to perform the do/while loop
*to figure it out, have a look at the generated ASM file after compilation
*/
void CLK_Delay_ms(unsigned long ms) {
	unsigned long cycles = CLK_DELAY_CYCLES_MS_16 * ms;
	volatile unsigned long int i = 0;
	for(i = 0; i < cycles; i++) {
		/* DO NOTHING BUT WASTE CYCLES */
	}
}


