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
#### GCC - Cross Platform (g++/ gpp)

This is a highly portable, open source standard for Linux/ Unix and cross-platform projects. In CLI, commands can be aliased with *g++* or *gpp*

**Advantages:**
- Highly portable, used on Linux, macOS, Windows (via MinGW/ MSYS2), and embedded systems
- Often has more robust support for the latest C++ standards and strict standard compliance
- Extremely flexible with many build options but harder to integrate as an API

#### MinGW

This is a Windows port of GCC required if you want to run GCC on a Windows machine without heavy third party tooling.
#### LLVM - clang/ clang++

LLVM is a project that is a compiler infrastructure on which actual compilers are built. The LLVM C compiler is called *clang* and the C++ compiler is called *clang++*.

**Advantages:**
- Clear, readable error messages
- Highly modular plugin / compiler extensibility 
- Fast compilation on small/ medium projects

### Identify Compiler Executables

| If you see… | It’s…              |
| ----------- | ------------------ |
| `cl`        | Microsoft compiler |
| `g++`       | GCC                |
| `clang++`   | Clang              |

### Compiler Comparison

|Category|Clang|GCC|MSVC|
|---|---|---|---|
|Primary Platforms|macOS, Linux, Windows|Linux, Windows (MinGW), others|Windows|
|Default on|macOS|Most Linux distros|Visual Studio on Windows|
|Standards Compliance|Excellent, very up-to-date|Excellent, often first to implement|Good, historically slower but much improved|
|Error Messages|Very clear and readable|Improved but can be verbose|Generally good, sometimes less detailed|
|Compile Speed|Often fast for small/medium projects|Very fast, especially optimized builds|Good, optimized for Windows projects|
|Optimization Quality|Very strong (LLVM backend)|Extremely strong, especially on Linux|Very strong for Windows targets|
|Tooling / Static Analysis|Excellent (clang-tidy, clang-format, libclang)|More limited built-in tooling|Strong IDE integration in Visual Studio|
|IDE Integration|Great with VS Code, CLion|Good in many IDEs|Best in Visual Studio|
|ABI Stability|Depends on standard library (libc++ or libstdc++)|Uses libstdc++ (stable on Linux)|Uses MSVC STL (Windows ABI standard)|
|Cross-Platform Consistency|Very consistent|Very consistent|Windows-focused|
|Windows Support|Good (clang-cl mode available)|Via MinGW (less native)|Native and best-supported|
|Diagnostics for Templates|Excellent|Good but sometimes harder to read|Improved significantly in recent versions|
|Plugin / Compiler Extensibility|Strong (LLVM infrastructure)|Mature but less modular than LLVM|Limited compared to LLVM|
|Embedded / Niche Architectures|Moderate|Excellent (many architectures supported)|Limited compared to GCC|
