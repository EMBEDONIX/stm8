//SM8S003 Registers
//Author: Saeid Yazdani
//Website: www.embedonix.com
//original file was provided by SDCC for STM8L
//but I just edited it to make it compatible with STM8S
#ifndef STM8S003_H
#define STM8S003_H

/* ------------------- GPIO ------------------- */
//moved to gpio.h

/* ------------------- CLOCK ------------------- */
//moved to clock.h

/* ------------------- WD ------------------- */


/* ------------------- USART ------------------- */
#define USART1_SR 		*(unsigned char*)0x5230
#define USART1_DR 		*(unsigned char*)0x5231
#define USART1_BRR1 	*(unsigned char*)0x5232
#define USART1_BRR2 	*(unsigned char*)0x5233
#define USART1_CR1 		*(unsigned char*)0x5234
#define USART1_CR2 		*(unsigned char*)0x5235
#define USART1_CR3		*(unsigned char*)0x5236
#define USART1_CR4		*(unsigned char*)0x5237
#define USART1_CR5		*(unsigned char*)0x5238
#define USART1_GTR		*(unsigned char*)0x5239
#define USART1_PSCR		*(unsigned char*)0x523A

/* USART_CR1 bits */
#define USART_CR1_R8 	(1 << 7)
#define USART_CR1_T8 	(1 << 6)
#define USART_CR1_UARTD (1 << 5)
#define USART_CR1_M 	(1 << 4)
#define USART_CR1_WAKE 	(1 << 3)
#define USART_CR1_PCEN 	(1 << 2)
#define USART_CR1_PS 	(1 << 1)
#define USART_CR1_PIEN 	(1 << 0)

/* USART_CR2 bits */
#define USART_CR2_TIEN 	(1 << 7)
#define USART_CR2_TCIEN (1 << 6)
#define USART_CR2_RIEN 	(1 << 5)
#define USART_CR2_ILIEN (1 << 4)
#define USART_CR2_TEN 	(1 << 3)
#define USART_CR2_REN 	(1 << 2)
#define USART_CR2_RWU 	(1 << 1)
#define USART_CR2_SBK 	(1 << 0)

/* USART_CR3 bits */
#define USART_CR3_LINEN (1 << 6)
#define USART_CR3_STOP2 (1 << 5)
#define USART_CR3_STOP1 (1 << 4)
#define USART_CR3_CLKEN (1 << 3)
#define USART_CR3_CPOL 	(1 << 2)
#define USART_CR3_CPHA 	(1 << 1)
#define USART_CR3_LBCL 	(1 << 0)

/* USART_SR bits */
#define USART_SR_TXE 	(1 << 7)
#define USART_SR_TC 	(1 << 6)
#define USART_SR_RXNE 	(1 << 5)
#define USART_SR_IDLE 	(1 << 4)
#define USART_SR_OR 	(1 << 3)
#define USART_SR_NF 	(1 << 2)
#define USART_SR_FE 	(1 << 1)
#define USART_SR_PE 	(1 << 0)


/* ------------------- TIMERS ------------------- */
#define TIM1_CR1 	*(unsigned char*)0x52B0
#define TIM1_CR2 	*(unsigned char*)0x52B1
#define TIM1_SMCR 	*(unsigned char*)0x52B2
#define TIM1_ETR 	*(unsigned char*)0x52B3
#define TIM1_DER 	*(unsigned char*)0x52B4
#define TIM1_IER 	*(unsigned char*)0x52B5
#define TIM1_SR1 	*(unsigned char*)0x52B6
#define TIM1_SR2 	*(unsigned char*)0x52B7
#define TIM1_EGR 	*(unsigned char*)0x52B8
#define TIM1_CCMR1 	*(unsigned char*)0x52B9
#define TIM1_CCMR2 	*(unsigned char*)0x52BA
#define TIM1_CCMR3 	*(unsigned char*)0x52BB
#define TIM1_CCMR4 	*(unsigned char*)0x52BC
#define TIM1_CCER1 	*(unsigned char*)0x52BD
#define TIM1_CCER2 	*(unsigned char*)0x52BE
#define TIM1_CNTRH 	*(unsigned char*)0x52BF
#define TIM1_CNTRL 	*(unsigned char*)0x52C0
#define TIM1_PSCRH 	*(unsigned char*)0x52C1
#define TIM1_PSCRL 	*(unsigned char*)0x52C2
#define TIM1_ARRH 	*(unsigned char*)0x52C3
#define TIM1_ARRL 	*(unsigned char*)0x52C4
#define TIM1_RCR 	*(unsigned char*)0x52C5
#define TIM1_CCR1H 	*(unsigned char*)0x52C6
#define TIM1_CCR1L 	*(unsigned char*)0x52C7
#define TIM1_CCR2H 	*(unsigned char*)0x52C8
#define TIM1_CCR2L 	*(unsigned char*)0x52C9
#define TIM1_CCR3H 	*(unsigned char*)0x52CA
#define TIM1_CCR3L 	*(unsigned char*)0x52CB
#define TIM1_CCR4H 	*(unsigned char*)0x52CC
#define TIM1_CCR4L 	*(unsigned char*)0x52CD
#define TIM1_BKR 	*(unsigned char*)0x52CE
#define TIM1_DTR 	*(unsigned char*)0x52CF
#define TIM1_OISR 	*(unsigned char*)0x52D0
#define TIM1_DCR1 	*(unsigned char*)0x52D1
#define TIM1_DCR2 	*(unsigned char*)0x52D2
#define TIM1_DMA1R 	*(unsigned char*)0x52D3

/* TIM_IER bits */
#define TIM_IER_BIE 	(1 << 7)
#define TIM_IER_TIE 	(1 << 6)
#define TIM_IER_COMIE 	(1 << 5)
#define TIM_IER_CC4IE 	(1 << 4)
#define TIM_IER_CC3IE 	(1 << 3)
#define TIM_IER_CC2IE 	(1 << 2)
#define TIM_IER_CC1IE 	(1 << 1)
#define TIM_IER_UIE 	(1 << 0)

/* TIM_CR1 bits */
#define TIM_CR1_APRE 	(1 << 7)
#define TIM_CR1_CMSH 	(1 << 6)
#define TIM_CR1_CMSL 	(1 << 5)
#define TIM_CR1_DIR 	(1 << 4)
#define TIM_CR1_OPM 	(1 << 3)
#define TIM_CR1_URS 	(1 << 2)
#define TIM_CR1_UDIS 	(1 << 1)
#define TIM_CR1_CEN 	(1 << 0)

/* TIM_SR1 bits */
#define TIM_SR1_BIF 	(1 << 7)
#define TIM_SR1_TIF 	(1 << 6)
#define TIM_SR1_COMIF 	(1 << 5)
#define TIM_SR1_CC4IF 	(1 << 4)
#define TIM_SR1_CC3IF 	(1 << 3)
#define TIM_SR1_CC2IF 	(1 << 2)
#define TIM_SR1_CC1IF 	(1 << 1)
#define TIM_SR1_UIF 	(1 << 0)



#endif //end include gaurd
