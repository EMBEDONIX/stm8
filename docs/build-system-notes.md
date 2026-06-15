# Build System Notes

The current build system is intentionally small. Each example has its own Makefile and is meant to be built from inside that example directory.

## Current Build Mechanism

Visible examples:

- `examples/blink`
- `examples/inputpooling`
- `examples/leddance`
- `examples/uart`

The GPIO based examples compile the example source together with shared files from `src` and headers from `include`.

Typical command:

```sh
cd examples/blink
make
```

Flashing is provided as a Make target:

```sh
make flash
```

The flash target uses:

```sh
stm8flash -cstlinkv2 -pstm8s003 -w bin/<example>.ihx
```

## Compiler And Tool Dependencies

The Makefiles assume:

- `sdcc`
- `make`
- POSIX shell utilities, including `mkdir -p` and `rm -rf`
- `packihx` for the UART example
- `stm8flash` for flashing
- ST-Link v2 compatible programmer for the flash command

The Makefiles use SDCC options such as:

```sh
-mstm8
-lstm8
```

## Include Paths And Shared Code

The examples use:

- `../../include` for headers
- `../../src` for shared helper implementations

Shared helpers:

- `src/gpio.c`
- `src/clock.c`
- `src/dance.c` for the LED dance example

The code uses direct register definitions, not STM8 Standard Peripheral Library project files.

## What Is Missing For A Clean Build

Before claiming a verified build, record:

- host operating system
- SDCC version
- Make version
- `packihx` version or source
- exact example command
- generated output files
- whether flashing was tested
- board and programmer used for flashing

No root Makefile exists yet. That is acceptable for the current repository, but the README should make it clear that examples are built from their own directories.

## What Should Not Be Changed Yet

Do not replace the per-example Makefiles until at least one example has been built with the existing flow.

Do not add CMake or PlatformIO as the primary build flow before the old SDCC workflow is documented and verified.

Do not remove generated Doxygen output until there is a clear documentation plan. It is generated material, but it is also part of the current repository history.

## Minimal Next Build Step

The safest first build target is `examples/blink`.

Recommended sequence:

```sh
cd examples/blink
make clean
make
```

If build succeeds, record the tool versions and generated files. Flash only when a known STM8S003F3 board and ST-Link v2 are connected.
