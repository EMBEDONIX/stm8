
<img src="resources/embedonix.jpg" width=64 height=64 align="right" />


# STM8S Example Projects With [SDCC](http://sdcc.sourceforge.net/)
This repository is a collection of simple projects for STM8S003F3 to help you get started with this series of small, cheap but capable MCU's.


<img src="resources/board.jpg" width=192 height=192 align="right" />


# Hardware
The examples in this repository are tested with a generic STM8S003F3P6 in TSSOP20 package. There is no reason they do not work on other packages.

For compatibility with other STM8X (e.g. L) series of MCU's make sure the registers in the "include/stm8s.h" are compatible with your own MCU. Just make a copy of this file and apply changes according to the datasheet of the chip you have at hand.

For tutorial on programming these examples on your MCU, please check the [guide to flashing stm8 on linux](http://embedonix.com/articles/linux/setting-up-development-and-programming-for-stm8-on-linux/).


# Folders Structure

- **examples**  Contains examples

| File Name     |      Description      |
|---------------|:---------------------:|
| ***blink***        |   Blinks an  LED |
| ***inputpooling*** |   Reads a pin configured as input and reacts by turning a LED on/off  |   
| ***leddance***     | Uses the implemented dance routins to make appealing LED dancing      |   
|***uart***          |A simple UART communication example that prints characters to serial   |

- **include** Header files which contain constants, types and function declarations
- **include** Used for store git repository, not important for users
- **src** Contains function definitions


# How to use?

Just go inside the 'examples' folder and see the source code for each example. Use the Make file to compile and flash the example on your own chip.

# What's coming next?

This is an ongoing project. I will try to add more examples, e.g. Timers, interruprs, SPI and I2C.

# What can you do?

If you have nice examples and projects, please contribiute to this repository.

# Donations

Your donations will make further development much faster! If you are interested to donate to EMBEDONIX (any amount even 1$ is welcome!) please visit [EMBEDONIX.COM](http://www.embedonix.com) and click on the paypal donate button!
