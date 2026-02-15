[Cherno Introduction to Compilers](https://www.youtube.com/watch?v=3tIqpEmWMLI&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=6&pp=iAQB)

Header files do NOT get compiled - only .cpp files get compiled. Header code included in the .cpp file will be compiled during compilation. Note the difference between header file code being compiled in the .cpp file that includes it versus the header file itself being compiled.

## What's The Difference?

Lots of different compilers exist for C/ C++:
- MSVC (Microsoft Visual C/C++)
- GCC (Gnu Compiler Collection)
- LLVM (clang/ clang++)

#### MSVC - Microsoft Compiler

This is Microsoft's compiler is the optimized, default choice for Windows development (deeply integrated with Visual Studio). The executable is *ms-cl*.

**Advantages:**
- Windows-native applications
- Game development
- Developers using Visual Studio (seamless integration with VS IDE, debugger, and Windows SDKs)
- Highly optimized for Intel & AMD processors on Windows
#### GCC - Cross Platform

This is a highly portable, open source standard for Linux/ Unix and cross-platform projects. In CLI, commands can be aliased with *g++* or *gpp*

**Advantages:**
- Highly portable, used on Linux, macOS, Windows (via MinGW/ MSYS2), and embedded systems
- Often has more robust support for the latest C++ standards and strict standard compliance
- Extremely flexible with many build options but harder to integrate as an API

### MinGW

This is a Windows port of GCC
### LLVM - clang/ clang++

LLVM is a project that is a compiler infrastructure on which actual compilers are built. The LLVM C compiler is called *clang* and the C++ compiler is called *clang++*.

**Advantages:**
- 