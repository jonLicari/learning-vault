Here are **the best free (or mostly free) resources specifically geared toward embedded C/C++**, not generic software–so you can practice _real embedded concepts_ like memory-mapped I/O, concurrency, bare-metal programming, registers, ISRs, and performance-critical C++.

I’ve grouped them by **hands-on practice**, **problem sets**, **embedded C++ learning**, and **simulators/emulators**.

---

# ✅ **1. Hands-on Embedded C/C++ Practice (FREE)**

### **▶ Embedded Artistry: “C/C++ Practices for Embedded Systems”**

[https://embeddedartistry.com](https://embeddedartistry.com/)

- Articles and tutorials specifically about _embedded C++_, including
    
    - zero-cost abstractions
        
    - RAII for embedded
        
    - memory safety patterns
        
    - avoiding dynamic allocation
        
    - using STL in embedded
        
- Very high quality, real-world engineering level.
    
- Completely free.
    

---

### **▶ Miro Samek’s “Modern Embedded Systems Programming” (YouTube)**

Free course by a top embedded engineer (Quantum Leaps/QP).

- State machines
    
- ISRs
    
- RTOS vs bare-metal
    
- Embedded C++ real-world patterns
    
- Event-driven architectures
    
- MISRA C/C++ concepts  
    **Extremely practical** and industry-relevant.
    

---

### **▶ Memfault “Interrupt” blog**

[https://interrupt.memfault.com](https://interrupt.memfault.com/)

- Free production-grade embedded engineering articles
    
- Topics like:
    
    - UART/SPI/I2C deep dives
        
    - memory fragmentation
        
    - debugging crashes
        
    - linker script fundamentals
        
    - embedded C++ pitfalls
        
    - unit-testing embedded code  
        This is one of the **best free embedded engineering blogs in existence**.
        

---

# ✅ **2. Embedded-Focused Problem Sets & Exercises**

### **▶ Embedded Systems Programming on Codewars (C & C++)**

Not officially “embedded,” but there are many _low-level bit manipulation_ challenges:

- write your own memcpy
    
- bitfields
    
- reverse bits
    
- fixed-point math
    
- ring buffers
    
- CRC calculations
    

Great for sharpening the skills used in microcontroller work.

---

### **▶ Project Euler (algorithmic, but useful for math on MCUs)**

Helps sharpen skills around:

- integer overflow
    
- numeric optimization
    
- avoiding dynamic memory  
    Especially useful for embedded low-resource thinking.
    

---

### **▶ HackerRank C and C++ Problem Sets (low-level categories)**

Some categories are distinctly embedded-friendly:

- Bit Manipulation
    
- Pointer Exercises
    
- Array handling without STL
    
- Memory-constrained logic
    

Not ideal for hardware, but good for embedded-style logic.

---

# ✅ **3. MCU Simulators (Practice Without Hardware!)**

These let you program **real microcontrollers** in C/C++ without buying boards.

### **▶ Wokwi (free MCU simulator)**

[https://wokwi.com](https://wokwi.com/)  
Supports:

- AVR / Arduino
    
- ESP32
    
- RP2040  
    You write **C/C++**, interact with simulated sensors, LEDs, I/O.  
    Amazing for embedded practice.
    

---

### **▶ Renode (professional-grade embedded simulator—FREE)**

Supports dozens of MCUs and SoCs.  
Used by ARM, Google Nest, Nordic, etc.  
You can:

- build firmware in C/C++
    
- run it on simulated hardware
    
- debug via GDB  
    This is literally _industry-level embedded practice_ without hardware.
    

---

### **▶ QEMU ARM Cortex-M Emulation**

Completely free.  
You can write bare-metal ARM code in C/C++, load a `.elf`, and debug with GDB.

---

# ✅ **4. Deep Embedded Learning (Theory + C++)**

### **▶ “Modern C++ in Embedded Systems” by Meeting C++ (free videos)**

Covers:

- avoiding dynamic allocation
    
- constexpr in firmware
    
- placement new
    
- custom allocators
    
- zero-cost abstractions for MCUs
    

---

### **▶ FreeRTOS Official Course (book + examples)**

Even if you're not using FreeRTOS, it teaches:

- scheduling
    
- context switching
    
- priorities
    
- mutexes & deadlocks
    
- queues
    

All in C/C++ and widely applicable.

---

# ✅ **5. Build Embedded Projects (best long-term practice)**

Here are **embedded project types** that do NOT require hardware (with simulators):

### 1. **Bit-banged SPI, I2C, UART in C++**

Implement protocols manually. Great for timing & register-level thinking.

### 2. **Finite State Machines in C++ (Miro Samek style)**

Use polymorphism or `std::variant` for state patterns.

### 3. **Ring buffer / circular buffer library**

Classic embedded staple.

### 4. **Implement your own lightweight RTOS kernel**

With:

- cooperative scheduler
    
- preemption
    
- queues
    
- tasks
    

### 5. **Write a simple device driver**

For simulated GPIO or timers.

---

# ⭐ **If you want a single, structured "embedded C++ learning path"**

I can assemble one:

**(1) Language:**  
Modern Embedded C++ (Embedded Artistry + Meeting C++ video series)

**(2) Hardware simulation:**  
Wokwi → Renode → QEMU

**(3) Problem sets:**  
Bit manipulation exercises on Codewars + your own driver implementations

**(4) Real embedded architecture concepts:**  
Miro Samek + Interrupt blog + FreeRTOS material

---

[[Embedded Cpp Interview Question Bank]]