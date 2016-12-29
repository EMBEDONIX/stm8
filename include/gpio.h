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

#define GPIO_PORT_A			(gpio_port_t)0x5000

#define GPIO_PORT_B			(gpio_port_t)0x5005

#define GPIO_PORT_C			(gpio_port_t)0x500A

#define GPIO_PORT_D			(gpio_port_t)0x500F

#define GPIO_PORT_E 			(gpio_port_t)0x5014

#define GPIO_PORT_F 			(gpio_port_t)0x5019

/* ------------------- PINS ------------------- */
#define GPIO_PIN_0		1
#define GPIO_PIN_1		2
#define GPIO_PIN_2		4
#define GPIO_PIN_3		8
#define GPIO_PIN_4		16
#define GPIO_PIN_5		32
#define GPIO_PIN_6		64
#define GPIO_PIN_7		128
#define GPIO_PIN_ALL		255

/* ------------------- DIRECTOIN -------------- */
#define PIN_DIR_IN	0
#define PIN_DIR_OUT	1

/* ------------------- MODES -------------- */
#define PIN_MODE_INPUT_FL_NO_INT	0x00
#define PIN_MODE_INPUT_FL_INT		0x01
#define PIN_MODE_INPUT_PU_NO_INT	0x02
#define PIN_MODE_INPUT_PU_INT		0x03
#define PIN_MODE_OUTPUT_OD		0x04
#define PIN_MODE_OUTPUT_OD_FAST		0x05
#define PIN_MODE_OUTPUT_PP		0x06
#define PIN_MODE_OUTPUT_PP_FAST		0x07
#define PIN_MODE_OUTPUT_TRUE_OD		0x08


/** CR1 OpenDrain Output Normal */
#define PIN_MODE_OD			0
/** CR1 PushPull Output Normal */
#define PIN_MODE_PP			1
/** CR2 OpenDrain Output FastMode */
#define PIN_MODE_ODF 			1


/* ---------- FUNCTION PROTO TYPES -------------- */
/**
* @brief Configures the pin according to the provided mode.
* @param port: The port to be configured.
* @param pins: Pin(s) to be configured.
*               This can be a single pin or a group of pins.
*		For example:
*		(GPIO_PIN_0 | GPIO_PIN_1) to configure pin 0 and 1.
* @param pin_mode: The configuration to set for pin(s).
* @retval None
*/
void GPIO_Config_Pin(gpio_port_t port, gpio_pin_t pins,
	unsigned char pin_mode);

/**
* @brief Set pin(s) to output high.
* @param port: The port to be configured.
* @param pins: Pin(s) to be configured.
*               This can be a single pin or a group of pins.
*		For example:
*		(GPIO_PIN_0 | GPIO_PIN_1) to act on pin 0 and 1.
* @retval None
*/
void GPIO_Set_Pin_High(gpio_port_t port, gpio_pin_t pins);

/**
* @brief Set pin(s) to output low.
* @param port: The port to be configured.
* @param pins: Pin(s) to be configured.
*               This can be a single pin or a group of pins.
*		For example:
*		(GPIO_PIN_0 | GPIO_PIN_1) to act on pin 0 and 1.
* @retval None
*/
void GPIO_Set_Pin_Low(gpio_port_t port, gpio_pin_t pins);

/**
* @brief Reverses the pin(s) output level.
* @param port: The port to be configured
* @param pins: Pin(s) to be configured.
*               This can be a single pin or a group of pins.
*		For example:
*		(GPIO_PIN_0 | GPIO_PIN_1) to act on pin 0 and 1.
* @retval None
*/
void GPIO_Toggle_Pin(gpio_port_t port, gpio_pin_t pins);

/**
* @brief Read pin(s) input level.
* @param port: The port to be read.
* @param pins: Pin(s) to be configured.
*               This can be a single pin or a group of pins.
*		For example:
*		(GPIO_PIN_0 | GPIO_PIN_1) to configure pin 0 and 1.
* @retval The current input state of the input (1 = high, 0 = low).
*/
unsigned char GPIO_Read_Pin(gpio_port_t port, gpio_pin_t pin);

/**
* @brief Read entire input state of pins of a port.
* @param port: The port to be read.
* @retval Binary representation of input state of the pins of the port.
*/
unsigned char GPIO_Read_Port(gpio_port_t port);



#endif //end include guard
