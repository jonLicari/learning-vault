[[ESP32 Mock Interview 2 | Additional Questions]]
## Question 1

**Scenario:**

You’re designing firmware for an ESP32-based device that:

- Reads data from a sensor every 10 ms
- Sends aggregated data over Wi-Fi once per second
- Must remain responsive even when Wi-Fi activity spikes

**Question:**

**Talk me through how you would architect this system.**  
Focus on:

- Task structure
- Timing guarantees
- How you prevent Wi-Fi from interfering with sensor sampling
### Model Answer (2–3 minutes)

> “Let me restate the problem to make sure I understand it. We need to sample a sensor every 10 milliseconds, aggregate that data, and send it over Wi-Fi once per second, while ensuring Wi-Fi activity doesn’t interfere with sensor timing.”

> “I’d architect this using separate FreeRTOS tasks. I’d create a high-priority periodic sensor task that runs every 10 milliseconds. This task would be pinned to the APP_CPU to isolate it from Wi-Fi activity.”

> “Sensor sampling would be driven by a FreeRTOS delay or timer rather than busy polling to ensure consistent timing and low CPU usage.”

> “I’d have a lower-priority aggregation or communication task that runs once per second and handles packaging the data for transmission. Wi-Fi tasks would remain on the PRO_CPU, where ESP-IDF typically schedules them.”

> “Communication between tasks would use a queue or buffer to avoid shared state, allowing the sensor task to remain fast and deterministic.”

> “This design keeps time-critical sampling isolated, uses preemptive scheduling with priorities, and prevents Wi-Fi latency from impacting sensor reads.”

> “In summary, the key is task isolation, core pinning, and RTOS-driven timing rather than polling.”

### Question 2

**Question:**

A shared data buffer is written by a sensor task and read by both a logging task and a Wi-Fi task on different cores.

👉 **How would you design this to be thread-safe and avoid performance bottlenecks?**

### Model Answer

> “First, I’d identify this as a shared resource accessed from multiple tasks across two cores, which means we need both thread safety and low latency.”

> “The simplest solution would be to protect the buffer with a mutex, but that risks blocking the sensor task, which is time-critical.”

> “Instead, I’d prefer a design where the sensor task owns the buffer and publishes data using a FreeRTOS queue or ring buffer. The logging and Wi-Fi tasks would consume copies or pointers, avoiding shared mutable state.”

> “If a mutex is required, I’d keep the critical section very small and ensure the sensor task has higher priority to avoid priority inversion.”

> “Atomic operations would be useful for small state variables like buffer indices or flags, but not for protecting the entire buffer.”

> “In summary, message passing over shared memory gives better performance and scalability on a dual-core ESP32.”

### Question 3

**Question:**

A GPIO interrupt fires when a sensor detects an event.  
This event must be processed within 1 ms, but the processing itself takes several milliseconds.

👉 **How would you design this system on ESP32?**

### Model Answer

> “Let me restate the problem. A GPIO interrupt signals an event that must be responded to within 1 millisecond, but the actual processing takes several milliseconds, which means it cannot be done inside the ISR.”

> “The ISR should be lightweight and non-blocking. Its only responsibility would be to acknowledge the interrupt and signal a higher-level task that work needs to be done.”

> “I’d use a FreeRTOS mechanism like a task notification or queue from ISR context to wake a dedicated processing task. That task would run at a high priority to meet the timing requirement.”

> “Since events may arrive faster than they can be processed, I’d introduce a buffer, such as a ring buffer or queue, to decouple event arrival from processing.”

> “On ESP32, I’d also consider pinning the processing task to a core to avoid interference from Wi-Fi or other system tasks.”

> “In summary, the ISR guarantees fast response, while the task handles the longer processing in a controlled, schedulable context.”

### Question 4

**Question:**

Your ESP32 system occasionally resets after running for several hours.  
There is no obvious crash log.

👉 **Talk through how you would debug and diagnose this issue.**

### Model Answer

> “First, I’d confirm the cause of the reset rather than assuming it. On ESP32 there are several possibilities, including watchdog timeouts, brownouts, stack overflows, or heap corruption.”

> “I’d start by checking the reset reason using the ESP-IDF reset APIs to see whether it was a watchdog, power-related, or software fault.”

> “If watchdog-related, I’d investigate which task may be blocking or starving the system, and verify watchdog configuration and task priorities.”

> “I’d also enable additional diagnostics such as stack overflow detection, heap integrity checks, and core dumps to flash or UART to capture context before the reset.”

> “Since this happens after long runtimes, I’d suspect memory issues like heap fragmentation or stack exhaustion, so I’d monitor heap usage and task stack high-water marks over time.”

> “In parallel, I’d rule out hardware causes by checking power stability with an oscilloscope to detect brownouts or transient drops.”

> “Finally, I’d add targeted logging or counters to narrow down what the system was doing just before the reset.”

> “In summary, I’d approach this systematically by identifying the reset cause, increasing observability, and isolating whether the issue is software timing, memory, or hardware-related.”

### Question 5

**Question:**

How do you decide between **static allocation** and **dynamic allocation** in an embedded FreeRTOS system like ESP32?

> “In an embedded FreeRTOS system like ESP32, I generally prefer static allocation for components that are time-critical or long-lived, because it provides deterministic memory usage and avoids fragmentation.”

> “Static allocation is especially important for task stacks, queues, and core system components where predictable behavior matters.”

> “That said, dynamic allocation can be appropriate when memory requirements are variable or not known at compile time, such as network buffers or optional features.”

> “When using dynamic allocation, I’m careful to control allocation lifetimes, avoid frequent allocate-free cycles, and monitor heap usage to prevent fragmentation over long runtimes.”

> “On ESP32, I also take advantage of RTOS and ESP-IDF diagnostics like heap integrity checks and stack high-water marks to validate memory usage.”

> “In summary, the decision is about balancing determinism and flexibility — static allocation for critical paths, dynamic allocation where flexibility is required and well-controlled.”

### Question 6

**Question:**

You notice that when Wi-Fi is enabled, your ESP32 system experiences occasional latency spikes in time-critical tasks.

👉 **How would you analyze and mitigate this?**

> “First, I’d analyze the problem to confirm that Wi-Fi activity correlates with the latency spikes. I’d look at task scheduling, CPU utilization, and whether spikes align with transmit or receive events.”

> “On ESP32, Wi-Fi runs background tasks that can preempt application code, so I’d check task priorities and whether time-critical tasks are being starved.”

> “I’d measure task execution times and jitter using RTOS tracing or timestamp logging to understand where deadlines are being missed.”

> “To mitigate the issue, I’d isolate time-critical tasks by pinning them to a core that’s not heavily used by Wi-Fi, typically the APP_CPU.”

> “I’d also ensure that real-time tasks have higher priority and avoid blocking calls or dynamic memory allocation in those paths.”

> “If needed, I’d decouple Wi-Fi communication using buffers or queues so networking delays don’t directly impact time-critical logic.”

> “In summary, the solution is to combine measurement with isolation — understand where latency comes from, then use task priorities, core pinning, and buffering to contain Wi-Fi side effects.”


### Question 7

**Question:**

Design a **firmware update (OTA)** strategy for an ESP32 device deployed in the field.

👉 Talk through reliability, failure recovery, and safety.

> “For an ESP32 OTA update strategy, reliability and safety are critical since devices may be deployed remotely.”

> “First, during transmission, I’d ensure data integrity using checksums or CRCs and only accept the update once the full image has been received and validated.”

> “On the device side, I’d use a dual-partition or A/B update strategy, where the new firmware is written to an inactive partition while the currently running firmware remains untouched.”

> “After flashing the new image, I’d validate it and update metadata so the bootloader attempts to boot the new firmware on the next reset.”

> “If the new firmware fails to boot or crashes during startup, the bootloader can automatically roll back to the previous known-good version.”

> “This approach protects against power loss during updates, which is a common failure scenario.”

> “Optionally, delta updates can be used to reduce bandwidth, but they add complexity and must be carefully validated.”

> “In summary, the key principles are integrity checking, safe partitioning, bootloader-controlled rollback, and protection against power and connectivity failures.”

### Question 8

**Question:**

You’re given an unfamiliar embedded codebase that is poorly documented and has known bugs.

👉 **How do you approach understanding and improving it?**

### Model Answer

> “I’d start with a top-down approach rather than immediately diving into the code.”

> “First, I’d understand the product context — what problem the device solves, who uses it, and what the high-level requirements are.”

> “Next, I’d translate that into technical expectations: real-time constraints, reliability requirements, and key subsystems.”

> “Before modifying anything, I’d make sure I can reliably build, flash, debug, and deploy the firmware so I have a safe environment to work in.”

> “I’d then reproduce known bugs and add targeted logging or instrumentation to better understand system behavior.”

> “From there, I’d create small test cases to validate individual components and ensure changes are incremental and reversible.”

> “Throughout the process, I’d avoid large refactors until I understand system dependencies and failure modes.”

> “In summary, the goal is to build confidence in the system first, then improve it incrementally with minimal risk.”


## Question 9 (Deep reasoning — classic RTOS trap)

### **Question 9**

A task in your FreeRTOS system occasionally **misses its deadline**,  
but **overall CPU usage is only ~40%**.

👉 **How would you explain this, and how would you investigate it?**

### Model Answer (video-ready)

> “Low CPU utilization doesn’t guarantee deadlines are met, because missed deadlines are often caused by blocking or scheduling issues rather than raw CPU load.”

> “I’d first look for blocking calls — mutexes, queues, or delays — that may be preventing the task from running when it needs to.”

> “I’d also check task priorities to see whether higher-priority tasks or interrupts are preempting it at critical times.”

> “On ESP32 specifically, I’d verify whether Wi-Fi or system tasks are interfering, and whether the task is pinned to an appropriate core.”

> “To investigate, I’d measure task execution time and jitter using timestamps or RTOS tracing, and check for priority inversion or resource contention.”

> “In summary, missed deadlines are usually caused by scheduling, blocking, or contention — not lack of CPU.”


# Question 10 (Tradeoff / judgment test)

### **Question 10**

You’re asked to optimize an embedded system for **performance**, but doing so increases **complexity** and reduces **maintainability**.

👉 **How do you decide whether the optimization is worth it?**

### Model Answer

> “I’d start by identifying whether performance is actually a bottleneck or just a perceived issue.”

> “If the system already meets its timing and reliability requirements, I’m cautious about adding complexity that could reduce maintainability or increase risk.”

> “When optimization is required, I prefer targeted changes backed by measurement rather than broad refactoring.”

> “I also consider the long-term cost — debugging, onboarding, and future changes — especially for systems deployed in the field.”

> “In short, optimization is justified when it solves a real problem and the benefits clearly outweigh the added complexity.”


# Question 11 (Senior-level reflection / culture fit)

### **Question 11**

Tell us about a time you had to make a **technical decision with incomplete information**.

👉 **How did you approach it?**

### Model Answer (generic but excellent)

> “In embedded systems, incomplete information is common, so I start by identifying what assumptions I need to make and what risks those assumptions introduce.”

> “I choose a conservative approach that prioritizes safety and reversibility, and I validate the decision as early as possible with testing or instrumentation.”

> “As more information becomes available, I refine the solution rather than committing too early to a complex design.”

> “The key is making progress while minimizing the risk of irreversible mistakes.”

---