Weaknesses of the C language:
1. weak data typing
2. primitive data types
3. integer values can switch between positive and negative
4. boolean types are implemented in code
5. strings can be created without proper termination
6. Memory management overseen by programmer not the language
7. easy to access memory beyond allocated chunk
8. buffers can overflow easily
9. undefined behaviours

To write secure code, always code defensively!

Bad actors are always looking to exploit buffer overflows and input routines to access and manipulate the program.

### Defensive Coding
- Buffer or array sizes should be known
- Store the size value and test it to ensure no overflow occurs
- Validate input and reject invalid values
- Assume malicious actors will interact with your code
- Document code, especially after code is in working stable state
	- describe ranges, program logic, limits, and known issues
	- consider comments as notes to your future self
	- explain alternative methods or solutions and why you opted for the current implementation
	- use a changelog
