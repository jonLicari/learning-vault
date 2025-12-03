Types of Code Errors:
- Syntax Errors: located by the compiler
- Logic Errors: does not cause compilation failure but doesn't run as intended
- Crashes: Program runs but stops unintentionally 

Debugging takes *time* and *patience*.

## Manually Debugging Code

Common steps that can be used in general:
- Rubber Duck: 
	- talk through your code and the problem you are encountering
	- often by stepping through your code you can uncover errors in program logic or obvious incorrect implementations
	- explaining your problem to your Rubber Duck can help jog your mind on how to approach more thorough debugging
- Output Values at Runtime:
	- print returned values or function arguments at runtime to see if there are deviations from expected values
	- writing comprehensive unit tests can aid in this process as issues can be found faster and more directly
- Print Logs:
	- along the same lines as above, logs can be used to trace the program flow and observe values being produced and passed at different points in the program
	- can also be used for things like memory dumps to observe peripheral hardware

## Common Coding Problems
1. Missing brackets or parentheses
2. Missing or misplaced semi-colon
3. Using assignment operator `=` instead of strict equality operator `==` 
4. Using unsigned integer for loop iteration
5. Exit conditions
6. Not terminating String with null character 
7. Not initializing variables before use
8. Passing pointers to functions
9. Don't write addresses in files
