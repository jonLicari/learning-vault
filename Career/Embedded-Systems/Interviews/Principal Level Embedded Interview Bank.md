## Questions

### **1. Conceptual Questions**

1. How do you design a fault-tolerant embedded system?
2. How does a dual-core MCU synchronize shared memory?
3. Describe how an RTOS handles interrupt nesting, preemption, and critical sections.
4. How do you architect for deterministic latency?
5. Explain the differences between lock-free, wait-free, and obstruction-free algorithms.

### **2. C/C++ Questions**

1. Architect a fully compile-time HAL using templates.
2. Show how to eliminate virtual function overhead in a large embedded system.
3. Explain ABI compatibility issues between toolchains.
4. Disassemble and analyze a piece of C++ code (given assembly).
5. Evaluate a large codebase for MISRA/CERT compliance.

### **3. Hardware/RTOS Questions**

1. How do you design for multi-core real-time determinism?
2. Compare bare-metal vs RTOS vs Linux RT in a system design.
3. Architect a secure bootloader with firmware rollback.
4. Design a system to handle asynchronous events at microsecond resolution.
5. Explain how bus contention affects real-time deadlines.

### **4. Coding Challenges**

1. Implement a fully lock-free message queue with memory fences.
2. Write a high-performance logging system with zero dynamic allocation.
3. Create a compile-time FSM using constexpr and metaprogramming.
4. Implement a custom linker script for memory segmentation.
5. Create a C++ hardware abstraction using only constexpr, templates, and no runtime overhead.

### **5. Debugging Exercise**

**Problem:** System occasionally corrupts data shared between DMA and CPU.  
**Question:** Diagnose likely root causes:

- Missing cache invalidation
- Incorrect memory region attributes
- Race conditions
- DMA not aligned
- Incorrect scatter-gather setup

### **6. Take-Home Project**

**Architect and implement a distributed embedded system**  
Requirements:

- Two simulated MCUs (Renode) communicating over UART/SPI
- Custom protocol
- Fault tolerance & retry logic
- Unit tests + integration tests
- HAL + driver + application layers
- Detailed documentation  
    This evaluates systems-level embedded engineering.


---

## Solutions