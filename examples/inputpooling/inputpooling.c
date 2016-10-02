#include "stm8s003.h"
#include "clock.h"
#include "gpio.h"

//button port and pin, change according to your own prefrence!
gpio_port_t buttonPort = GPIO_PORT_D;
gpio_pin_t  buttonPin = GPIO_PIN_4;

//led port and pin, change according to your own prefrence!
gpio_port_t ledPort = GPIO_PORT_D;
gpio_pin_t  ledPin = GPIO_PIN_3;

//setup GPIO
void gpio_init() {
    //set the button pin as input, pull up, no interrupt
    GPIO_Config_Pin(buttonPort, buttonPin, PIN_MODE_INPUT_PU_NO_INT);
    //set the led pin as input push pull normal (not fast)
    GPIO_Config_Pin(ledPort, ledPin, PIN_MODE_OUTPUT_PP);
}

int main() {
        //setup clock, internal RC @ 16MHz
    	CLK_Init(CLK_SRC_HSI, 0x00, 0x00);
        gpio_init();

        //main loop
        while(1) {
            //0 means button is pressed, 1 means it is not pressed!
            if(!GPIO_Read_Pin(buttonPort, buttonPin)) {
                //turn on if pressed
                GPIO_Set_Pin_High(ledPort, ledPin);
            } else {
                //turn off if released
                GPIO_Set_Pin_Low(ledPort, ledPin);
            }

            //a little bit of delay...not really necessery
            CLK_Delay_ms(10);
        }

}