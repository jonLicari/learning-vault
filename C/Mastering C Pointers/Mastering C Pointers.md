# INTRODUCTION 
All information herein is 
A pointer is:
- a variable that holds a memory location
- the address of another variable
- the address of a chunk of memory

# 1.0 Pointer Basics
C is a mid level language featuring useful concepts like pointers.
Pointers can be effectively used to examine and manipulate data.

## 1.1 Understanding Pointers
Rules:
1. Pointer declared as specific data type (int, char, etc.)
2. Pointer must be initialized before it's used 

Pointer Dual Nature
- Use * operator to DECLARE pointer: `char *ptr`;
- Pointer variable is used with or without the `*` operator
- `ptr` refers to an address
- `*ptr` refers to the value stored at the address

See 01-01-pointer1.c

## 1.2 C Language Pointer Tools
1. Operators
    Unary * (pointer)
    Unary & (address-of)
    sizeof (# of bytes taken up in storage)

2. Symbolic Constants
    NULL, a ptr not assigned to any specific address
    size_t, represents a byte count

The operators help examine a variable.
Data type, variable name, value, & (address in memory), sizeof (size of memory occupied)

See 01-02-examine1.c

## 1.3 Using Pointers as Function Arguments
Rule: Always test the pointer returned from a function 
```c
FILE *ptr;
ptr = fopen("fileName.c", "r");

if (ptr == NULL) // exit upon a function failure
{
    fprintf(stderr, "Unable to open file\n");
    exit(1);
}
puts("File opened!");
```
Pointer Function:
```C
int *iptr(void)
{
    static int a = 53;
    return(&a); // returns address of variable a
}

int main()
{
    int *x;
    x = iptr(); // Stores address of a in pointer x

    if (ptr == NULL) // exit upon a function failure
    {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }
    puts("File opened!");

    return 0;
}
```
malloc():
```C
int main()
{
    void *chunk; // pointer of untyped memory

    chunk = malloc(1024); // allocate 1024 bytes of memory

    if (chunk == NULL) // test if allocation was successful
    {
        puts("Memory allocation failed!");
    } 
}
```
## 1.4 Challenge: Obtain an address
- output the address of variables a and b
- %p to output address
- p is for pointer
- initialize pointers x and y to their corresponding variables
- output the addresses stored in each pointer variable

```C
/*
- output the address of variables a and b
- %p to output address
- p is for pointer
- initialize pointers x and y to their corresponding variables
- output the addresses stored in each pointer variable
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    char *x;

    int b;
    int *y;

    // Initialize pointers
    x = &a;
    y = &b;

    // Output addesses of each variable
    printf("Address of var a: %p\n", &a);
    printf("Address of var b: %p\n", &b);

    // Output addresses stored in each pointer 
    printf("Address stored in x: %p\n", x);
    printf("Address stored in y: %p\n", y);
    
    return 0;
}
```

Output:
```
> Address of var a: 0061FEC7
  Address of var b: 0061FEC0
  Address of var a: 0061FEC7
  Address of var b: 0061FEC0
```

# 2.0 Memory Allocation and Buffers
## 2.1 Comparing Arrays and Pointers
Output the values stored in the array:
```C
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x;

	for( x=0; x<5; x++ )
		printf("%d",a[x]); // prints values of array

	return(0);
}
```

Output:
```
> 11 22 33 44 55
```
Output the addresses of each index in the array:
```C
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x;

	for( x=0; x<5; x++ )
		printf("%d\n",&a[x]); // prints address of each index

	return(0);
}
```

Output:
```
> 0061FEB8
  0061FEBC
  0061FEC0
  0061FEC4
  0061FEC8
```
Use pointer to traverse an array:
```C
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x,*p;

	p = a; // assign start address of array to pointer p
	for( x=0; x<5; x++ )
	{
		printf("%p\n",p); // prints out the address of each index
		p++; // increment pointer p to access next array index
	}

	return(0);
}
```
Output:
```
> 0061FEB8
  0061FEBC
  0061FEC0
  0061FEC4
  0061FEC8
```
```C
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x,*p;

	p = a; // assign start address of array to pointer p
	for( x = 0; x < 5; x++ )
	{
		printf("%d ", *p); // prints the value of each array index
		p++; // increment pointer p to access next array index
	}

	return(0);
}
```
Output:
```
> 11 22 33 44 55
```

In the previous examples, once you increment pointer p, you have lost the base address and must always be aware of how many increments have been performed in order to get back to the base. 
It's important not to lose the base address, especially when dealing with dynamically allocated memory.

Preferred method is to keep the base and offset separate so you never modify the base:

```C
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x;
	int * const p = a; // const pointer so address never changes
	for( x = 0; x < 5; x++ )
	{
		printf("%d\n", *(p+x) ); // output value stored at address (p + x)
	}

	return(0);
}
```

## 2.2 Allocating Storage

- Arrays work for many types of storage
- To dynamically allocate storage, use a pointer
- The pointer holds the buffer's address

`malloc()` returns the buffer's address, NULL if unable to allocate the memory.

> [!TIP]
> Always test the allocated buffer before use!

malloc() implementation:

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *storage; // declare storage buffer pointer
    // allocate 16 char size units 
	storage = (char *)malloc( sizeof(char) * 16 ); // typecast to char pointer 
	if( storage==NULL ) // test if allocation was successful
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	else
	{
		puts("Memory allocated");
	}

	return(0);
}
```

When allocating memory for a string buffer, always include room for the terminating null character:

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* 15 characters are required for input */
	char *input;

    // Allocate memory for 15 characters +1 for the null terminating character
	input = (char *)malloc( sizeof(char) * 15 + 1 );
	if( input==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	else
	{
		puts("15 characters are available for input");
	}

	return(0);
}
```
## 2.3 Exploring Allocation Functions
- **malloc()** allocates uninitialized storage
- **calloc()** allocates and initializes storage (numeric storage set to 0, char type set to null characters)
- **realloc()** dynamically resizes an existed buffer. Contents of the old buffer are copied to the new buffer. An existing buffer can be resized by specifying its address both as an argument and as the return value. realloc() doesn't initialize storage
- **free()** frees up allocated memory to recover the memory or storage. Afterr using free(), set a pointer'v value to NULL. Not necessary to free memory when program quits because this is done autmatically. Only free when the buffer is no longer needed but the program must still run. 

Allocation example:
```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int x;

	/* use malloc to set the buffer size to
	   store five integers */
	storage = (int *)malloc( sizeof(int) * 5);
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");
	/* initialize and output the values */
	for( x=0; x<5; x++ )
	{
		*(storage+x) = (x+1) * 11;
		printf("%d ",*(storage+x) );
	}

	/* now increase the buffer size by two
	   integer values */
	storage = (int *)realloc(storage, sizeof(int) * 7 );
	if( storage==NULL )
	{
		fprintf(stderr,"Reallocation failed\n");
		exit(1);
	}
	puts("\nBuffer re-sized: ");
	/* add the final two values */
	*(storage+5) = 66; 
	*(storage+6) = 77; 
	/* output the results */
	for( x=0; x<7; x++ )
	{
		printf("%d ",*(storage+x) );
	}

	return(0);
}
> Output:
Memory allocated
11 22 33 44 55 
Buffer re-sized: 
11 22 33 44 55 66 77 
```
Memory free() usage:
```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int x;

	/* the malloc() function allocates the pointer */
	storage = (int *)malloc( sizeof(int) * 5);
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");
	/* the pointer is allocated, but the storage
	   locations haven't been initialized */
	for( x=0; x<5; x++ )
		printf("%d\n",*(storage+x) );

	/* release the allocated memory */
	free(storage);
	storage = NULL;
	puts("Memory freed");
	/* it's unnecessary to free() storage before
	   a program quits, but if you plan on re-
	   using the pointer, or it's allocated within
	   a function, do free it and assign the
	   pointer to the NULL symbolic constant,
	   as shown here */

	return(0);
}
> Output:
Memory allocated
13970984
13959360
1701603654
947398771
1128081718
Memory freed
```
## 2.4 Accessing the Buffer
Pointer math:
- Mathematically manipulating a pointer alters its address by te data type size
- Incrementing integer pointer *p* doesn't add one to the address

    *p++;* // adds one integer-size chunk to the address  
    After incerementing, *p* references the next integer in memory

    Add one to character pointer *c*; the next character is referenced  
    *c+1;* // the second character in the buffer

    Add one to double pointer *d*; the next double value is referenced  
    *d+4;* // the fifth double integer value is referenced

### Avoiding Buffer Overruns 
- It's possible to reference a value beyond allocated memory
- Ensure overruns are avoided as compilers will not pick up these issues
- [sol'n] Define a constant to be the size of the array or allocated buffer
    - This constant will be the loop exit condition value when accessing the buffer

## 2.5 Working with Poiinters in Structures

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct person {
		char *name;
		int *age;
	} my;
	char n[] = "Jennifer";

	/* allocate storage for the age integer */
	my.age = (int *)malloc( sizeof(int) * 1);
	if( my.age==NULL )
	{
		fprintf(stderr,"Allocation error\n");
		exit(1);
	}
	/* assign value; the asterisk is required, but the
	   standard dot operator is used */
	*my.age = 26;

	/* because 'n' is an array and 'my.name' is a pointer,
	   you can just copy the base address
	   again, the dot operator is used */
	my.name = n;

	/* output results
	   'my.name' is a character pointer and the
	   asterisk isn't required
	   the asterisk is required for 'my.age' */
	printf("%s is %d years old\n",
			my.name,
			*my.age
		  );

	return(0);
}
> Output: Jennifer is 26 years old
```
## 2.6 Creating Structure Pointers
When a pointer references a structure, the member operator (.) changes to the (->) operator
```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct person {
		char name[32];
		int age;
	} president = {
		"George Washington",
		59
	};
	struct person *first;

	/* output regular structure */
	printf("%s is %d years old\n",
			president.name,
			president.age
		 );

	/* assign structure pointer */
	first = &president;

	/* output pointer reference */
	printf("%s is %d years old\n",
			first->name,
			first->age
		 );

	return(0);
}
```
Example:
- pointer structure *first* has its memory allocated at line 13
- *malloc()* sets aside memory for one person-sized structure
- the function itself is typecast to a person structure pointer
- this allocation must take place before the members of the structure are accessed
- this structure is a pointer, therefore the -> operator is used (ln 21, 22, 24) 
- **Note:** in the scanf statement, the & is still required
- structure member age is an integer value and its address must be passed to *scanf()*
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char name[32];
		int age;
	} *first;

	/* allocate the structure's memory */
	first = (struct person *)malloc( sizeof(struct person) * 1);
	if( first==NULL )
	{
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}

	/* assign structure members */
	strcpy(first->name,"George Washington");
	printf("How old was %s? ",first->name);
	/* first->age is still an integer variable */
	scanf("%d",&first->age);

	/* output results */
	printf("%s was %d years old\n",
			first->name,
			first->age
		 );

	return(0);
}
```
This example shows how to deal with a pointer allocated as a structure with pointers as members:
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char *name;
		int *age;
	} *first;

	/* allocate the structure's memory */
	first = (struct person *)malloc( sizeof(struct person) * 1);
	if( first==NULL )
	{
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}
	/* allocate structure members */
	first->name = (char *)malloc( sizeof(char) * 32);
	first->age = (int *)malloc( sizeof(int) * 1);
	if( first->name==NULL || first->age==NULL )
	{
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}

	/* assign structure members */
    // -> used bc structure itself is allocated as a pointer
	strcpy(first->name,"George Washington"); 
	printf("How old was %s? ",first->name);
	/* first->age is still an integer variable */
	scanf("%d",first->age); // member age is a pointer, thus first->age is an address

	/* output results */
	printf("%s was %d years old\n",
			first->name,
			*first->age // member age is a pointer, thus *first->age is the value
		 );
/*
The addressing of member age in the scanf() and printf() are necessary regardless 
of if the structure is allocated as a pointer or declared outright.
A pointer member of a structure is stll an address and it must be treated as such.
*/
	return(0);
}
```
## 2.7 Saving Pointers and Buffers
When saving a buffer to a file, ensure you are saving the data and not the pointer.
```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base,x;
	FILE *fp;

	/* allocate storage */
	base = (int *)malloc( sizeof(int) * 10 );
	if( base==NULL )
	{
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* fill storage */
	for( x=0; x<10; x++ )
	{
		*(base+x) = x * 100;
	}
	puts("Memory allocated and filled");

	/* open the file */
	fp = fopen("integers.dat","w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create file\n");
		exit(1);
	}

	/* save the buffer */
    // Ensure you don't enter ...sizeof(base), 1,...
    // 
	fwrite(base,sizeof(int),10,fp);
	puts("Data saved");

	/* close the file */
	fclose(fp);

	return(0);
}
```
NOTE: 
- Do **NOT** save a structure to a file when it has pointer members even when they're allocated
- If you want to save structured data, the member shouldn't be a pointer, but rather an array
- Otherwise, the pointer's address is saved, not its data

## 2.8 Challenge
Saving a Record:
- The structure is allocated as a pointer  
- Contains two members: string name, integer age
- Prompt user to provide both inputs
- Write the structure to the file save.dat

Reading a Record:
- Read data written by the first program
- Use the same structure definition
- Read data from save.dat into the structure 
- Output the structure's data

Saving a Record Program:
```C

```
Reading a Record Program:
```C
```

# 3.0 Linked Lists
## 3.1 Understanding Linked Lists
Linked List: 
- dynamic storage involving structures and pointers
- members describe data
- one structure member is a pointer
- the pointer references the next structure in the list

Beyond the pointer member in the list, three pointer variables help manage the list:
- Base: references base address of the starting structure in the list
- Current: references address of current structure in the list
- Next: references address of the next structure in the list  

For each Structure added:
- The structure to be added is allocated
- Its address is stored in the preceeding structure's linking member or kept as the base of the entire list
- This added structure's linking member is set to NULL indicating it's the last structure in the list

Advantages of Linked Lists over Arrays:
- LL is dynamic; structures can be added or removed whereas arrays are of fixed size
- LL can link complex data structures

## 3.2 Implementing a Linked List
See implementations outlined in exercises Chapter 03 section 02

## 3.3 Removing Structures
Structures are managed by manipulating their pointers.

To remove a structure:
- the previous item skips over it to reference the following item
```C
current->next = (current->next)->next;
```
- the structure is then unlinked and its memory freed
	- a new pointer member must be included in the struct
	- the new pointer stores the pointer to the structure to be removed
	```C
	// temp pointer stores the current->next pointer
	temp = current->next;
	// refocus the next pointer to reference structure 4 instead of 3
	current->next = temp->next;
	// free storage
	free(temp);
	```
	- the base pointer needs to be handled with care else risk losing the whole list
	- save base pointer in temporary pointer variable
	```C
	// save first structure
	temp = first;
	// set second structure as the new base
	first = first->next;
	// free first structure memory
	free(temp);

## 3.4 Adding Structures
Update the pointer of the previous structure to point to the new one.

To add a structure to the list:
- Allocate the new structure 
- Copy the previous structures next member into the new structure 
- change the previous structures next member to reference the new structure
- if added structure is the first element, it references the previous first element 
- if added structure is the last element, it references null

## 3.5 Double Linked List
Each structure will feature both a "next" and "previous" pointer address.

This allows each structure to traverse to both the following or preceeding structure.

## 3.6 Saving a Linked List
Things to remember:
- WARNING: fwrite function assumes all memory chunks are sequential
	- Allocated memory is NOT always sequential 
		- Struct A location: 0x64AAD0
		- Struct B location: 0x64AAD4
		- Struct C location: 0x64AE2C 
- the data stored in the linked list is saved, not the linked list itself
- when reading from file, a new linked list must be allocated and populated with data
- pointer addresses will not be the same on different machines 
- thus useless to save pointer addresses, and only essential to save the data itself

# 4.0 Advanced and Crazy Pointers
## 4.1 Understanding Pointers to Pointers
- An array of pointers is a collection of addresses
- As with all pointers, addresses must be initialized to the location of some variable
- The pointer to pointers stores the location of the array of pointers is stored
- Refer to the Pointer Reference Cheat Sheet 

## 4.2 Sending Pointer to a Function
- Always pass the address as the parameter to the function else risk losing the address
	- [Confirm] when switching from main to function, the stack frees allocated memory from main to be used as memory for the function it is servicing

## 4.3 Sorting Pointers
See weekdays sorting expample 04_03

- Running a sorting algorithm on a set of strings is highly demanding as each character in each string needs to be handled. Not good.
- Making the strings pointers allows one to sort the memory addresses instead of the characters
- Thus, sorting a set of pointers is much less demanding and better for performance
- these are pointers being swapped, not strings being assigned

## 4.4 Managing Memory
memcpy() and memmove():
- copy or move a chunk of memory, raw bytes
- the memory location and address, or pointer, or the name of an array is used as the source/ destination
- the memory contents are actually copied or moved, not simply referenced

## 4.5 Function Pointers 
```C
// Function pointer prototype
void (*fp) (int param);
```