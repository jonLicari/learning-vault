In school, we are mostly graded on our ability to "make the program work".  
This allows for slimmed down programs that get straight to the point.  
But this almost always assumes a "well behaved user" is providing input.  
  
This course identifies techniques to keep your data secure and protect your software from malicious attacks and undefined behaviours .  
  
Defensive coding techniques add more overhead to your program but greatly reduce the amount of vulnerabilities that can be used to exploit your software such as buffer overflows and code injection flaws.

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


## Topics
- [[#Miscellaneous|Miscellaneous]]
- [[#Input Validation|Input Validation]]
- [[#String Management|String Management]]
- [[#Issues with Pointers|Issues with Pointers]]
### Miscellaneous
#### Formatting Preprocessor Directives

The code below shows poor choice of preprocessor directives for function parameters. There is a big issue with readability as well as type-safety. More problems will occur if `set_pixel_data()` is defined as a macro.
```C
#include <stdio.h>

#define GRAYSCALE  

void set_pixel_data(int depth, void *p) { }

int main() {
	struct pixel_gray { char m; } pg;
	struct pixel_color { char r; char g; char b; } pc;

	set_pixel_data(
#ifdef GRAYSCALE
		1,&pg
#else
		3,&pc
#endif
	);

return(0);
}
```

Improve code by moving the entire function signature inside the preprocessor below
```C
#include <stdio.h>

#define GRAYSCALE

void set_pixel_data(int depth, void *p) { }

int main()
{
	struct pixel_gray { char m; } pg;
	struct pixel_color { char r; char g; char b; } pc;

#ifdef GRAYSCALE
	set_pixel_data( 1, &pg);
#else
	set_pixel_data( 3, &pc);
#endif

	return(0);
}
```

#### Using Assignment Operator as Condition
The assignment of `a=b` when used as a boolean condition avoids a compiler warning and thus can go unnoticed. Variable `a` will take the value of `b` and then the result of this operation, which is the original value of `b`, is what the condition evaluates as a boolean.

```C
#include <stdio.h>

int main()
{
	int a,b;

	b = -8;

	if( (a=b) )
		puts("Value assigned");
	else
		puts("Value is zero");

	return(0);
}
```
Depending on what you are trying to evaluate some techniques can be used to avoid undesirable evaluations.

If you wanted to evaluate the range of the variable `a`, ensure you are testing not the assignment, but rather the range of the value.
```C
#include <stdio.h>

int main()
{
	int a,b;

	b = -8;

	/* Assign `b` to `a` and test the
	   result (value of `b`) with zero */
	/*** DO NOT USE `a==b` HERE! ***/
	if( (a=b) != 0 )
		puts("Value assigned");
	else
		puts("Value is zero");

	return(0);
}

```

### Input Validation

### String Management

### Issues with Pointers
