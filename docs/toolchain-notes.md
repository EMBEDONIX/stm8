# STM8 Toolchain Notes

This repository currently shows an SDCC based workflow. Other STM8 toolchains are mentioned here for context, but they should not be treated as supported unless project files or test results are added later.

## SDCC

SDCC is the toolchain used by the current Makefiles. The examples pass `-mstm8` and link against the STM8 support library with `-lstm8`.

Why use it:

- open source
- works well with simple C examples
- fits the original Linux focused Embedonix STM8 workflow
- keeps the build system small

Limitations:

- the existing Makefiles assume POSIX shell commands
- delay loops may depend on compiler output and clock setup
- no recent build has been recorded in this revival pass
- generated files are not checked in, so each example needs a local build

Current repository support:

- SDCC is the only visible compiler flow in the repository.
- `examples/uart/Makefile` also calls `packihx`.
- Flashing uses `stm8flash -cstlinkv2 -pstm8s003`.

Still needs testing:

- SDCC version
- GNU Make or compatible make version
- `packihx` availability
- `stm8flash` version
- build and flash results for each example

## STVD, ST Visual Develop

STVD was the classic Windows IDE used for STM8 development with ST tools and third party compilers.

Why someone might use it:

- legacy STM8 projects often used it
- useful for older Windows based maintenance work
- familiar to teams that already have STVD projects

Limitations:

- Windows focused
- legacy tooling
- no STVD project files are currently present in this repository

Current repository support:

- not currently supported by visible project files

Still needs testing:

- whether any example can be imported cleanly
- include paths and linker setup
- compiler choice inside STVD

## Cosmic Compiler

Cosmic C is a commercial compiler historically used for STM8.

Why someone might use it:

- existing products may already use it
- strong historical STM8 support
- useful for comparing old project behavior

Limitations:

- commercial tooling
- different compiler options and project setup from SDCC
- no Cosmic project files are currently present in this repository

Current repository support:

- not currently supported by visible project files

Still needs testing:

- compile compatibility
- required startup and linker files
- project setup instructions

## PlatformIO

PlatformIO can be useful as a modern workflow wrapper for embedded projects, but this repository does not currently include a `platformio.ini`.

Why someone might use it:

- easier dependency and environment setup
- editor integration
- repeatable command line builds

Limitations:

- not part of the original project
- may hide some of the simple Makefile flow
- STM8 support and board definitions must be checked before claiming support

Current repository support:

- not currently supported

Still needs testing:

- whether STM8S003F3 builds work with the current code
- board and upload configuration
- whether it adds value without changing the character of the project
