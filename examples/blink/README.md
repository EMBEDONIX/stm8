# Blink Example

This is the simplest example in the repository. It configures one GPIO pin as an output and toggles it with delay loops.

## What It Demonstrates

- STM8S003 GPIO output
- clock setup through the shared clock helper
- a simple busy wait delay
- building one example with SDCC and the local Makefile

## Board Assumptions

The example assumes an STM8S003F3 style target and one LED connected to PD3. The active LED state depends on the board wiring.

## Pins Used

| Signal | STM8 pin |
| --- | --- |
| LED | PD3 |

PD3 is configured as push pull output with `PIN_MODE_OUTPUT_PP`.

## Toolchain Assumptions

The Makefile assumes SDCC and POSIX style shell commands.

Build from this folder:

```sh
make
```

Flash with the existing target:

```sh
make flash
```

The flash target assumes `stm8flash`, ST-Link v2, and an STM8S003 target.

## Expected Behavior

The firmware toggles the LED on PD3 repeatedly. The delays are 1000 ms, 500 ms, and 250 ms in sequence, based on the current delay helper implementation.

## Known Limitations

- This example has not been recently rebuilt or flashed as part of the revival.
- Delay timing depends on clock setup and compiler output.
- The Makefile is written for the original SDCC workflow.
- The example uses the shared `include/stm8s003.h`, `include/gpio.h`, and `include/clock.h` files.
