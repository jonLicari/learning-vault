#include <stdio.h>

int main()
{
	char a;

	/* initialize variables! */
	a = 'A';

	printf("Value of variable 'a': %c\n",a);
	printf("Address of variable 'a': %p\n",&a);

	// sizeof(a) finds the # of bytes variable a uses in memory
	// %lu is long unsigned integer
	printf("Size of variable 'a': %lu\n",sizeof(a));

	return(0);
}
