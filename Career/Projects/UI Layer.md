Perfect—getting clarity on telemetry, inputs/outputs, and which parameters are mutable versus immutable is critical for **both initial implementation and future upgrades**. Here’s a concise breakdown for your FPGA+MCU adaptive motor control project.

---

# **1. Key Data to Monitor / Telemetry**

The telemetry is **all the data you care about in real time to evaluate system performance**. For this project:

| Telemetry                      | Purpose / Notes                                                                           |
| ------------------------------ | ----------------------------------------------------------------------------------------- |
| Motor Speed                    | Core performance metric; allows verification of closed-loop control.                      |
| Motor Position                 | Useful for profiling motion and detecting drift or jitter.                                |
| PWM Duty Cycle                 | Shows what FPGA is commanding the motor; diagnostic for control tuning.                   |
| Estimated Torque / Load        | Derived from current sensing or back-EMF; demonstrates FPGA handling variable resistance. |
| Error Signal (Target – Actual) | Useful to visualize control accuracy.                                                     |
| Adaptive Control Parameters    | Optional: shows PID gain adjustments or gain-scheduled outputs in real time.              |
| System Status Flags            | Start/stop, fault indicators, saturation, or over-current events.                         |

**Optional Advanced Telemetry** (can add later):

* Encoder velocity derivatives (acceleration)
* Camera-based visual confirmation of wheel position
* Logging of mechanical load or friction setting for repeatability

---

# **2. Inputs and Outputs**

### **Inputs (to FPGA / Control Loop)**

* Target motor speed or position (from MCU/UI)
* Sensor feedback:

  * Encoder pulses / position
  * Optional: camera input or vision marker
  * Optional: motor current/back-EMF signal
* Adaptive control parameters (from MCU/UI)
* Start/stop or enable commands
* Environmental / test parameters (optional, like simulated load level)

### **Outputs (from FPGA / MCU)**

* PWM signals to motor driver (FPGA)
* Telemetry stream to MCU:

  * Motor speed/position
  * Estimated torque/load
  * Error signal
  * Adaptive gain / PID values (if applicable)
  * Status flags

---

# **3. Mutable vs Immutable Parameters**

### **Mutable Parameters**

These can be adjusted during operation via UI/MCU without restarting or reprogramming:

* Target speed or position
* PID gains (P/I/D)
* Adaptive control parameters (e.g., gain scheduling factors)
* Start/stop or enable commands
* Motion profile parameters (acceleration/deceleration ramps)

### **Immutable Parameters**

These are typically **fixed at design time** or FPGA synthesis and not meant to change in real time:

* FPGA clock frequency or PWM resolution
* Maximum motor voltage/current limits (safety)
* Encoder counts per revolution or sensor sampling rate
* Fixed FPGA module configurations (e.g., bit widths for PID registers)
* Communication protocol definitions between MCU and FPGA (register map, data packet format)

---

# **4. Practical Notes for Implementation**

1. **Standardize register map** for all mutable parameters so the UI and MCU don’t need to know FPGA internals.
2. **Design telemetry as packets** that include timestamp + values, to make it easily parsed by Python, web UI, or future OLED dashboard.
3. **Prioritize real-time data** (speed, torque, PWM) for demonstration; others can be sampled at slower rates if needed.
4. **Separate mutable and immutable clearly in software** so you don’t accidentally overwrite safety-critical constants.

