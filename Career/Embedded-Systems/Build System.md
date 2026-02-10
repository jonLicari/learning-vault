
## 1. Pre-Processing

Prior to compilation, preprocessor directives get executed.
- Macros get expanded
- `#include` imports the "included" file contents into the current file.
- `#pragma once` - states that the header file will only be included once in a single translation unit. This is important from when we chain include statements
- Include Paths: 
	- Angular brackets `<>` include files outside of relative directory path 
	- Quotation marks `""` include files 
- Operators are essentially just functions. For example, `<<` is just a function operator.
- **Output**: single preprocessed file (`.i` for C, `.ii` for C++)

## 2. [[Compiler| Compilation]]

How the [[Compiler]] Works

- Header files do **NOT** get compiled - only `.cpp` files get compiled. 
- Header code included in the `.cpp` file will be compiled during compilation
- Note the difference between header file code being compiled in the `.cpp` file that includes it versus the header file itself being compiled
- Translates preprocessed code to assembly
- Compiler performs optimizations if specified
- **Output**: assembly source file (`.s`)

## 3. Assembler 
- Note: Assembly refers to the code language, assembler is the utility program that translates the assembly code into machine code
- Converts assembly to machine-readable object code
- **Output**: object files (`.o`)

## 4. [[Linker| Linking]]

How the [[Linker]] Works

- Linker links object files, resolves symbols
- Applies memory layout via linker script (`.ld` file)
- **Output**: Executable and Linkable Format (`.elf`) file


## 5. Binary Generation
- Converts ELF to binary and/ or Intel Hex for flashing
- **Output**: Binary (`.bin`), Hex (`.hex`) file

## 6. Flashing

- Using JTAG/ SWD/ UART to upload to microcontroller
- Programmer hardware is used to write the data to the device's flash memory 

