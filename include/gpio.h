#ifndef GPIO_H
#define GPIO_H

/* ------------------- GPIO ------------------- */

/* ------------------- REGISTERS -------------- */
#define PA_ODR *(unsigned char*)0x5000
#define PA_IDR *(unsigned char*)0x5001
#define PA_DDR *(unsigned char*)0x5002
#define PA_CR1 *(unsigned char*)0x5003
#define PA_CR2 *(unsigned char*)0x5004

#define PB_ODR *(unsigned char*)0x5005
#define PB_IDR *(unsigned char*)0x5006
#define PB_DDR *(unsigned char*)0x5007
#define PB_CR1 *(unsigned char*)0x5008
#define PB_CR2 *(unsigned char*)0x5009

#define PC_ODR *(unsigned char*)0x500A
#define PC_IDR *(unsigned char*)0x500B
#define PC_DDR *(unsigned char*)0x500C
#define PC_CR1 *(unsigned char*)0x500D
#define PC_CR2 *(unsigned char*)0x500E

#define PD_ODR *(unsigned char*)0x500F
#define PD_IDR *(unsigned char*)0x5010
#define PD_DDR *(unsigned char*)0x5011
#define PD_CR1 *(unsigned char*)0x5012
#define PD_CR2 *(unsigned char*)0x5013

#define PE_ODR *(unsigned char*)0x5014
#define PE_IDR *(unsigned char*)0x5015
#define PE_DDR *(unsigned char*)0x5016
#define PE_CR1 *(unsigned char*)0x5017
#define PE_CR2 *(unsigned char*)0x5018

#define PF_ODR *(unsigned char*)0x5019
#define PF_IDR *(unsigned char*)0x501A
#define PF_DDR *(unsigned char*)0x501B
#define PF_CR1 *(unsigned char*)0x501C
#define PF_CR2 *(unsigned char*)0x501D

/* ------------------- PINS ------------------- */
#define GPIO_PIN_0		1
#define GPIO_PIN_1		2
#define GPIO_PIN_2		4
#define GPIO_PIN_3		8
#define GPIO_PIN_4		16
#define GPIO_PIN_5		32
#define GPIO_PIN_6		64
#define GPIO_PIN_7		128
#define GPIO_PIN_ALL	255

/* ------------------- PORTS ------------------ */
#define GPIO_PORT_A	0
#define GPIO_PORT_B	1
#define GPIO_PORT_C	2
#define GPIO_PORT_D	3
#define GPIO_PORT_E	4
#define GPIO_PORT_F	5

/* ------------------- DIRECTOIN -------------- */
#define PIN_DIR_IN	0
#define PIN_DIR_OUT	1

/* ------------------- MODES -------------- */
#define PIN_MODE_OD	0
#define PIN_MODE_PP	1


/* ---------- FUNCTION PROTO TYPES -------------- */
void GPIO_Set_Pins_Dir(unsigned char* p_ddr, unsigned char pins,
			unsigned char direction);
void GPIO_Set_CR1(unsigned char* p_cr1, unsigned char pins,
			unsigned char val);
void GPIO_Set_CR2(unsigned char* p_cr2, unsigned char pins,
			unsigned char val);
void GPIO_Set_Pin_High(unsigned char* p_odr, unsigned char pins);
void GPIO_Set_Pin_Low(unsigned char* p_odr, unsigned char pins);
void GPIO_Toggle_Pin(unsigned char* p_odr, unsigned char pins);



#endif //end include guard
