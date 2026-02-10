- Compiler directive that identifies the associated data as being modifiable outside of the program's control and thus that it must not assume that the data stays the same value between accesses and prohibits compiler optimization as a result

- Used for data that can be accessed and modified from outside of the program's control, such as hardware registers (UART, timers), peripherals (DMA), ISRs, etc.

- Behaviour:
	- **Reads**: Every time the volatile data is read, a `load` operation from the actual memory location is performed (no caching)
	- **Writes**: Compiler emits a `store` operation for every volatile write (cannot merge or remove volatile writes)
	- **Note**: Volatile does **NOT** guarantee [[Atomic|atomicity]], synchronization, or thread safety

In summary, the key difference is that atomic variables are explicitly designed for synchronized and atomic access in multithreaded scenarios, while volatile variables are primarily concerned with preventing compiler optimizations and are often used in low-level programming contexts such as embedded systems and hardware I/O registers. When working with multithreaded code, if your goal is to ensure atomic access, synchronization, and thread safety, you would typically use atomic variables or appropriate synchronization mechanisms like locks, semaphores, or mutexes. Volatile variables, on the other hand, are not typically used to achieve atomicity or synchronization in multithreaded programming.