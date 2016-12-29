#ifndef CLOCK_H
#define CLOCK_H

/************** REGISTERS *************/
/** Internal Clock Control Register (RS=0x01) */
#define CLK_ICKR		*(unsigned char*)0x50C0
/** External Clock Control Register (RS=0x00) */
#define CLK_ECKRR		*(unsigned char*)0x50C1
/** Clock Master Status Register (RS=0xE1) */
#define CLK_CMSR		*(unsigned char*)0x50C3
/** Clock Master Switch Register (RS=0xE1) */
#define CLK_SWR			*(unsigned char*)0x50C4
/** Clock Switch Control Register (RS=0xXX) */
#define CLK_SWCR		*(unsigned char*)0x50C5
/** Clock Divider Register (RS=0x18) */
#define CLK_CKDIVR		*(unsigned char*)0x50C6
/** Peripheral Clock Gating Register 1 (RS=0xFF) */
#define	CLK_PCKENR1		*(unsigned char*)0x50C7
/** Clock Security System Register (RS=0x00) */
#define CLK_CSSR		*(unsigned char*)0x50C8
/** Configurable Clock Control Register (RS=0x00) */
#define CLK_CCOR		*(unsigned char*)0x50C9
/** Peripheral Clock Gating Register 2 (RS=0xFF) */
#define CLK_PCKENR2		*(unsigned char*)0x50CA
/** HSI Clock Calibration Trimming Register (RS=0x00) */
#define CLK_HSITRIMR	*(unsigned char*)0x50CC
/** SWIM Clock Control Register (RS=0bXXXXXXX0) */
#define CLK_SWIMCCR		*(unsigned char*)0x50CD


/********************** USER OPTIONS **********/

/** HighSpeed Internal RC Oscillator */
#define CLK_SRC_HSI	0xE1
/** LowSpeed Internal RC Oscillator */
#define CLK_SRC_LSI	0xD2
/** HighSpeed External Crystal */
#define CLK_SRC_HSE	0xB4
/** Current Active Clock Source */

//////////////////HSI PRESCALERS////////////////////
#define CLK_HSI_DIV_NONE			0x00 //00
#define CLK_HSI_DIV_TWO				0x01 //01
#define CLK_HSI_DIV_FOUR			0x02 //10
#define CLK_HSI_DIV_EIGHT			0x03 //11

#define CLK_CPU_DIV_MASTER_NONE			0x00 //000
#define CLK_CPU_DIV_MASTER_TWO			0x01 //001
#define CLK_CPU_DIV_MASTER_FOUR			0x02 //010
#define CLK_CPU_DIV_MASTER_EIGHT		0x03 //011
#define CLK_CPU_DIV_MASTER_SIXTEEN		0x04 //100
#define CLK_CPU_DIV_MASTER_THIRTYTWO		0x05 //101
#define CLK_CPU_DIV_MASTER_SIXTYFOUR		0x06 //110
#define CLK_CPU_DIV_MASTER_HUNTWENTYEIGHT	0x07 //111

/******* DELAY CONSTANTS ***************/
//only if used with provided implementation
#define CLK_DELAY_CYCLES_MS_16			(unsigned int)569
#define CLK_DELAY_CYCLES_MS_08  		(unsigned int)(DELAY_CYCLES_MS_16 / 2)
#define CLK_DELAY_CYCLES_MS_04			(unsigned int)(DELAY_CYCLES_MS_16 / 4)
#define CLK_DELAY_CYCLES_MS_02			(unsigned int)(DELAY_CYCLES_MS_16 / 8)
#define CLK_DELAY_CYCLES_MS_01			(unsigned int)(DELAY_CYCLES_MS_16 / 16)


/********** FUNCTION PROTOTYPES *********/

/**
* @brief: This functions calculates necessary cycles for exact delay.
*			This function should not be called by user! It will be called when
*           clock is changed by user.
* @retval: None
*/
static void CLK_Caluclate_Delay_Cycles();

void CLK_Set_HSE_Freq(unsigned long freq);

void CLK_Init(unsigned char clk_src, unsigned char ps
	, unsigned char cpu_div);

/**
* @brief: Delay for milliseconds
* @param m The amount of time to delay in milliseconds
* @retval none
*/
void CLK_Delay_ms(unsigned long ms);

#endif //end include guard
