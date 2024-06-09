# Controller Area Network Bus 

CAN bus is a serial communication protocol used in various applications, particularly in automotive and industrial settings, for real-time control and data exchange between electronic devices. CAN bus is designed to allow multiple electronic control units (ECUs) within a system to communicate with each other without a host computer, enabling distributed control and monitoring.

CAN bus is known for its reliability, high data transfer rates, and ability to operate over long distances. It's commonly used in vehicles for tasks such as engine control, transmission control, anti-lock braking systems (ABS), airbag systems, and more. In industrial applications, CAN bus is used for factory automation, process control, and machinery communication.

CAN (Controller Area Network) is considered robust and reliable due to several key design features:

1. **Differential Signaling**: CAN uses differential signaling, where the information is transmitted as the voltage difference between two wires (CAN_H and CAN_L). This helps in reducing electromagnetic interference (EMI) and noise susceptibility, making CAN less prone to communication errors in noisy environments.
    
2. **Collision Detection and Arbitration**: CAN uses a non-destructive bitwise arbitration mechanism. This means that if two nodes attempt to transmit data simultaneously, the node transmitting the higher-priority message will gain control of the bus. This collision detection and arbitration ensure that data transmission conflicts are resolved efficiently and without data loss.
    
3. **Error Detection and Fault Confinement**: CAN includes mechanisms for error detection and fault confinement. Each CAN message includes a checksum, allowing receiving nodes to detect transmission errors. Additionally, CAN has built-in error-handling mechanisms that enable nodes to detect errors such as bit errors, frame errors, and acknowledgment errors. When errors occur, CAN implements strategies to isolate faulty nodes and maintain the integrity of the network.
    
4. **Message Prioritization**: CAN supports message prioritization through the use of identifiers. Lower identifier values represent higher-priority messages. This allows critical messages to be transmitted with minimal delay, ensuring timely communication for safety-critical systems in automotive and industrial applications.
    
5. **Efficient Frame Structure**: CAN uses a compact frame structure that minimizes overhead. Each CAN frame includes a start-of-frame (SOF) bit, identifier bits, control bits, data bits, and cyclic redundancy check (CRC) bits for error detection. This efficient frame structure maximizes the amount of useful data that can be transmitted over the bus.
    
6. **Bit Synchronization**: CAN ensures precise synchronization between transmitting and receiving nodes through bit-stuffing. Bit-stuffing maintains the proper timing of data bits, ensuring accurate reception even in the presence of clock drift or variations.

Interconnected nodes share information across a network

Electronic Control Units (ECU) can e.g. be the engine control unit, airbags, audio system etc

![](https://lh7-us.googleusercontent.com/hbjv5GRSGLp0QWMoLTV38GBpxkfkwG8IirosZePNeZl_PyYl30yXuOCWaiLqpiDIMaViYJU-Ybnqmvz-HwQmdHNpFgV4iInV0CA29rUEZzrhdYtgh7Lv1Xx_0unuLLJLOq29_T5QlIML_Jq3_sj9Ww)

  

Data Link layer - protocol layer transfers data between nodes on the physical layer 

- In High speed CAN, ISO 11898-1 describes the data link layer
    

  

Physical Layer  - 

- In High speed CAN, ISO 11898-2 describes the physical layer
    

  

![](https://lh7-us.googleusercontent.com/_voYeWHctHi3OPfep5XC1QDilNbYTCdDUPE3lUjLh3NeM02sC8tkjOZfXleDDBUOXhtD44N8m2B82KxFRpZiaIDXDLQzk5szPvu6JpZrk3o4oP6Xk2JppadaN7lUdVTtMUhdOXLEEYDwxQt-NJO8CA)

A CAN network consists of a High and Low line connected by terminating resistors at either end. Nodes can be connected anywhere along the network

Nodes are connected via a 2-wire connection: 1 wire to high line, 1 wire to low line

Any node on the network can communicate with any other node on the network 

Any node can accept and check the message but can choose to reject and ignore the message

CAN frames can use ID to prioritize access to the network without causing interruption of other frames  

  

High Speed CAN

Low Speed CAN 

- Fault tolerant; can work with only one line
    
- Each node has its own CAN termination (terminating resistor)
    

  

CAN Frames

  

Communication occurs in frames

![](https://lh7-us.googleusercontent.com/vg1TSfnaIIaDap2Z4vNjEGWM-pRGb72YTrKjynci6tHCkLFCTVSkKpuaTIWLLU6Ruc6KJndLccUlL-gJc8O8-xWGRhru2cZyMCLZMVKRm7CjazSUatM9-RqneCYF5IpG0U5tFID-O9W8tICBkeqaFQ)

- SOF: The Start of Frame is a 'dominant 0' to tell the other nodes that a CAN node intends to talk
    
- ID: The ID is the frame identifier - lower values have higher priority
    
- RTR: The Remote Transmission Request indicates whether a node sends data or requests dedicated data from another node
    
- Control: The Control contains the Identifier Extension Bit (IDE) which is a 'dominant 0' for 11-bit. It also contains the 4 bit Data Length Code (DLC) that specifies the length of the data bytes to be transmitted (0 to 8 bytes)
    
- Data: The Data contains the data bytes aka payload, which includes CAN signals that can be extracted and decoded for information
    
- CRC: The Cyclic Redundancy Check is used to ensure data integrity
    
- ACK: The ACK slot indicates if the node has acknowledged and received the data correctly
    
- EOF: The EOF marks the end of the CAN frame
    

  

Logging CAN Bus Data

- CAN ID and Data packets are required for logging
    

[Source](https://www.csselectronics.com/screen/page/simple-intro-to-can-bus/language/en)

  

[Vector Learning](https://elearning.vector.com/mod/page/view.php?id=333)

  

[ISO 11898-1](https://www.iso.org/standard/63648.html) describes the CAN protocol

CAN protocol covers the Data Link Layer (MAC — Medium Access Control, LLC — Logical Link Control) and the Physical Layer (PLS — Physical Signaling)

![](https://lh7-us.googleusercontent.com/JnAPPCmAZ5uHanD5VN_VmCt8rY-vQpk_oeYFSbMB5GT8QxnuIx_3XHSgcIYR6fWBhn6DClTLpLovlwGtzCNYG-gOUvOzFCJwnkZv5bf972xylIxcafE0SQmJJq6en6dbdOswTIoeApwGPxFEgDx7LA)

  

CAN controllers handle CAN messages

Full CAN Controller - features object storage

Basic CAN controller - does not feature object storage

CAN High Speed and Low Speed - 

![](https://lh7-us.googleusercontent.com/tAlpNNzksn81ZRuDzGXYYbDH_OjYjtz9S8obXwwNxuqZNIxo4iPMqbaW8uZ1Iwii1OZdCLZ7IC6BvBiONAHKUUXbLVfo7aYdcSWN7Z9tgLpDNOQrizbF4B1zUH0_kp9gQdeC5k5e4SdfWQ09agasMA)

  

CAN Node

![](https://lh7-us.googleusercontent.com/dNE_s0h1J9rAaExsf1iIUTK3-uPwxUlaBlFseO0rC2UVrMXCe3G5nMaSyNAU7JObYDhPi_aqMP8A3A0toMSEm6foF2aMUSMmziD3VoEhb8mnjJTX7W7IfQNE4DpCZBhthqeqzRcNGRDH9UoB8lJyNw)

- Increasing complexity - due to the complexity of the software in modern systems, an OS, network management, and diagnostics are required
    
- AUTOSAR - provides an open source architecture for ECU nodes
    
- AUTOSAR Run-Time Environment - decouples the network from the software components of the application. From bottom to top, it is made up of three levels: Microcontroller Abstraction Layer, ECU Abstraction Layer, Service Layer.
    

  

CAN Interface

- Any ECU that wants to communicate to a CAN network needs to be interfaced with a CAN Controller and CAN Transceiver. The CAN controller fulfills communication functions prescribed by the CAN protocol, which relieves the host considerably.
    
- CAN Transceiver connects the CAN Controller to the physical transmission medium
    
- Usually, these two components are electrically isolated by optical or magnetic decoupling, so that overvoltages on the CAN bus may destroy the CAN transceiver, but the CAN controller and the underlying host are preserved.
    
- Different nodes on the network can receive and send messages at different frequencies from other nodes on the network. Therefore two different CAN controllers have been created - ones with object storage and ones without.
    
- CAN Controllers can be used as
    

- Standalone: MCU treats the CAN Controller as a memory chip (more flexible)
    
- Integrated: on-chip variant has the advantage of requiring less space, and communication between the microcontroller and the CAN controller is faster and more reliable.
    

![](https://lh7-us.googleusercontent.com/0w7lv8Tm_II7GgPWfQWxGR0TPF2mvacPineqkjMFPdcfuRkVrYv-_olwY4WyYzkh5fmLSV3aalxo0qOgDYyKk192sWSkkv7v0TvFQtBmmE2xQh_3lOpIYubYHDWO3YNEzdO6oFfgMMX9EmjBxKWE3A)

CAN Transceiver

Bus Connection

- Previously nodes were connected to the network via discrete circuits, now transceivers are used
    
- Transceivers have 2 lines CANH (line high) and CANL (line low)
    

High/ Low Speed

- High-speed CAN transceivers support data rates up to 1 Mbit/s. 
    
- Low-speed CAN transceivers only support data rates up to 125 kbit/s.
    
- However, low-speed CAN transceivers ensure a fault-tolerant layout of the bus interface (e.g. a failure of one of the two communication lines does not result in total communication failure).
    

Transceiver

- When both output transistors are blocking, both CAN lines assume the same potential (0.5*Vcc), and the differential voltage is zero. 
    
- As soon as both transistors conduct, this produces a differential voltage between the two lines that is a function of the load resistance. 
    
- According to ISO 11898-2 this difference should be 2 Volt. Accordingly, a current of approx. 35 mA flows.
    

Noise

- Common mode choke is used to filter out high frequency emissions 
    

Limitations

- Max number of CAN nodes depends on the performance of the CAN transceivers used and whether it is a high-speed or low-speed CAN network. 
    
- For example, if the TJA1050 high-speed CAN transceiver is used in a high-speed CAN network, up to 110 CAN nodes may be connected in one CAN network per specification.
    

![](https://lh7-us.googleusercontent.com/KQbqrLteP_2cGtuIoFNjfdu2xcbY3JQlbg44BPuMaZHX_zlpewREWNiMUq8GT_TB6hg7mS3g1zG9QzbNjQDuraH9dq4-zGxKar0FTvw0bop7pHaR0Vyr4su3zxEdXBb16rWche8Ucau1RT2kIe1abw)

![](https://lh7-us.googleusercontent.com/yNgVw7TkRn8lrKJA-nUATCm7uBq0ORE3IT1zC426uREXKT0y8c8kyZ4kLZ8X7mAX-pAZ6dwvH8Toy-UwlAJQKEmF6jqYV_UNF5-pabZQCTPT65ztXCC7-W-1b6JFyQDyAe9DcuQJalkKnH5AsW_-sQ)

CAN Bus

Differential Signals

- [https://www.apogeeinstruments.com/differential-vs-single-ended-measurements/](https://www.apogeeinstruments.com/differential-vs-single-ended-measurements/)
    
- Differential is taken between two lines as a “floating” voltage with no reference to ground
    

  

 Continue from https://elearning.vector.com/mod/page/view.php?id=340

**