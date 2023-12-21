
## Pre-Processing

Prior to compilation, preprocessor directives get executed.

#include imports the "included" file contents into the current file.

main() is the program entry point; where the program begins execution.

Operators are essentially just functions. For example, `<<` is just a function operator.

## Compiler

[[How the Compiler Works]]

Header files do NOT get compiled - only .cpp files get compiled. Header code included in the .cpp file will be compiled during compilation. Note the difference between header file code being compiled in the .cpp file that includes it versus the header file itself being compiled.

## Linker

[[How the Linker Works]]

Compiled source files are output into object (.o) files. It is the role of the linker to link these object files into a single (.exe) file.

`#pragma once`
pragma is an instruction to the preprocessor
once states that the header file will only be included once - no duplicates in a single translation unit. This is important from when we chain include statements.

Include Paths
Angular brackets `<>` include files outside of relative directory path 