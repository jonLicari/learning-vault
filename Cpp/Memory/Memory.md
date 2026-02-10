Volatile
Non-Volatile
[[Heap]]
[[Stack]]
[[RAII]]
Static vs Dynamic Allocation
[[Static Variables]]
Debugging Memory Errors

## Embedded Memory Layout

| Section | Location                          | Purpose                                                     |
| ------- | --------------------------------- | ----------------------------------------------------------- |
| `.text` | Flash                             | Contains program code (functions, constants)                |
| `.data` | RAM (copied from flash)           | Initialized global/ static variables                        |
| `.bss`  | RAM                               | Zero-initialized global/ static variables                   |
| stack   | RAM                               | Function call/ return, local statically allocated variables |
| heap    | RAM                               | Dynamically allocated memory                                |
| MMIO    | Reserved peripheral address space | Direct hardware access                                      |
`.text` 
- Stores compiled code and read-only data
- Located in Flash
`.data`
- Stores **initialized** global/ static variables
- Copied from Flash to RAM at program startup
```c
  int counter = 10; // stores in .data
```

`.bss`
- Stores **zero-initialized** and **uninitialized globals/ static** variables
- Allocated in RAM, automatically zeroed at program startup
```c
static int error_count; // goes in .bss
```

These memory regions are defined by the [[linker]] script (`.ld` file) and startup code (usually in `startup.s` or `crt0`) that copies `.data` and zeroes the `.bss`
## Stack vs Heap in Embedded

[[Stack]]
- Used for statically allocated data
```C
int array[255]; // stores in stack region of RAM
```

[[Heap]]
- Used for dynamically allocated data


## Flash vs RAM in Embedded

| Aspect       | Flash                      | RAM         |
| ------------ | -------------------------- | ----------- |
| Volatility   | Non-volatile               | Volatile    |
| Usage        | Program storage, constants | Stack, Heap |
| Size         | Larger                     | Smaller     |
| Access Speed | Faster                     | Slower      |

Examples:
```C
const uint8_t table[4] = {1,2,3,4}; // const stores in flash (.text region)
uint8_t buffer[16]; // statically allocated array stores in RAM (.data, .bss)
```

## Memory Errors

- Stack overflows
- Crashes from accessing uninitialized memory
- Unexpected behaviour in ISRs or shared buffers
- Hardfaults
- Memory out of bound errors
- Memory fragmentation

Knowing the memory layout can help:
- find stack overflows (watch stack pointer in debugger)
- prevent overlap of stack and heap
- identify where faults are occurring and what source code they are occurring in