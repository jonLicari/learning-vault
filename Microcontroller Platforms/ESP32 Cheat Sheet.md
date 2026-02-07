# ESP32 Embedded Software — 30-Minute Cheat Sheet

## 1. High-level mental model (say this out loud if needed)

> “ESP32 is a dual-core MCU running FreeRTOS as the native execution model, with Wi-Fi/BLE stacks running concurrently, so application design is RTOS-first rather than superloop-based.”

If you say this confidently, you already sound legit.

---

## 2. ESP32 vs STM32 (1-minute comparison answer)

|STM32|ESP32|
|---|---|
|Optional RTOS|**FreeRTOS is mandatory**|
|Single core|**Dual core (PRO + APP)**|
|Deterministic timing|**Wi-Fi/BLE add jitter**|
|HAL/LL|**ESP-IDF drivers**|
|Flat memory|**Multiple memory regions**|

Key phrase:

> “ESP32 behaves more like a small SMP system than a traditional MCU.”

---

## 3. Dual-core basics (VERY important)

- Two cores:
    
    - **PRO_CPU** → usually system / Wi-Fi
        
    - **APP_CPU** → user tasks
        
- Tasks can be:
    
    - Unpinned (run on any core)
        
    - **Pinned to a core**
        

Example talking point:

> “Time-critical tasks are often pinned to a core to avoid interference from Wi-Fi tasks.”

Race conditions:

- Shared memory **must** be protected
    
- Use:
    
    - Mutexes
        
    - Spinlocks
        
    - Critical sections
        
- `volatile` alone is **not sufficient**
    

---

## 4. FreeRTOS on ESP32 (know these cold)

FreeRTOS is **not optional middleware**.

Key concepts they expect:

- Tasks
    
- Queues
    
- Semaphores / mutexes
    
- Event groups
    
- ISRs vs task context
    

ESP32 specifics:

- ISRs are short and defer work to tasks
    
- Use queues or task notifications from ISRs
    
- Stack sizes matter more due to Wi-Fi usage
    

Good answer line:

> “ISRs should do minimal work and signal a task via a queue or notification.”

---

## 5. Wi-Fi / BLE impact (common trick question)

Reality:

- Wi-Fi tasks run in background
    
- Can preempt your code
    
- Cause latency spikes
    
- Consume heap and CPU
    

Correct design response:

- Avoid hard real-time guarantees during Wi-Fi activity
    
- Separate networking from time-critical tasks
    
- Pin real-time tasks to a core if needed
    

If asked about jitter:

> “Wi-Fi introduces non-determinism, so hard real-time behavior must be carefully isolated.”

---

## 6. Memory model (you don’t need details, just awareness)

ESP32 memory types:

- **IRAM** → code that must run when flash cache is off
    
- **DRAM** → data
    
- Flash-mapped memory
    
- DMA-capable vs non-DMA memory
    

Why it matters:

- Some ISRs must be in IRAM
    
- Flash operations can stall execution
    
- DMA buffers must be allocated carefully
    

Safe statement:

> “On ESP32 you must be aware of which memory region code and data live in, especially for ISRs and DMA.”

---

## 7. Peripheral handling (similar but different)

Similar to STM32:

- GPIO, UART, SPI, I2C, timers
    

Different:

- Drivers are asynchronous
    
- Often callback-based
    
- Integrated with FreeRTOS
    
- Less register-level work in application code
    

Say this:

> “ESP-IDF abstracts peripherals more heavily and integrates them into the RTOS model.”

---

## 8. Boot & execution flow (simple version)

STM32:

`Reset → main() → while(1)`

ESP32:

`Bootloader → ESP-IDF init → FreeRTOS scheduler → tasks`

You don’t “own” the main loop.

---

## 9. Build & tooling buzzwords (drop casually)

- ESP-IDF
    
- `idf.py`
    
- CMake
    
- `menuconfig`
    
- Logging macros (`ESP_LOGI`, etc.)
    
- OTA updates supported natively
    

Even just naming these helps.

---

## 10. Common interview questions & bullet answers

### “How do you handle concurrency on ESP32?”

- FreeRTOS primitives
    
- Core pinning
    
- Careful shared resource protection
    

### “How do you ensure real-time behavior?”

- Minimize Wi-Fi interaction
    
- Task priorities
    
- Pin tasks to a core
    
- Avoid heavy work in ISRs
    

### “ESP32 vs STM32 — when would you choose ESP32?”

- Built-in Wi-Fi/BLE
    
- IoT applications
    
- OTA support
    
- Faster time to market
    

---

## 11. If you get a coding question (unlikely but possible)

They are NOT expecting:

- Perfect ESP-IDF syntax
    

They ARE expecting:

- Clean structure
    
- RTOS awareness
    
- ISR safety
    
- Thread safety
    

Pseudo-code is acceptable.

---

## 12. Final framing line (use this if unsure)

If you’re ever stuck, say:

> “My experience is primarily on STM32, but the concepts transfer directly — the main adjustment on ESP32 is treating FreeRTOS and dual-core behavior as first-class concerns.”

That sounds mature, not weak.

---
# How to Win a Recorded, No-Editor Technical Interview

## Your #1 goal

Sound like a **calm, senior embedded engineer** who:

- Clarifies assumptions
- Structures problems
- Identifies tradeoffs
- Designs safe systems

---
## The Universal Answer Structure (memorize this)

Use this for **every question**:

> **1. Restate the problem**  
> **2. State assumptions**  
> **3. Outline approach**  
> **4. Identify risks / edge cases**  
> **5. Summarize solution**

If you do only this, you’ll already score high.

---

# The 11 Most Likely Question Types (with model answers)

## 1. Concurrency / Race Condition

**Question:**  
“How would you safely share data between tasks or cores?”

**Answer structure:**

- Shared state = dangerous    
- Identify readers/writers
- Protect with mutex or message passing
- Avoid work in ISR

**Model phrasing:**

> “First I’d identify who produces and consumes the data. If it’s shared state, I’d protect it with a mutex or redesign using message passing via queues to avoid shared memory entirely.”

---

## 2. ISR Design

**Question:**  
“How do you design an interrupt handler?”

**Key points:**

- Minimal work    
- No blocking
- Signal a task

**Model phrasing:**

> “An ISR should do the minimum possible — acknowledge the interrupt and notify a task using a queue or task notification.”

---

## 3. Timing / Real-Time Behavior

**Question:**  
“How would you ensure real-time performance?”

**Key points:**

- Define what “real-time” means
- Priorities
- Avoid blocking
- Measure latency

**Model phrasing:**

> “I’d first define whether this is hard or soft real-time, then assign task priorities accordingly and ensure no blocking calls exist on critical paths.”

---

## 4. System Design (Open-Ended)

**Question:**  
“Design firmware for X device.”

**Approach:**

- Break into subsystems
- Tasks per responsibility
- Clear interfaces

**Model phrasing:**

> “I’d decompose the system into independent tasks — hardware I/O, processing, communication — and connect them using queues for clear ownership.”

---

## 5. Debugging a Bug You Can’t Reproduce

**Key points:**

- Instrumentation
- Logging
- Narrow scope
- Hypothesize → test

**Model phrasing:**

> “I’d add lightweight logging to capture state leading up to the failure and try to narrow the issue to timing, memory, or concurrency.”

---

## 6. Memory Issues

**Question:**  
“How do you avoid memory problems?”

**Key points:**

- Avoid fragmentation
- Static allocation when possible
- Watch stack sizes

**Model phrasing:**

> “I prefer static allocation in embedded systems and closely monitor stack usage to prevent overflows.”

---

## 7. Power Management

**Key points:**

- Sleep modes
- Peripheral shutdown
- Event-driven wakeup

**Model phrasing:**

> “I’d design the system to be event-driven so the CPU can remain in low-power states as much as possible.”

---

## 8. Communication Protocols

**Question:**  
“How do you ensure reliable communication?”

**Key points:**

- Timeouts
- Retries
- State machines
- CRC

**Model phrasing:**

> “I’d implement a simple state machine with timeouts and retries, and validate data integrity using checksums.”

---

## 9. Failure Handling

**Key points:**

- Detect failure
- Fail safely
- Recover if possible

**Model phrasing:**

> “I’d ensure the system fails into a known safe state and attempts recovery where appropriate.”

---

## 10. Tradeoff Question

**Question:**  
“Why choose approach A over B?”

**Key points:**

- No right answer
- Explain constraints

**Model phrasing:**

> “The choice depends on constraints like timing, memory, and complexity. I’d prefer A when determinism matters and B when flexibility is more important.”

---

## 11. “What would you do differently?”

**Key points:**

- Reflection
- Iteration
- Improvement mindset

**Model phrasing:**

> “After validating functionality, I’d focus on simplifying the design and reducing coupling between components.”

---

# Recovery Line (if you blank)

> “I don’t have full information, so I’ll make reasonable assumptions and explain my approach.”


[[ESP32 Mock Interview]]