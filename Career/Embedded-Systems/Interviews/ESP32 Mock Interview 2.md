## 1. How would you keep memory dedicated to each core and/or task on ESP32?

> “On ESP32, memory isn’t strictly private per core, but I can control access patterns.”

Key points to say:

- Tasks can be **pinned to a specific core**
- Each task has its **own stack**
- Shared data must be explicitly managed

Good answer:

> “Each FreeRTOS task has its own stack, which is naturally isolated. For shared data, I either use message passing so only one task owns the data, or I protect shared memory using mutexes or spinlocks. Core pinning helps reduce contention, but memory protection is achieved through design, not hardware isolation.”

## 2. What is the difference between a thread and a task?

Embedded-safe explanation:

> “In FreeRTOS terminology, a task is essentially a thread of execution. The difference is mostly conceptual — a task includes its stack, priority, and scheduling metadata managed by the RTOS.”

Optional clarification:

- “Thread” is more common in desktop / POSIX systems
    
- “Task” is the RTOS abstraction
    

Safe phrasing:

> “On ESP32 with FreeRTOS, tasks are the unit of scheduling and are equivalent to threads in other systems.”

## 3. Should Wi-Fi / BLE always run on PRO_CPU? What does PRO_CPU mean?

What PRO_CPU is:

- **PRO_CPU = Protocol CPU**
    
- **APP_CPU = Application CPU**
    

Best-practice answer:

> “By default, ESP-IDF schedules Wi-Fi and Bluetooth stacks on the PRO_CPU, which is optimized for protocol handling. It’s best practice to leave Wi-Fi on PRO_CPU and pin time-critical application tasks to APP_CPU to reduce interference.”

Important nuance:

> “It’s not a hard rule, but following ESP-IDF’s default scheduling avoids subtle performance issues.”

## 4. Explain atomic vs volatile data

This one is a **classic trap** — answer it cleanly.

### Volatile

> “Volatile tells the compiler not to optimize away reads or writes, but it does not provide thread safety or atomicity.”

### Atomic

> “Atomic operations guarantee that a read or write completes without interruption and with proper memory ordering across cores.”

Key line (very strong):

> “Volatile is about visibility; atomic is about correctness under concurrency.”

## 5. Best practices for accessing shared memory (lock CPU, disable interrupts, etc.)

Correct hierarchy of tools:

> “The approach depends on context.”

Say this:

- **Between tasks** → mutexes / queues
- **ISR to task** → queues or task notifications
- **Very short critical sections** → critical sections / spinlocks (simple busy wait, burns CPU cycles but is non-blocking, mutex causes the waiting thread to sleep)
- **Avoid disabling interrupts** unless absolutely necessary
    

Strong phrasing:

> “I prefer message passing over shared memory. When shared memory is unavoidable, I use the least intrusive synchronization mechanism appropriate to the context.”


## 6. Typical process for a secure, reliable OTA update on ESP32

This is how to say it cleanly and confidently:

> “ESP32 uses a bootloader that runs before the application and is independent of application cores.”

Then step-by-step:

1. **Bootloader**
    - Runs before FreeRTOS
    - Chooses which firmware partition to boot
        
2. **OTA process**
    - New firmware is downloaded into an inactive partition
    - Integrity is verified (checksum / signature)
    - Metadata is updated to mark the new image as pending
        
3. **Reboot**
    - Bootloader attempts new firmware
    - If it fails, automatic rollback occurs
        
4. **Security**
    - Optional secure boot
    - Signed images only
        

Important clarification:

> “Cores are not updated independently — the firmware image applies to the entire system.”