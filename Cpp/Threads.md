## RTOS Threads
Yes, Mbed OS threads, managed by the [[Mbed OS]] RTOS, are different from POSIX threads (pthreads) used in traditional desktop or server-based operating systems. Here are some key differences:

1. Embedded vs. General-Purpose Systems: Mbed OS is designed for embedded systems, which have different requirements and constraints compared to general-purpose desktop or server systems. Mbed OS threads are optimized for embedded and real-time applications, offering features like priority-based scheduling and resource-constrained management.

2. Abstraction and Portability: Mbed OS provides a high-level, portable abstraction for working with threads, timers, and synchronization primitives. This abstraction shields developers from the underlying hardware and RTOS details, making it easier to write code that can run on various embedded platforms.

3. Real-Time Features: Mbed OS threads are designed to meet real-time requirements, ensuring predictable and deterministic behaviour. Developers can set thread priorities to manage task scheduling based on their specific real-time requirements.

4. Resource Efficiency: Mbed OS threads are designed to be lightweight, which is crucial in resource-constrained embedded systems. They use a minimal amount of memory and other system resources.

5. Integration with Mbed OS Ecosystem: Mbed OS threads are part of the broader Mbed OS ecosystem, which includes libraries, middleware, and tools specifically tailored for developing embedded systems.

On the other hand, pthreads are a standard threading library in POSIX-compliant operating systems, and they are used for general-purpose multi-threading on desktop and server systems. Pthreads provide a more traditional and lower-level interface to manage threads and synchronization, and they are not as optimized for the constraints and requirements of embedded systems.

In summary, Mbed OS threads are designed for embedded and real-time systems, offer a higher-level abstraction, and are part of the Mbed OS ecosystem, while pthreads are a standard library for general-purpose multi-threading on POSIX systems. The choice of threading mechanism depends on the specific application and the platform on which it will run.

In the context of multithreading and thread management, there are differences between calling `break`, `join`, and `terminate` within a thread, and they serve distinct purposes:

1. `break`:

   - `break` is not a standard function or method in most threading libraries or frameworks, including Mbed OS. It's typically used in control flow constructs like loops or switch statements to exit the loop or switch statement prematurely.

   - When you call `break` within a thread, you're essentially breaking out of a loop or some control structure within that thread's execution. It doesn't directly terminate the thread itself; it only exits the specific loop or block where `break` is used.

   - This means that the thread may continue executing other parts of its code or perform any cleanup actions before it naturally exits.

2. `join`:

   - The `join` method is used to wait for a specific thread to finish its execution. It is a way for one thread to block and wait until another thread has completed its work.

   - When you call `join` from a thread on another thread, it essentially waits for the target thread to finish its execution. This is useful for synchronization, where you want to ensure that a specific thread has completed its work before continuing with the current thread.

   - `join` is typically used to wait for a specific thread to finish its task, and it's a way to coordinate and synchronize between threads.

3. `terminate`:

   - `terminate` is used to forcefully terminate a thread's execution. This is a mechanism to abruptly stop a thread, and it's generally discouraged because it can lead to resource leaks, inconsistent program state, and undefined behavior.

   - In many threading libraries, including Mbed OS, there is no built-in `terminate` function because it's considered a dangerous operation.

In summary, `break` is used for control flow within a thread, `join` is used for synchronization between threads, and `terminate` (if supported) is a risky way to forcibly stop a thread. The choice of which to use depends on the specific requirements and design of your multithreaded application. In general, it's better to design your threads to naturally exit when their work is done, using mechanisms like flags or synchronization primitives for coordination.


I was trying to use threads to solve the issue where attempting to read/ write to the tmc drivers when they were disabled caused the thread to hang indefinitely.

## First Exercise 
Prove that a thread can be terminated after an amount of time:
```cpp
#include <mbed.h>

void hardwareThreadFn() {
	auto led = DigitalOut(PA_5, 1);
	Timer threadTimer;
	const int maxExecTime = 5; // seconds
	
	threadTimer.start();
	
	while(1) {
		// thread work
		led = !led;
		logln("LED: %d", led.read());
		
		// Check if the timer has exceeded the limit
		if (threadTimer.read() >= maxExecTime) {
			logln("--- FINISHED ---");
			break;
		}
		ThisThread::sleep_for(500);
	}
}

int main() {
	...
	
	rtos::Thread t_hardware; 
	t_hardware.start(callback(hardwareThreadFn));
	t_hardware.join();
	
	...
}
```

Output:
```
(Info) --- Gantry Initialized
(Debug) LED: 0
(Debug) LED: 1
(Debug) LED: 0
(Debug) LED: 1
(Debug) LED: 0
(Debug) LED: 1
(Debug) LED: 0
(Debug) LED: 1
(Debug) LED: 0
(Debug) LED: 1
(Debug) LED: 0
(Debug) --- FINISHED ---
```

## Second Exercise
Prove that one thread dedicated to time management can terminate another thread dedicated to hardware operation:

If you want to use a semaphore to control the execution of the hardware thread, you can use the semaphore to synchronize the timekeeping thread and the hardware thread. Here's how you can modify the example to use a semaphore:

```cpp
#include "mbed.h"

Thread timekeeping_thread;
Thread hardware_thread;
Timer timekeeping_timer;
const int maxExecutionTime = 10;  // Maximum execution time in seconds
volatile bool terminate = false;  // Semaphore to control execution

void timekeeping_function() {
    timekeeping_timer.start();
    while (1) {
        if (timekeeping_timer.read() >= maxExecutionTime) {
            // Time limit exceeded, release the semaphore
            executeSemaphore.release();
            break;
        }
        ThisThread::sleep_for(1000);  // Sleep for 1 second
    }
}

void hardware_function() {
    // Your hardware thread's work here
    while (true) {
        // Wait for the semaphore to be available (released)
        executeSemaphore.acquire();
        if (!executeSemaphore.available()) {
            break;  // The time limit has been reached, exit the thread
        }
        // Continue with hardware operations
    }
}

int main() {
    timekeeping_thread.start(callback(timekeeping_function));
    hardware_thread.start(callback(hardware_function));

    // Wait for the hardware thread to finish naturally
    hardware_thread.join();

    while (1) {
        // Your main thread's work here
    }
}
```

In this modified example, the `executeSemaphore` is used to control the execution of the hardware thread. The timekeeping thread releases the semaphore when the time limit is exceeded, allowing the hardware thread to acquire the semaphore and continue its execution. When the semaphore is not available (not released), it means the time limit has been reached, and the hardware thread exits gracefully.

This approach ensures proper synchronization between the timekeeping thread and the hardware thread while avoiding the use of `terminate()`.

## [[Atomic]] vs [[Volatile (keyword)]] 

Atomic variables and volatile variables serve different purposes in multithreaded programming, and they are not interchangeable. Here's an explanation of their differences:

1. **Atomic Variable:**

   - An atomic variable is a variable that is designed to be accessed and modified by multiple threads concurrently while ensuring that operations on the variable are atomic (indivisible).

   - Atomic variables are often used to prevent data races and ensure safe access and modification of shared variables in multithreaded environments.

   - Atomic variables are typically used in cases where multiple threads need to perform operations on a shared variable without causing conflicts or inconsistencies.

   - Atomic variables are defined by specific data types or classes provided by threading libraries or languages. Common examples include `std::atomic` in C++ or `AtomicInteger` in Java.

   - Atomic operations include operations like compare-and-swap, increment, and load/store operations, which are guaranteed to be atomic and thread-safe.

2. **Volatile Variable:**

   - A volatile variable is a variable that informs the compiler that its value may change at any time (e.g., by hardware, or by other threads), and it should not optimize or cache its value.

   - Volatile is mainly a hint to the compiler, and it doesn't provide atomicity or synchronization. It's primarily used for variables that are accessed by multiple threads or by hardware, but it doesn't provide any specific guarantees about thread safety.

   - In many languages, including C and C++, `volatile` is often used for memory-mapped hardware registers and for variables accessed in signal handlers or other asynchronous contexts.

   - The `volatile` keyword does not guarantee atomicity, mutual exclusion, or a memory barrier; it's primarily concerned with preventing the compiler from optimizing away reads and writes to the variable.

In summary, the key difference is that atomic variables are explicitly designed for synchronized and atomic access in multithreaded scenarios, while volatile variables are primarily concerned with preventing compiler optimizations and are often used in low-level programming contexts such as embedded systems and hardware I/O registers. When working with multithreaded code, if your goal is to ensure atomic access, synchronization, and thread safety, you would typically use atomic variables or appropriate synchronization mechanisms like locks, semaphores, or mutexes. Volatile variables, on the other hand, are not typically used to achieve atomicity or synchronization in multithreaded programming.