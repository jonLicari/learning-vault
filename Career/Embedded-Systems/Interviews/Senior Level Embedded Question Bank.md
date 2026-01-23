## Questions

## **1. Conceptual Questions**

1. Explain interrupt latency and what affects it.
2. Describe how context switching works at the assembly level.
3. What happens during an MCU's reset sequence (startup.s)?
4. Explain cache coherency on Cortex-M7.
5. What is a memory barrier? When is it required?

## **2. C/C++ Questions**

1. Explain CRTP and give a use case in embedded.
2. How do zero-cost abstractions work in modern C++?
3. Why avoid `std::string` in embedded systems?
4. What is placement new and why is it useful?
5. Design a no-heap polymorphic system.

## **3. Hardware/RTOS Questions**

1. How does DMA circular buffering work?
2. What is the difference between ISR tail-chaining and late-arrival?
3. Describe a deadlock scenario in an RTOS.
4. How does an MMU-less architecture isolate memory?
5. How would you design a crash dump system for a microcontroller?

## **4. Coding Challenges**

1. Write a compile-time register map using `constexpr`.
2. Implement a non-blocking driver for UART (interrupt-driven).
3. Implement a minimal cooperative scheduler.
4. Write a fixed-size allocator (block pool).
5. Write a C++ state machine using templates (no virtuals).

## **5. Debugging Exercise**

**Problem:** System crashes after 60 minutes of uptime. RAM usage looks stable.  
**Question:** Identify possible causes:

- Timer rollover
- Stack creep
- ISR starving task
- Memory corruption
- Deadlock

## **6. Take-Home Project**

**Implement an event-driven motor controller**  
Features:

- Hardware abstraction layer (C or C++)
- ISR-based encoder input
- PID loop
- Emergency stop
- Must run in simulation (Renode/QEMU)

---

## Solutions