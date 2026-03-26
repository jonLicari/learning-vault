The microcontroller is supervisory in nature and sends commands to the [[FPGA Layer]] which is the engine of this project.

The MCU acts as the conductor and communicator.

A protocol layer is required to communicate data between the FPGA and MCU. This layer needs to be clearly defined as critical data needed for performance and recovery will need to be passed seamlessly.
## Business Requirements

1. Configuration
2. Control/ Orchestration
3. Adaptability

#### Configuration
- Define Motor profiles
	- Step, Ramp, Sine, Arbitrary
- Send 
	- Target speed/ position
- Parameter Management
	- PID gains
	- Calibration constants
- Telemetry / Logging
	- Speed, position
	- Current, torque estimate
	- Effective error
	- Buffer stream to host PC
- Local GUI 
- System Coordination
	- Initialize FPGA, sensors
	- FPGA fault detection & recovery
	- Mode switching
## Technical Requirements

## Protocol Layer

This needs to encompass - what info is being communicated between the MCU and FPGA?

We can put together a list from the Business Requirements:
- Performance
	- Motor profile (step, ramp, sine, arbitrary)
	- Target speed
	- Target position
	- PID gains (kp, ki, kd)
	- Error 
	- Calibration constants
	- Current estimate
	- Torque estimate
- Telemetry
	- FPGA fault flags

Communication can be:
- SPI (common for FPGA <> MCU)
- UART (simpler, slower)
- Memory-mapped (if tightly coupled)

Timing separation (important)
- FPGA loop: 10–100 kHz
- MCU loop: 10–100 Hz
- Implication:
	- MCU does not sit in the control loop
	- It only updates parameters asynchronously

| Feature       | SPI         | UART       | Memory-Mapped |
| ------------- | ----------- | ---------- | ------------- |
| Determinism   | High        | Low        | Very High     |
| Latency       | Low         | Medium     | Very Low      |
| Bandwidth     | Medium–High | Low–Medium | Very High     |
| Complexity    | Medium      | Low        | High          |
| Debuggability | Medium      | High       | Low           |
| Pin count     | Low         | Very Low   | High          |
Going to go with a SPI interface:
- Master drives clock giving high determinism
- Low latency
- Less tightly coupled to hardware
## Minimal viable firmware scope (good starting point)

### FPGA (v1)

- Encoder read
- Velocity calculation
- Basic PID speed control
- PWM output

### MCU (v1)

- Send constant target speed
- Read telemetry over UART/SPI
- Print to terminal