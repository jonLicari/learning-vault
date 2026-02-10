# 1.0 Introduction
Assembly language is unique to a specific processor family.

This course deals with Intel x86-64 Assembly language in a Linux environment.

## 1.1 Controlling CPU using C and Assembly
All programs are compiled or interpreted into machine code.

Assembly has many commands which directly correspond to machine code but they are still different things.

__Advantages of Assembly:__
- Speed
    - properly coded assembly can run a command as fast as is possible for a given system
    - Translating a program into assembly is done by the compiler
    - Compiler optimizations seek to translate the developer's code into the most efficient assembly possible
- Tight 
    - No overhead or translation involved from a compiler

__Disadvantages of Assembly:__
- Slow Development Time
- Difficult Debugging

The _asm_ keyword is used by many compilers to denote assembly code within a C program.

C code can also be written into an assembly program.

Object (.o) files from assembly and C programs can be linked together.

## 1.2 Assembly Language
Source code is divided into sections:
1. .data for initialized data
2. .bss for uninitialized data or storage
3. .text for coding instructions
4. _start: is similar to main; it is a global function which designates the start of the program

Each Assembly instruction set will manipulate data in registers. 

The register maps will be hardware dependent and vary per processor family.

__Common Operators:__
- mov 
    - moves data from origin register to destination register
- sub
    - subtracts data from one register from another
- jmp
    - jumps to a branch of code (similar to function call)
- cmp
    - compare the values of two registers together

## 1.3 Building Assembly
1. Write source code
    - can be written in editor of choice
2. Assemble program
    - analogous to compiling C code in that the result is an object (.o) file
3. Link
    - same as in C, files are linked to form a program but in assembly, there are no libraries linked in - whatever is in the assembly source code is the entire program

__Use Command Line to Assemble:__
```
01_03$ nasm -f elf64 01_03-goodbye.asm
``` 
- **nasm** assembler program (clang, nasm, etc.)
- **-f** specify output file format
- **elf64** executable and linkable format of 64 bit width
- **01_03-goodbye.asm** source code file name

Linking files is a separate process from assembling.

This is unlike C, where the compilation process both assembles and links program files.

__Use Command Line to Link:__
```
01_03$ ld 01_03-goodbye.o -o goodbye
```
- **ld** name of linker in the Unix environment
- **01_03-goodbye.o** recently created object file
- **-o** sets the output file name
- **goodbye** output file name

Run the program:
```
01_03$ ./goodbye
```

# 2.0 The Assembly Side of C
## 2.1 Viewing C as Assembly
When the two implementations of the Hello World program are compared, the C code was about 9x larger than the Assembly code even though they are doing the exact same thing.

The disassembled C program features a larger number of instructions than the Assembly program.

For certain functions, since you know exactly what you intend to perform, you can write Assembly code that is tighter than the compiler optimized C code.

This is the advantage of using inline Assembly or linking an Assembly language object code module.

## 2.2 Choosing C or Assembly
The most effective use of these languages is to use them in tandem with each other.

The advantage is to know which parts of your C program need optimization achieved through assembly.

__Finding Bottlenecks in C Code:__
- use an optimization utility like *valgrind*
- these utilties find areas of your code which may have inefficiencies
- help pinpoint where in the C code it is best to use assembly

Assembly modules can be linked to C program.

For smaller functionalities, *asm* can be used to insert a cheeky inline assembly code.

Note that the opposite is prohibited; C cannot be written inline in assembly source code.

Code written in assembly is tighter than C code because the developer can program exactly what they want without overhead for interfacing with C library functions.
C must add extra code to interface with C library functions.

## 2.3 Challenge: Link Multiple Modules into One Program

# 3.0 C and Assembly Integration
## 3.1 Adding Assembly to C
A C code object file can be linked with an assembly code object file.

Ensure functions are called correctly and scope of variables/ functions are compatible for integration.

An assembly module can contain functions to be used in a C program.

Simply add the function prototype in the C file as you would do from a header file.

## 3.2 Adding C to Assembly
Using instruction "call", a C language function can be called from the assembly file.

Assemble source code into object files and link the same as before.

Ensure that C library functions are executed in the C source code rather than assembly to minimize complexity with passing of arguments and register manipulation.

## 3.3 Inline Assembly
Assembly code can be written within a C source file.

This removes the need to link separate modules.

Use the *asm* keyword to add strings of assembly code directly into your C file.

```C
#include <stdio.h>
// variables that are used by inline assembly must be global or external
int total;

int main() {
    int x;

    total = 1;

    for(x=0; x<10; x++) {
        printf("%d/n", total);
        asm(
            ".intel_syntax noprefix;"
            "mov rax, total;"
            "imul rax, 2;"
            "mov total, rax;"
        );
    }
} 
```
Note:
- Assembly statement strings must end with a semicolon
- *asm* keyword is not standard amongst C compilers and is actually a deprecated legacy keyword
- Only the C compiler is required to compile, assemble, and link the final program
- Assembly statements must be enclosed in double quotations

Q: What change is needed in assembly code if the main module is linked by 'clang' and not 'ld'?
A: The code's entry point must be named "main"

Q: What must be done to call an assembly function from C source code?
A: 
- function must be prototyped in the C source file
- function must be either global or external

# 4.0 Assembly Functions for C
## 4.1 Passing Arguments in Assembly
Never assume that C functions preserve register data.

## 4.2 Returning a Value in Assembly
