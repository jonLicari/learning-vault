[[#Table of Contents]]
- [[#HOW DOES A BOOTLOADER WORK?|HOW DOES A BOOTLOADER WORK?]]
- [[#MICROCONTROLLER BOOT PROCESS|MICROCONTROLLER BOOT PROCESS]]
	- [[#MICROCONTROLLER BOOT PROCESS#What are Vector Tables?|What are Vector Tables?]]
- [[#HOW TO PROGRAM CUSTOM BOOTLADER|HOW TO PROGRAM CUSTOM BOOTLADER]]
	- [[#REQUIREMENTS|REQUIREMENTS]]
	- [[#UDEMY STM32 CUSTOM BOOTLOADER]]
	- [[##Boot Configurations of STM32 MCU|Boot Configurations of STM32 MCU]]
	- [[#MCU BOOTLOADER PROCEDURE]]
		- [[#Vector Table Relocation]]
		- [[#Vector Table Offset Register VTOR]]
		- [[#Nested Vector Interrupt Controller (NVIC)]]
		- [[#ABSENT VTOR ON CORTEX M0]]
		- [[#HOST TO MCU TRANSFER]]
		- [[#PAGING]]
		- [[#CHECKSUMS AND HAMMING DISTANCE]]
			- [[#STM32 CRC UNIT]]
- [[#BOOTLOADER CODE FLOW]]

In computing, a bootstrap loader is the first piece of code that runs when a machine starts, and is responsible for loading the rest of the OS. In modern computers it is stored in ROM, but can be accessed by hardware manipulation (switches) which can load different disk segments into memory and run them.

A bootloader, also known as a boot program or bootstrap loader, is a special OS software that loads into the working memory of a computer after start-up. For this purpose, immediately after a device starts, a bootloader is generally launched by a bootable medium like a hard drive, USB stick, CD. 

The boot medium receives information from the computer’s firmware (e.g. BIOS) about where the bootloader is. The whole process is also described as booting.


## HOW DOES A BOOTLOADER WORK?

When you press the start button on a computer, the first thing you see on screen is information about the hardware installed. The software responsible for this notification is the device firmware mentioned above, which is usually implemented by manufacturers in flash memory on the computer’s motherboard. With most PCs and notebooks this will be the Basic Input/ Output System ([[BIOS]]) or the more modern Unified Extensible Firmware Interface ([[UEFI]]). Both of these applications collect the most diverse hardware data and create a complete list of all of the device’s available drives.

## MICROCONTROLLER BOOT PROCESS

[https://www.beningo.com/understanding-the-microcontroller-boot-process/](https://www.beningo.com/understanding-the-microcontroller-boot-process/)

The MCU boot process starts by applying power to the system. Once the voltage rails stabilize, the MCU looks to the reset vector for the memory location in flash where the start-up instructions can be found. The reset vector is a special location within the flash memory map. 

NOTE: STM32F051C6T7 FLASH = 8x 32 KB, RAM = 8x 8 KB

The address that is stored at the reset vector is loaded by the microcontroller and the instructions are loaded and executed by the CPU. These are instructions for how to start-up the MCU, not the developer’s program.
### What are Vector Tables?

- Consists of a set of assembler instructions, which cause the microcontroller or computer to jump to a specific location that can handle a specific exception or interrupt. A vector uses a special assembler instruction to load the address of the handler
    
- The vector table offset register can be used to relocate the vector table to any boundary in the Cortex memory map

The vector tables that are stored in flash are copied into RAM. Depending on architecture, there may be an instruction to update the vector table register so that the microcontroller knows where the start of the RAM table is.

Next, data sections (e.g. variables that have been initialized to non 0) are copied into RAM followed by .bss (e.g. variables that have not been initialized or init to 0). 

Finally, the microcontroller will copy any functions from flash to RAM. 

This process is called the “C copy down”. Once it’s completed, the microcontroller then jumps to the start of the main application where the developer’s application begins.

## HOW TO PROGRAM CUSTOM BOOTLADER

My understanding so far is that I will make a bootloader which is a regular application capable of loading different developer-made applications from flash to the RAM where they will be executed. 

A default application will load on start-up (could be bootloader or original firmware)

Bootloader activated on hardware interrupt (I/O Pin 2 goes high) and on that interrupt, switch the reset vector memory location to the start address of the application we wish to load. The bootloader will then force a reset to begin the newly loaded application

Bootloader can also be capable of receiving a new binary from an external source like RPi which talks to the bootloader already in the microcontroller via UART serial line which writes the binary to user application program memory

A basic bootloader can have a serial line connected to a host. The bootloader can run from reset and poll for an upload request. If the upload program was running it would respond and send a new app image. If it did not respond, the polling timeout would be reached and the bootloader would load the existing application. 

Program memory uploader for devices with enough memory that multiple app images can be stored at the same time. This way, the bootloader simply has to reassign the reset vector memory location to launch the new app

Based on this, I must be able to have the bootloaders interrupt vector table active at all times irrespective of which application is running. Dissimilarly, the currently running application interrupt vector table needs to be swapped with the newly loaded application’s  interrupt vector table.
 

ST Application note:
Write Memory command: used to write data to any valid memory address i.e RAM, flash memory, option byte area

Know what a [[Compilers]], [[Librarians]], and [[Linkers]] each do in the context of building firmware.

![](https://lh7-us.googleusercontent.com/j1xuJM7k3qD17jLSGIuO3CsdUjeyF0c3VbZjeYLZEDG2FH4rtRkeSWMx0mSXvb5saAQa4HU6MMPhw4qbOepS-dZ4cwZIqPGbgElj-LofrbtlBHU-CGzduKYoK_PHrO0JBI3v36jXU_bSiEnQblv7UQ)

![](https://lh7-us.googleusercontent.com/pVx_DZzgJqGbq7_Yijo0a8SUwlZye-FzD_BYaUUv3-sE8B2DWuk3Wo5is8dg9nOtZBKkts6OhwfACDYrk2-Ic9E9aNi-7AcQimPGoFMaH3qjcXCaT-1ZfGbPl-iV8f25QWEY9LXoawHyRDXTyFN63A)

 

## REQUIREMENTS:

- Should be able to:
	- detect, 
	- report, and 
	- handle errors: 
		- power failure, 
		- loss of communication, 
		- security check failure, and 
		- write flash error 
- Flash error protection is usually achieved by storing a checksum or CRC
- If errors exist in the check, BL communicates with host and redownloads the corrupted packet
- How would a BL update itself? In ROM, a BL will be protected from being overwritten but cannot be updated. [Vendor supplied bootloader exists in System Memory](https://www.datasheets360.com/pdf/8816423916946185521). We can use this Vendor-Supplied BL (VSBL) to flash a new Custom BL (CBL)
- Check if firmware is up to date by tracking version numbers [1]
- Does there need to be an interface for the user or is this only for our (developers) use?
- Can the incoming program file be stored in external memory? If so it must be encrypted when stored externally, and decrypted when storing it internally
- Reserving a pin on the slave MCU is robust because the host can call BL regardless if main application and primary communication interface is not functional
- BL loads if main application space is empty or damaged; detection can be simple (check non-erased state of flash location) or complex (calculating CRC or hash of the entire application image). Balancing speed and robustness of error detection must be evaluated
- Generally, it is better to use slow, but secure algorithms for new image verification, and fast algorithms (like CRC32) for application integrity verification. [2]
    
- White paper outlining common requirements for generic bootloader
	- Ability to switch or select operating mode (application or BL)
    - Communication interface requirements (UART, I2C, etc)
    - Record parsing requirement (S-record, hex, intel, toeff, etc) how does the bootloader turn the file into data to be stored in flash?
    - Flash system requirements (erase, write, read, location)
    - EEPROM requirements (partition, erase, read, write)
    - Application checksum (verify app is not corrupt)
    - Code security (protecting the bootloader and the application)
    
- Can use inline assembly function to check if the user application reset vector is FFFF (indicating no user application) branch to BL if this is true, else safe to jump to the user application pg10
- A single GPIO line is not robust, so it is better to have something more definitive like writing a flag in EEPROM. The application therefore needs a command that can write an EEPROM byte to notify the boot-loader that it should run and then perform a soft reset of the system.
- Soft reset (A common method used for restarting the system is to cause the watchdog timer to timeout or restart the system. Most watchdog timers will immediately reset if incorrect values are written to it. The other option would be to place the system into an infinite loop and allow the watchdog to time-out at its own pace) 
- Refer to Appendix A for a functional requirement example [3] 

“The final option is to create your own bootloader. Diving into the details can be quite rewarding and challenging. Bootloaders reveal just how well, or not well, a developer understands their microcontroller, embedded software and how to debug applications. A typical development effort for an experienced developer can take four to six weeks depending on the complexity and interface requirements. A developer with little to no experience with a bootloader can easily take 10 to 12 weeks. The learning curve and bugs are not trivial.” - Jason Beningo


### Sources:

[1] [https://www.embedded.com/bootloaders-101-making-your-embedded-design-future-proof/](https://www.embedded.com/bootloaders-101-making-your-embedded-design-future-proof/) 

[2] [http://ww1.microchip.com/downloads/en/DeviceDoc/Bootloader-Design-Considerations-90003207A.pdf](http://ww1.microchip.com/downloads/en/DeviceDoc/Bootloader-Design-Considerations-90003207A.pdf)

[3] [https://www.beningo.com/wp-content/uploads/images/Papers/bootloader_design_for_microcontrollers_in_embedded_systems%20.pdf](https://www.beningo.com/wp-content/uploads/images/Papers/bootloader_design_for_microcontrollers_in_embedded_systems%20.pdf)

  
## UDEMY: STM32 CUSTOM BOOTLOADER

1. Find system memory location for specific STM32
2. Reset MCU to default state (bootloader)
    1. Set RCC to default values (same as on startup)
    2. Disable sysTick interrupt and reset it to default
    3. Disable all interrupts
3. Map system memory to 0x00000000 location
4. Set jump location to memory location +4 bytes offset
5. Set main stack pointer to value stored at system memory location address
6. Call virtual function assigned before


## Boot Configurations of STM32 MCU

After reset, Processor looks at 0x00000000 which has an alias for 0x08000000 which is the MSP (main stack pointer). 

The next address, 0x08000004 is the Reset Handler Address.

The Boot Mode selection pins are used to determine the boot area:

- BOOT0[0] - Main Flash memory is selected as the boot area
    
- BOOT0[1], BOOT1[0] - System memory is selected as the boot area
    
- BOOT0[1], BOOT1[1] - Embedded SRAM is selected as the boot area

## MCU BOOTLOADER PROCEDURE
1. Power up 
2. Boot configuration start address 0x00000000
3. Program counter is loaded with start flash address 0x08000000 where bootloader is stored
4. Bootloader jumps to user application by:
	1. Determine if a user program exists. If the user program doesn’t exist, start running the main bootloader program and abort this sequence
    2. Verify application checksum and security credentials
    3. Disable interrupts 
    4. Set VTOR to the start of the user program (table lives at the beginning of the flash image of the program)
    5. Read the address of the stack pointer from the first word of the user program
    6. Set up function pointer which holds the user application reset handler from the second word
    7. Configure the MSP by reading the value from the base address of Page where user app is stored
    8. Set the new stack pointer using __set_MSP()
    9. MSP is the base address, reset handler is the base+4B address
    10. Jump to the user application reset handler

### Vector Table Relocation
Unlike the Cortex M0+, M3 and M4, the M0 does not support vector table relocation ( it is fixed at 0x00000000). It does not use a register (VTOR) to remap the vector table so you must copy the new table into the base of RAM so it can be mapped/ shadowed at address 0. Src: [https://community.st.com/s/question/0D50X00009XkYjd/custom-bootloader-on-stm32f0](https://community.st.com/s/question/0D50X00009XkYjd/custom-bootloader-on-stm32f0)

### Vector Table Offset Register VTOR 
- Default set to 0 which is an alias for 0x08000000 (vector table location for default application, our bootloader) 
- To switch to the user application, VTOR = 0x0800xxxx (start address of user app) so that the user app’s vector table is used, not the bootloader’s  

The VTOR points to the location of the NVIC. By default, VTOR points to 0x00000000 so when power comes up, the handler whose address lives at 0x00000004 is executed to handle the reset. Later the program may modify the VTOR so that it points at some other location in memory like 0x08004000. After that point, the NVIC would read 0x0800402C to determine the address of the handler to call.

The ARM core uses a boot remapping feature which uses the physical BOOT0 pin to map the flash (which starts at 0x08000000) onto the memory space starting at 0x00000000. System memory is a ROM which usually contains some ST supplied bootloader. Some STM32s have support for extra modes like mapping the SRAM (address 0x20000000) onto 0x00000000.

  
### Nested Vector Interrupt Controller (NVIC) 

- Used to prioritize peripheral interrupts while managing the code which is executed in response. 
- It works by using a lookup table at a specific location to determine what code to execute    
- When an interrupt occurs, the NVIC will read the handler address from the table and then execute the handler


![](https://lh7-us.googleusercontent.com/Q96GNko3veF7aWgnDXVP9e0qrAFXSm1NPkoo1EDPdI5w8rTyHkkwxPQJQ4-sjGDrZDcMLZ21KEvMjgNwM2kE0gu1VGqJTXSi-W9_kJxVf1Yq_JggtFjsAfoGrMvu7buwRawkIYpCcNbV_gdQOqyXpA)[https://www.st.com/content/ccc/resource/technical/document/programming_manual/fc/90/c7/17/a1/44/43/89/DM00051352.pdf/files/DM00051352.pdf/jcr:content/translations/en.DM00051352.pdf](https://www.st.com/content/ccc/resource/technical/document/programming_manual/fc/90/c7/17/a1/44/43/89/DM00051352.pdf/files/DM00051352.pdf/jcr:content/translations/en.DM00051352.pdf)


### ABSENT VTOR ON CORTEX M0

The VTOR addresses two main issues:
1. Determining the address of an interrupt when it isn’t relative to 0x00000000
2. Forwarding execution of the interrupt routine to that custom address
  
Sol’n: relocate the VT to [[SRAM]] by software 
- Reserve a block of SRAM in the bootloader file as holding data valid while processor is running
- The user program’s linker script had its SRAM startpoint moved beyond this reserved section
- Set application load address to 0x08004000 in the linker file
- To be able to serve application interrupts, relocate VT (contains IRQ Handlers) to SRAM
- Copy VT from flash (mapped at app start address) to the beginning of the SRAM block (0x20000000 + sram_offset)
- Remap SRAM to address 0x00000000 using __HAL_SYSCFG_REMAPMEMORY_SRAM() macro
- Once “interrupt occurs” the M0 will fetch the IRQ Handler from the relocated VT in SRAM, then jump to execute the interrupt handler located in flash 
- This should all be done at the initialization phase of “the application” 

NOTE: 

The reserved SRAM will only be used by the BL, and the User app will never disturb this memory. In the reserved SRAM, store a pseudo VTOR. 

- The [[RAM]] must be manually initialized before use
- VT is a uint32_t (address size) array of 48 elements (see VT diagram above)
- In main
    - Configure flash prefetch achieved by calling HAL_init(), clock by SYStemClock_Config()
    - Relocate the VT to internal RAM address using for loop to assign the flash addresses of the user application into the address array in SRAM


Q: When reading in a new firmware, how will pseudo VTOR be assigned?

A: Either bootloader resets after new firmware flashed to load pseudo VTOR or I could move the operations to a function and call it after the new firmware is installed before the jump to the new reset handler.

```c
#define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
tempBuf = *((uint32_t*) ram + i++);
tempBuf = SWAP_INT32(tempBuf);
```

### HOST TO MCU TRANSFER

Created python program to connect to Serial COM Port COMx using pyserial library.

Receives a ready flag from the MCU before transferring file data to MCU
- ready flag was being sent but not received
- Added time.sleep delay
- delay allows for only 8B/s which is miles too slow
- increased baudrate from 9600 to 115200 and remove delay
- was a bandaid patch not a fix
- after moving code from receive interrupt callback to main, issues were identified with packet receiving. All delays from host.py and stm32 while loop were removed

From the screenshot below, there is a discrepancy between the manually acquired data file on the left with the proven-to-work data written from stm32 cube on the right.

Will try to flash a binary instead of .ihex but i will need to remove the ‘.’ and ‘\n’ conditions in stm32 code.

Removed the conditions in stm32 code and .ihex still did not work, but the binary file does work.

![](https://lh7-us.googleusercontent.com/b6LMOuZzT3htS6tzSqPvKgXepACO9jp_IaBTJ7527Vv4JBO8Ko8xqVgwSqs0-fdts2w8nEIQrcyuGe_TdXajGYa3kih2ePBYuKS-Ag0QRjmg2oWx1UPuWPvtmKhv4zXhRo-dblBOowbry_QjQE_qAg)  

  
  
### PAGING

Virtual memory management in the bootloader
Load the kernel and other programs in their own virtual address space

### CHECKSUMS AND HAMMING DISTANCE

Parity only checks for single bit errors which, while they are the vast majority of error occurrences, do not identify 100% of error cases. 

One solution is to parity check every byte as opposed to the entire message. This will increase your likelihood of detecting errors but will add a lot of overhead to your transmission. This may be an acceptable tradeoff.

  
#### Overhead vs Chance of error detection

To detect burst errors, take a parity bit for a column of data ( if each byte is on a separate row, and each bit in the the was in a column, the column of bit[0] of every row would be parity checked).

A checksum can be any additional information sent with a message to refer if it has been sent correctly. One thing that can be done is to add the ascii values of each byte in the message together to generate a sum. For an 8-bit word the sum will be a few digits larger, so the MSB that overflow are wrapped to the beginning (LSB sIde) and added together. Then the sum of this number is inverted. This is how the Internet checksum works (except IP packets are 16-bits).

One issue is that summation doesn’t detect extra/ removal of 0s, or ordering issues so it’s not perfect. 

#### STM32 CRC UNIT

STM32F0 programmable on 32-bits

Polynomial coefficients fixed to 0x4C11DB7

CRC calculation unit is used to get a CRC code from a 32-bit data word

In the scope of the EN/IEC 60335-1 standard, they offer a means of verifying the Flash memory integrity

Implement it in hardware for a reduction from 78000 clock cycles to 1200.

For ihex the checksum of the record is = 01h + NOT(xxh + xxh + …) 

The last 2 hex characters are the checksum of the record (not included in the calculation of the record’s checksum obviously).

Use the HAL CRC unit to utilise the microcontrollers hardware accelerator unit. 

Issues:
- each data word is written in the reverse in flash.
- 1 byte from bin file does not equal the equivalent hex or ascii in the CRC calculation thus the two data types cannot be directly calculated and compared. The data type of the two sets being compared must also be the same format.

Sol'n: 
1. restructure the host such that each data packet is generating a checksum value that is being sent along with the data packet to the STM32.  
2. On the STM32 side, each data packet is received along with the checksum value. The received packet is stored in the RAM buffer which is then run through the CRC hardware calculation unit and compared. The generated packet checksum is compared to the received checksum and if it matches, send acknowledgement back to the host to receive the next packet. If the checksum comparison does not match, send a nacknowlegdement to the host and receive the same packet again. 

# BOOTLOADER CODE FLOW

1. Device power up/ on device reset 
	1. When user app is running, interrupt on pin 13 calls NVIC_SystemReset() (soft reset)
2. Booting message 
3. BL polls for PIN_STATE_X (Enter bootloader?)
	1. If PIN_STATE_X is not (No) achieved, JUMP_TO_USR_APP
	2. If PIN_STATE_X is (Yes) achieved, proceed to BL
	3. BL CLI will run   
		1. Mandatory: Erase flash
		2. Mandatory: write a new program to the usr flash space 
		3. Mandatory: JUMP_TO_USR_APP
		4. Option: Lock/ unlock unit - use security key to allow flash contents to modified
		5. Option: image checksum for app corruption
		6. Option: read flash
		7. Option: rwx eeprom
4. Jump to New Program
5. Create bootloader_f4 program
6. Program starts at flash origin
7. Program turns on red LED 
8. De-initialize Peripherals
	1. Deinitialize hardware
	2. Disable interrupts 
9. Jumps to new program 
	1. Set up function pointer which holds the user application reset handler from the 2nd word 
	2. Configure the MSP by reading the value from the base address of Page where user app is stored
	3. Set the new stack pointer using __set_MSP() 
	4. Set VTOR 
	5. Read the address of the stack pointer from the first word of the user program
	6. MSP is the base address, reset handler is the base+4B address
	7. Jump to the user application reset handler 
10. Set f4blink program start flash address to FLASH_USR_ADDR 
11. Enable Interrupts again __enable_irq(); 





