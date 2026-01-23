## Questions

### **1. Conceptual Questions**

1. Explain how memory-mapped I/O works.
2. What is an interrupt priority?
3. What is the difference between `struct` and `class` in C++?
4. Explain stack overflow in embedded systems.
5. What is a linker script?

### **2. C/C++ Questions**

1. Explain the “rule of 5”.
2. What is the memory layout of an object with virtual methods?
3. Why is this an error:
```cpp
  const void foo();
```
1. Explain undefined behavior with examples.
2. What is the cost of exceptions on MCUs?

### **3. Hardware/RTOS Questions**

1. How does a preemptive scheduler work?
2. Difference between a binary semaphore and a mutex.
3. What is priority inversion?
4. Explain DMA and how it improves performance.
5. What is a race condition? Give an MCU example.

### **4. Coding Challenges**

1. Implement a lock-free ring buffer (head/tail, volatile).
2. Parse a space-separated string into integers without heap allocations.
3. Implement a CRC16 calculator.
4. Implement a finite state machine for a traffic light.
5. Implement millisecond timing using SysTick.

### **5. Debugging Exercise**

**Problem:** UART reads garbage unless compiled with `-O0`.  
**Question:** What's likely happening? (Optimization removed volatile access / timing too tight)

### **6. Take-Home Project**

**Create a simulated temperature sensor system.**  
Requirements:

- Driver for ADC
- Moving average filter
- Alert when temperature > threshold
- Use FreeRTOS or a cooperative scheduler
- Must run on Wokwi, Renode, or QEMU

---

## Solutions