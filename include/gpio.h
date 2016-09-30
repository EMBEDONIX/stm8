#ifndef GPIO_H
#define GPIO_H

/* ------------------- TYPES  ------------------- */
typedef unsigned char* 	gpio_port_t;
typedef unsigned char	gpio_pin_t;
/* ------------------- REGISTERS -------------- */
#define GPIO_OFST_ODR			0x0000
#define GPIO_OFST_IDR			0x0001
#define GPIO_OFST_DDR			0x0002
#define GPIO_OFST_CR1			0x0003
#define GPIO_OFST_CR2			0x0004

#define GPIO_PORT_A				(gpio_port_t)0x5000
// #define PA_ODR *(unsigned char*)0x5000
// #define PA_IDR *(unsigned char*)0x5001
// #define PA_DDR *(unsigned char*)0x5002
// #define PA_CR1 *(unsigned char*)0x5003
// #define PA_CR2 *(unsigned char*)0x5004

#define GPIO_PORT_B				(gpio_port_t)0x5005
// #define PB_ODR *(unsigned char*)0x5005
// #define PB_IDR *(unsigned char*)0x5006
// #define PB_DDR *(unsigned char*)0x5007
// #define PB_CR1 *(unsigned char*)0x5008
// #define PB_CR2 *(unsigned char*)0x5009

#define GPIO_PORT_C				(gpio_port_t)0x500A
// #define PC_ODR *(unsigned char*)0x500A
// #define PC_IDR *(unsigned char*)0x500B
// #define PC_DDR *(unsigned char*)0x500C
// #define PC_CR1 *(unsigned char*)0x500D
// #define PC_CR2 *(unsigned char*)0x500E

#define GPIO_PORT_D				(gpio_port_t)0x500F
// #define PD_ODR *(unsigned char*)0x500F
// #define PD_IDR *(unsigned char*)0x5010
// #define PD_DDR *(unsigned char*)0x5011
// #define PD_CR1 *(unsigned char*)0x5012
// #define PD_CR2 *(unsigned char*)0x5013

#define GPIO_PORT_E 			(gpio_port_t)0x5014
// #define PE_ODR *(unsigned char*)0x5014
// #define PE_IDR *(unsigned char*)0x5015
// #define PE_DDR *(unsigned char*)0x5016
// #define PE_CR1 *(unsigned char*)0x5017
// #define PE_CR2 *(unsigned char*)0x5018

#define GPIO_PORT_F 			(gpio_port_t)0x5019
// #define PF_ODR *(unsigned char*)0x5019
// #define PF_IDR *(unsigned char*)0x501A
// #define PF_DDR *(unsigned char*)0x501B
// #define PF_CR1 *(unsigned char*)0x501C
// #define PF_CR2 *(unsigned char*)0x501D


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

/* ------------------- DIRECTOIN -------------- */
#define PIN_DIR_IN	0
#define PIN_DIR_OUT	1

/* ------------------- MODES -------------- */
#define PIN_MODE_INPUT_FL_NO_INT	0x00
#define PIN_MODE_INPUT_FL_INT		0x01
#define PIN_MODE_INPUT_PU_NO_INT	0x02
#define PIN_MODE_INPUT_PU_INT		0x03
#define PIN_MODE_OUTPUT_OD			0x04
#define PIN_MODE_OUTPUT_OD_FAST		0x05
#define PIN_MODE_OUTPUT_PP			0x06
#define PIN_MODE_OUTPUT_PP_FAST		0x07
#define PIN_MODE_OUTPUT_TRUE_OD		0x08


/** CR1 OpenDrain Output Normal */
#define PIN_MODE_OD		0
/** CR1 PushPull Output Normal */
#define PIN_MODE_PP		1
/** CR2 OpenDrain Output FastMode */
#define PIN_MODE_ODF 	1 


/* ---------- FUNCTION PROTO TYPES -------------- */
/**
* @brief Configures the pin according to the provided mode
* @param port: The port to be configured
* @param pins: Pin(s) to be configured.
*               This can be a single pin or a group of pins.
*				For example: 
*				(GPIO_PIN_0 | GPIO_PIN_1) to configure pin 0 and 1.
* @param pin_mode: The configuration to set for pin(s).
* @retval None
*/
void GPIO_Config_Pin(gpio_port_t port, gpio_pin_t pins,
	unsigned char pin_mode);

void GPIO_Set_Pin_High(gpio_port_t port, gpio_pin_t pins);

void GPIO_Set_Pin_Low(gpio_port_t port, gpio_pin_t pins);

void GPIO_Toggle_Pin(gpio_port_t port, gpio_pin_t pins);

unsigned char GPIO_Read_Pin(gpio_port_t port, gpio_pin_t pin);

unsigned char GPIO_Read_Port(gpio_port_t port);



#endif //end include guard
