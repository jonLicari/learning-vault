Static variables are neither stored on the [[stack]] nor the [[heap]] but rather in a separate memory region depending on whether or not they are initialized or uninitialized. This is a form of static allocation meaning memory is allocated at compile time, not at run time.

At program startup, static variables are allocated and persist for the duration of the program's execution (program scope).

**Initialized static variables** are stored in the **data segment** (or `.data` segment).

**Uninitialized static variables** (or those initialized to 0) are stored in the **Block Started by Symbol (BSS) segment** (or `.bss` segment).