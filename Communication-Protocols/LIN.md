# Local Interconnect Network

# LIN Bus 

  

![](https://lh7-us.googleusercontent.com/HnMBTDHGbUy1YfwKs-ZEAdIEG2nbGgx5T8_xZhEAkC1Co8DkJXcOFn8vLo_46CxGLwX9-Is2kQ0VqEmlq5uWYLl6do3SlWEzYeQjahuFyq7IgGZhmJbBJLptJ6zfcrCzon1h-FtA8wTRGeLZAr1Wjg)

## How It Works

- The LIN master node interfaces a LIN cluster to the CAN bus
- The master node has a single TX/ RX line which connects to the LIN bus
- All slave nodes connect to the same single wire 12V LIN bus
- All nodes in LIN cluster share a common ground 
- Every message sent to the LIN bus is received by every node on the bus
	- CAN to LIN messaging ?
	- LIN to CAN messaging? 
	- Master can request information from a node, and the respective node can then access the bus and send the required information
    

## LIN Messages

- A LIN bus message frame consists of a Header and a Response
- Master transmits a header to the LIN bus which triggers a response from a slave
- The header message
	- Begins with a “break” which is minimum 13+1 bits but in practice 18+2 bits
		- acts as a notice to the nodes on the bus that a frame is starting
	- Sync field (8 bits) usually always expressed as 01010101
		- Used to synchronize nodes by reading the rising/ falling edges and thus, dynamically tune to the master nodes baud rate
	- Identifier field is comprised of 6 bits + 2 parity bits
		- act as message ID and also identifies the slave being communicated with
- The slave can then
	- Ignore the message if it cannot contribute to the required information
    - Listen to data published by another slave node
    - Publish its own data to the bus in response to the header
 - Only one node is polled at a time
    - avoids risk of collisions
    - removes need for bus arbitration  
- The response message
    - Data field
	    - Can be 2, 4, or 8 bytes long depending on the ID range (LIN 2.0+)
	    - ID 0-31: 2 bytes 
	    - ID 32-47: 4 bytes 
	    - ID 48-63: 8 bytes
	- LIN signals are packed within the data bytes
- Because the bus is just a single line of full duplex communication, it is low performing and can experience delays
	- To offset these delays, inter byte space, or, a small time delay, can be added between bytes to ensure that a message is properly received with no corruption
	- Between the header and response, ‘response space' can be added to allow slave nodes sufficient time to react to the master's header 
  

![](https://lh7-us.googleusercontent.com/IXXxcI4DYvr1hVDgmKQh8MrttHHxsjXgVChOx_Upl7n1AyObduhr9OC--Kg6KWe-2-eYbEJUpkMs1vVGxAjrnhkrj5bfGbQ_qXw3fiWMvA9gdCNJW4Hb_7KCMBtnV1sY9CTlmYxzHS3ZfGFkay2GvA)

## LIN Frame Types

There are 6 types of LIN frames:
1. Unconditional frames
	1. Default frame of communication; master sends header to request data from specific slave and the specified slave responds accordingly
2. Event trigger 
    1. Master polls multiple slaves 
    2. A slave responds if its data has been updated, with its protected ID in the 1st data byte
    3. If multiple slaves responds, a collision occurs on the bus and the master defaults to the unconditional frames
3. Sporadic frames
    1. Only sent by master if it knows that a specified slave has updated information
    2. The master “acts as a slave” and responds to its own header
    3. This provides slave nodes with dynamic info
4. Diagnostic frames
    1. IDs 60-61 are used for reading diagnostics from master or slaves
	    1. ID 60 Master request 
	    2. ID 61 Slave response
    2. Frames always contain 8 bytes   
5. User Defined frames
    1. ID 62 is a user defined frame which can contain any user specified information
6. Reserved Frames
    1. ID 63 Should not be used in LIN 2.0 networks    

## LIN Node Configuration File (NCF)

This file details the capabilities of the LIN node.

This file is used to configure all nodes; master nodes and slave nodes.

## LIN Description File (LDF)

A cluster of node NCFs can be combined into a description file.

The master then sets up and manages the cluster based on the LDF (e.g. time scheduling headers).

LIN bus nodes can be reconfigured using the diagnostic frames.

Similar to Device Configuration Files in CANopen

![](https://lh7-us.googleusercontent.com/g3P-gckFwLA2I1BIBt4_YKHTacOAg16adEWbmByDU58CLLwUHIUtVx2X66t5hWl-iuhEvKC5Htec3eAlUUWV9r3j6ZJ6op8OZV4eW3SubhfMGHVrmUD7iozXqnFGN9on_Qh7NeieqFUXVVtx0D3zeQ)

## LIN Communication

UART was originally used between nodes on the LIN bus, but a fault free UART method was difficult to achieve so SCI (Serial Communication Interface) was adopted instead.

The microcontroller transmits bit frames, starting with the dominant start bit. This synchronizes all receivers on the bus, followed by the least significant bit to most significant bit, then a stop bit. This constitutes one SCI frame, and a LIN message is composed of multiple SCI frames.

### RPi as LIN Master

  

## Miscellaneous

- Lower performance and reliability than CAN but also lower cost
- Used for secondary vehicle functions that are not performance critical (windows, wipers, air conditioning, etc.)
- Based on a single wire (+ground) with 1-20 kbit/s max 40m bus length
- Uses time triggered scheduling with guaranteed latency time
- Operates on 12V, while the physical layer is based on [ISO 9141](https://weber.instructure.com/courses/181471/pages/iso-9141)
- In ISO 9141, each bit of information is 96us long and is voltage represents 0 or 1
- A Data-Link Connector (DLC) allows a scan tool to be connected to the serial line
- Supports sleep mode and wake up
  

[https://www.youtube.com/watch?v=hjuO1UjoQU0](https://www.youtube.com/watch?v=hjuO1UjoQU0)

[https://www.youtube.com/watch?v=Ewph2jxn8oU](https://www.youtube.com/watch?v=Ewph2jxn8oU)
