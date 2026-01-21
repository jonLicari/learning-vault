[[Threads]]

[[Event Queue]]

## Test Frameworks

MBED OS already has built-in test frameworks: GreenTea and IceTea.

GreenTea and IceTea are testing frameworks and tools that are part of the Mbed OS ecosystem. They are designed to assist in the testing and validation of Mbed OS-based embedded systems.

1. **[[GreenTea]]**:

   - **GreenTea** is a testing framework used for performing automated testing on Mbed OS targets. It provides a way to create test scripts that can be executed on embedded devices running Mbed OS.

   - Test cases in GreenTea are typically written in Python and target specific Mbed-enabled hardware platforms. These test scripts interact with the target hardware and verify that the Mbed OS features and functionalities are working correctly on the embedded device.

   - GreenTea also provides a test harness for handling the communication between the host PC and the embedded device, allowing for automated testing and reporting of test results.

2. **IceTea**:

   - **IceTea** is a tool used for automating and managing test campaigns in Mbed OS. It provides a higher-level interface for organizing and running multiple test cases and test suites across different Mbed OS platforms and targets.

   - IceTea makes it easier to coordinate and manage test campaigns that may involve running a series of tests on multiple embedded devices, collecting test results, and generating reports.

Both GreenTea and IceTea are essential tools for developers working on Mbed OS projects, especially when they need to validate the functionality of their code on embedded devices. These tools help ensure that Mbed OS operates as expected on various hardware platforms, and they assist in automating the testing process, which is crucial in the embedded systems development workflow.