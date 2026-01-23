## Questions
### **1. Conceptual Questions**

1. What is the difference between RAM and Flash in a microcontroller?
2. What is a GPIO pin?
3. What does “debouncing” mean?
4. What is the purpose of an interrupt?
5. What is a pull-up resistor and when do you need one?

### **2. C/C++ Questions**

1. What does `volatile` mean and why is it used in embedded C?
2. What is the difference between `=` and `==`?
3. What is a segmentation fault?
4. What does this pointer type mean: `const int* p`?
5. Why should you avoid dynamic memory (`new/delete`) on microcontrollers?

### **3. Hardware/RTOS Questions**

1. What is an ISR?
2. What is a timer peripheral used for?
3. Why is polling less efficient than interrupts?
4. What is PWM used for?
5. What is a watchdog timer?

### **4. Coding Challenges**

1. Toggle a bit in a register:

  ```c
   reg ^= (1 << bit);
  ```

2. Write a function that counts how many bits are set in an 8-bit value.
3. Write a ring buffer struct with push/pop (8-byte buffer).
4. Remove duplicates from an array of integers (fixed size).
5. Implement a simple debounce (using a counter-based method).

### **5. Debugging Exercise**

**Problem:** A loop never ends.

```cpp
while (flag == 1) {
    // work
}
```

`flag` is modified in an ISR.  
**Question:** Why might the loop never exit? How do you fix it?

### **6. Take-Home Project**

**Write a button-controlled LED driver using a simulated MCU (Wokwi).**  
Requirements:

- Button press toggles LED
- Use debouncing
- No dynamic allocation
- Include comments and a diagram

---


---
## Solutions

### 1. Conceptual Questions

**What is the difference between RAM and Flash in a microcontroller?**
- Random Access Memory is volatile (temporary) memory which only lasts for the current powercycle and is lost when power ceases to be supplied.
	- Used for storage of temporary program data
- Flash is non-volatile memory which retains data between powercycles
	- Used for storage of application software or configuration settings

**What is a GPIO pin?**

- General Purpose Input/ Output pins are physical connections to the electronics of a system that can be fed from and read by the connecting MCU or other computational hardware
- Can be high, low or floating voltage
- Voltage can be supplied or read to set or read the state of the pin

**What does debouncing mean?**

- Bouncing refers to the physical oscillation that can occur between two contacts in realistic conditions, causing an oscillation in voltage across the contacts 
- This oscillation can cause unwanted logic level transitions
- Debouncing is the act of filtering a signal by way of setting a voltage and/ or speed threshold to determine which logic level transitions are desired and which are to be disregarded

**What is the purpose of an interrupt?**

- An interrupt allows for immediate reaction to time-critical events
- Interrupts can be triggered from hardware or asynchronous events 
	- Hardware peripherals (timer, UART, ADC, GPIO)
	- External signal 
	- Fault Condition
- When an interrupt occurs, the CPU saves the context
- The ISR can then execute safely
- Context is resumed once the ISR finishes

**What is a pull-up resistor and when do you need one?**

- A pull-up resistor pulls the voltage up to a known HIGH voltage level when no active device is driving the signal and prevents the voltage from floating
- Can be internal or externally added
- The pull-up resistor biases an input pin to a known state, enabling logic transitions
- Necessary when whenever an input may be left unconnected such as for button inputs, open-drain circuits, or shared bus lines like I2C

### **2. C/C++ Questions**

**What does `volatile` mean and why is it used in embedded C?**
- volatile is a keyword identifier used to protect associated data from unwanted compiler optimization
- It tells the compiler that the associated data may be modified outside of the program's control and thus that it must not assume that the data stays the same value between accesses 
- This is used when data can be accessed and modified from outside of the program's control, such as Hardware registers (UART, timers), peripherals (DMA), ISRs, etc.
- volatile ensures:
	- Each read fetches the actual memory location
	- Each write is performed exactly as written
	- No reordering or elimination of accesses


**What is the difference between `=` and `==`?** 
- `=` is an assignment operator; it assigns an rvalue to an lvalue; returns the assigned value
- `==` is a strict equality operator; it evaluates if two expressions are strictly equal to each other; returns a boolean 

**What is a segmentation fault?**

- A memory access error; the program tries to access data that it is not allowed to access
- Example: attempting to write to read-only memory, dereferencing null or uninitialized pointers, accessing freed memory

**What does this pointer type mean: `const int* p`?**

- This is a raw pointer to a constant integer value
- This means that the pointer itself can change what address it points to, but the value of the integer data referenced by it must not change

**Why should you avoid dynamic memory (`new/delete`) on microcontrollers?**

- In general, dynamic memory allocation is risky because microcontrollers are constrained devices meaning they have limited resources so there is the potential to run out of memory
- Dynamic allocations are also risky due as memory leaks can occur if resources are not deallocated properly
- Dynamically allocating data can cause fragmentation leading to unpredictable behaviour and slow overall performance

### **3. Hardware/RTOS Questions**

**What is an ISR?**

- Interrupt Service Routine is the functionality that is performed when interrupts occur
- From the ISR, different interrupt handler callback functions can be executed to service the interrupt
- Before the program jumps to the ISR, the MCU saves the current register context to the stack so the ISR can run safely
- Once the ISR concludes, the saved register context is reloaded and normal execution resumes
- Since ISRs can interrupt the execution cycle of the application, it is important that they are as lightweight and minimalist as possible
	- Avoid heavy computations or introducing delays through messaging, etc.
	- Keep handling lightweight (modify flag, clear register, etc.)

**What is a timer peripheral used for?**

- Timer peripherals are used to generate accurate and repeatable clock ticks
- Some have dedicated high-precision clock-sources that are higher quality than integrated timer oscillators, and thus used for very time-critical functionality
- Timers in general are used for generating clock ticks, necessary for time-critical functionality such as watchdog timers, ADC, DMA, etc

**Why is polling less efficient than interrupts?**

- Polling is when a certain condition is checked repeatedly; this wastes CPU cycles checking conditions when they have not occurred
- Interrupts are more efficient as they allow the CPU to perform useful work until the condition occurs
- Polling can be less efficient than interrupts because it does not service events immediately when they occur - this can cause latency in performance

**What is PWM used for?**

- Pulse Width Modulation is a signal generation technique used to enable dynamic signal generation using a discrete digital output
- Pulses are generated at different duty cycles to modify the average power to a load (motors, LEDs, heaters, etc)
- In this way, it allows digital devices to mock an analog signal

**What is a watchdog timer?**

- Watchdog timer is a special timer that is capable of resetting the MCU
- It is used as a system recovery solution
- The watchdog timer runs until either:
	- it is "kicked" timer is reset by application, indicating that it is alive and healthy or 
	- it expires, indicating that the application is unresponsive, upon which the MCU is reset


### **4. Coding Challenges**

1. Toggle a bit in a register:

  ```c
   reg ^= (1 << bit);
  ```

2. Write a function that counts how many bits are set in an 8-bit value.
3. Write a ring buffer struct with push/pop (8-byte buffer).
4. Remove duplicates from an array of integers (fixed size).
5. Implement a simple debounce (using a counter-based method).