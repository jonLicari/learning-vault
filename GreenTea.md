To write a test case for a simple function that adds two numbers and set up GreenTea to execute the test from the Mbed CLI, follow these steps:

1. **Create Your Test Case File**:

   First, create a Python test case file. Let's call it `add_test.py`. In this file, you'll define your test case and the code to test. Here's a simple example:

   ```python
   import utest

   # Your function to test
   def add_numbers(a, b):
       return a + b

   # Define a test case
   def test_addition():
       result = add_numbers(2, 3)
       utest.assert_equal(result, 5)

   # Create a test suite
   test_suite = utest.TestSuite()
   test_suite.add(test_addition)

   # Run the test suite
   utest.default_reporter(test_suite)
   ```

   In this example, we have a function `add_numbers` that adds two numbers, and a test case `test_addition` that checks if the function returns the correct result.

2. **Set Up Your GreenTea Configuration**:

   GreenTea uses JSON configuration files to specify the test environment and test target. Create a `mbed_app.json` file in your project directory, and specify the GreenTea configuration within it. Here's a simple example:

   ```json
   {
       "target_overrides": {
           "*": {
               "target.tests_add": ["add_test.py"]
           }
       }
   }
   ```

   This configuration tells Mbed OS to include the `add_test.py` test script when building your project.

3. **Build Your Project with Mbed CLI**:

   Use the Mbed CLI to build your project:

   ```shell
   mbed compile -m YOUR_TARGET -t YOUR_TOOLCHAIN
   ```

   Replace `YOUR_TARGET` with your target platform (e.g., K64F) and `YOUR_TOOLCHAIN` with your toolchain (e.g., GCC_ARM).

4. **Run Your Tests with GreenTea**:

   After building your project, you can run the tests using GreenTea:

   ```shell
   mbed test -t YOUR_TOOLCHAIN -m YOUR_TARGET
   ```

   This command will flash your Mbed-enabled device with the test binary and execute the test cases. GreenTea will handle the test execution and report the results.

This is a basic example of setting up GreenTea to execute a test case from the Mbed CLI. You can expand on this by creating more complex test cases, organizing them into test suites, and using the features provided by GreenTea and Mbed OS for advanced testing and automation.