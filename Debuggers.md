Key debuggers include:
- GDB (GNU debugger)
- LLDB
- Integrated debuggers within IDEs (Visual Studio, STM32 Cube IDE)

### Common Debuggers

The choice of debugger often depends on the operating system and development environment: 

- **GDB (GNU Debugger)**: A powerful, command-line debugger widely used on Linux and macOS, and available on Windows via environments like Cygwin or MinGW. It's the standard for the GNU toolchain.
- **LLDB**: Part of the LLVM project, known for its modern design and flexibility. It is the default debugger on macOS within Xcode and is often paired with the Clang compiler.
- **Visual Studio Debugger**: The integrated debugger in Microsoft Visual Studio is highly regarded for its robust features and user-friendly interface on Windows. It offers advanced options like C++ dynamic debugging for optimized code.
- _**rr**_ **(Record and Replay)**: A unique tool for Linux that records the execution of a program, allowing for "reverse debugging" (stepping backward in time).

### Configuration and Options

- **Symbols**: Debuggers rely on debugging symbols (e.g., PDB files on Windows, DWARF on Linux/macOS) to associate machine code with your source code. You must enable the generation of debug information during compilation and linking (e.g., using the `/DEBUG` linker flag in Visual Studio or `-g` compiler flag in GCC) and disable code optimization.
- **Remote Debugging**: Most debuggers support debugging a process running on a different machine or an embedded system via a network connection.
- **Attach to Process**: Instead of launching a program through the debugger, you can attach the debugger to an already running process.
- **Configuration Files**: IDEs like Visual Studio Code use configuration files (e.g., `launch.json`) to specify the program path, command-line arguments, environment variables, and debugger setting