# Project History

This repository is part of the older Embedonix STM8 tutorial work. The related articles began around 2015, and the Git history in this repository starts in 2016.

The goal was practical: make STM8S development easier to approach with small examples, SDCC, Makefiles, and direct register access. At the time, STM8 parts were cheap, capable enough for many small jobs, and useful for learning microcontroller fundamentals without a large framework in the way.

STM8 was not always friendly to beginners. Tooling existed, but clear examples for Linux, SDCC, flashing, GPIO, and UART were harder to find than they were for Arduino or larger STM32 parts. That is why simple examples such as blinking an LED, reading a button, and sending text over UART had value.

The repository stayed mostly unchanged for years because the examples were small and tied to a specific teaching period. The embedded world also moved heavily toward ARM Cortex-M parts, STM32, Arduino style boards, and higher level tooling.

The current revival is meant to preserve the project and make it easier to use again. The plan is to improve documentation, record build status honestly, explain toolchain assumptions, and clean up example notes where they help.

This revival is not meant to turn the code into a large HAL or framework. The examples should remain small C programs that show the registers, pins, clock setup, and basic peripheral behavior clearly.

Planned maintenance:

- document the existing examples
- verify the SDCC build flow
- record what was tested and what was not
- keep historical links to Embedonix articles and videos
- make small fixes only when the behavior is understood

Out of scope for now:

- rewriting the project around CMake
- replacing the examples with a full abstraction layer
- claiming support for untested boards or toolchains
- adding new peripherals before the existing examples are understood
