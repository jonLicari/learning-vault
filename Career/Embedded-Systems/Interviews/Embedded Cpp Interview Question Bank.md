Below is a **high-quality Embedded Systems C/C++ interview question bank** that reflects what FAANG-adjacent embedded teams, automotive, aerospace, medical device companies, and firmware-focused startups actually ask.

I’ve grouped questions by **difficulty** and **topic**, including **C++ for MCUs**, **bit-level reasoning**, **memory constraints**, **RTOS**, **hardware**, and **debugging**.

Below are **fully structured embedded systems interview packs** for **Junior, Mid-Level, Senior, and Principal** embedded engineers. Each level includes:

✅ **Conceptual questions**  
✅ **Hardware/RTOS questions**  
✅ **C/C++ low-level questions**  
✅ **Coding challenges**  
✅ **Debugging exercises**  
✅ **One take-home assignment**

This is exactly the structure used by real embedded teams (medical, automotive, defense, consumer electronics, robotics):
- [[Junior Level Embedded Interview Bank|Junior Level]]
- [[Mid Level Embedded Interview Bank|Mid-Level]]
- [[Senior Level Embedded Question Bank|Senior]]
- [[Principal Level Embedded Interview Bank|Principal]]

---

# 🟦 **SECTION 1 — Essential C/C++ for Embedded (Fundamentals)**

### **C / Low-level**

1. What is the difference between `volatile` and `const volatile`?
    
2. Explain the difference between **stack**, **heap**, and **static** memory.
    
3. What happens during the startup/reset sequence of a microcontroller before `main()` runs?
    
4. Why is `volatile` required for memory-mapped registers?
    
5. What is a “memory barrier/fence”?
    
6. What's the difference between **struct padding** and **struct packing**?
    
7. Explain **undefined behavior** in C. Give examples that often appear in firmware.
    
8. What is the difference between `uint8_t`, `unsigned char`, `BYTE`, `size_t`?
    
9. How does integer promotion work on an 8-bit MCU?
    
10. What is a “strict aliasing violation”?
    

### **C++ (embedded-safe usage)**

1. Can you use `new` and `delete` in embedded systems? Why or why not?
    
2. Explain RAII and why it’s _helpful_ in embedded systems.
    
3. Which STL components are safe for embedded? Which are not?
    
4. What is a “zero-cost abstraction”? Give an embedded C++ example.
    
5. Difference between:
    
    - `const int*`
        
    - `int* const`
        
    - `const int* const`
        
6. What does the linker do with a `static` member variable in a class?
    
7. Explain the “rule of 3 / 5 / 0”.
    
8. Explain virtual function overhead (memory + runtime cost).
    
9. What’s the layout of a class with virtual functions in memory?
    
10. What is the cost of exceptions on embedded targets? Why are they often disabled?
    

---

# 🟦 **SECTION 2 — Bit Manipulation, Registers, and Embedded Logic**

### **Registers & Hardware Access**

1. How do you write to a memory-mapped register using C?
    
2. What is the difference between:
    
    ```cpp
    #define REG (*(volatile uint32_t*)0x40021000)
    ```
    
    and
    
    ```cpp
    volatile uint32_t &REG = *(uint32_t*)0x40021000;
    ```
    
3. Explain atomicity for 8-, 16-, and 32-bit operations on various architectures.
    
4. What is a critical section?
    
5. Why does reading a GPIO register sometimes require a dummy read?
    

### **Bit-level practice**

1. Reverse the bits of a byte.
    
2. Count the number of 1 bits in an integer.
    
3. Check if an integer is a power of two.
    
4. Set/clear/toggle/read a specific bit in a register.
    
5. Extract fields from a packed 32-bit status register.
    
6. Combine multiple bitfields into a 32-bit value.
    
7. Implement a ring buffer (head/tail pointer logic).
    

---

# 🟦 **SECTION 3 — RTOS and Concurrency**

### **RTOS Concepts**

1. Explain the difference between:
    
    - preemptive scheduling
        
    - cooperative scheduling
        
2. What is priority inversion?
    
3. How does a mutex differ from a binary semaphore?
    
4. Explain the difference between:
    
    - task
        
    - ISR
        
    - deferred interrupt handler
        
5. What is a race condition? Give a real embedded example.
    
6. What is a “tick”? How does SysTick work?
    
7. How does context switching work?
    
8. What is stack overflow in RTOS tasks and how to detect it?
    

### **FreeRTOS-specific**

1. What is a queue?
    
2. What is `taskYIELD`?
    
3. What happens when you call a blocking RTOS function from an ISR?
    
4. Why must interrupt-safe queue APIs end with `FromISR`?
    

---

# 🟦 **SECTION 4 — MCU Architecture, Peripherals, and Timing**

### **Hardware Basics**

1. What is an interrupt vector table?
    
2. How does debouncing work for a button input?
    
3. Explain PWM and a use case.
    
4. What is DMA and why is it used?
    
5. Describe how I2C arbitration works.
    
6. Explain synchronous vs asynchronous serial communication.
    
7. How does a watchdog timer work?
    
8. What is a brown-out detector?
    

### **Timing**

1. Explain timer overflow.
    
2. How do you convert a timer tick count into milliseconds?
    
3. Why are busy-wait loops discouraged?
    
4. How do you compute baud rate for UART?
    

---

# 🟦 **SECTION 5 — Debugging & Diagnostics**

### **Debugging Embedded Code**

1. Explain how to debug using SWD/JTAG.
    
2. Why might a hard fault occur?
    
3. How do you decode a stack trace?
    
4. How can misaligned memory access crash an MCU?
    
5. What happens when an ISR takes too long?
    
6. Why is global optimization (`-O2`, `-O3`) dangerous for debugging?
    

### **Common failure scenarios**

1. What causes `std::bad_alloc` on microcontrollers?
    
2. What causes stack overflow in embedded tasks?
    
3. Why do some peripherals behave unpredictably after waking from sleep?
    
4. Why can using `printf` cause crashes in embedded systems?
    

---

# 🟦 **SECTION 6 — Practical Embedded C/C++ Coding Challenges**

These are common interview coding tasks:

1. Implement a lock-free ring buffer with `volatile` head/tail indices.
    
2. Write a driver-style function that:
    
    - sets a bit
        
    - waits for a status bit
        
    - times out safely
        
3. Reorder a linked list without allocating memory.
    
4. Parse a simple command protocol (ASCII or binary).
    
5. Implement a fixed-size memory allocator.
    
6. Implement a debounce algorithm.
    
7. Write C++ code to model a hardware peripheral using a class with:
    
    - constructor initialization
        
    - RAII to enable/disable hardware
        
8. Write a constexpr function to compute a CRC.
    
9. Implement a timer-based event scheduler without using an RTOS.
    
10. Simulate SPI communication using bit-banging.
    

---

# 🟦 **SECTION 7 — Embedded C++ Design Patterns**

Interviewers frequently ask about these patterns:

1. **State Machine Pattern (Miro Samek)**
    
2. **RAII for peripherals**
    
3. **Static polymorphism (CRTP)**
    
4. **Non-allocating polymorphism**  
    (function pointers, variant, templates instead of virtuals)
    
5. **PIMPL without heap**
    
6. **Zero-cost drivers (compile-time configuration)**
    

---

# ⭐ Want a full curated “mock embedded interview”?

I can generate:

- 10 conceptual questions
    
- 10 hardware questions
    
- 10 C/C++ coding challenges
    
- 5 debugging logs where you must identify the root cause
    
- 1 full take-home embedded project
    

Just tell me the difficulty level:  
**junior / mid-level / senior / principal**.