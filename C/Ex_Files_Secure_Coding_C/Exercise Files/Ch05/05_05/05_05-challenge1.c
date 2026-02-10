#include <stdio.h>
#include <stdlib.h>

int get_number(void)
{
	int a;
	int numeric = 0;
	
	/* Buffer holds 1 character */
	char *r, *ptr;
	
	/* Obtain string input */
	r = fgets(ptr,2,stdin);

	/* Verify input */
	if (r == NULL) {
		puts("Invalid Input");
		exit(1);
	}
	if( strcmp(ptr,"nan")==0 || strcmp(ptr,"inf")==0 )
	{
		puts("Invalid input");
		exit(1);
	}	
	if (*ptr == '\n') {
		*ptr = '\0';
	}
	
	/* Convert String to integer and verify */
	numeric = atoi(ptr);
	printf("\nnumeric = %d", numeric);
	
	/* Free and clear allocated memory */
	free(ptr);
	ptr = NULL;
	*ptr = '\0';
	
	
	return numeric;

}

int main()
{
	int x,digit[3];

	puts("Valid digits are from 0 to 99");
	for( x=0; x<3; x++ )
	{
		printf("Enter digit #%d: ",x+1);
		digit[x] = get_number();
		printf("\nIteration %d\n", x);
	}

	printf("The combination is: ");
	for( x=0; x<3; x++ )
	{
		printf(" %02d",digit[x]);
	}
	putchar('\n');

	return(0);
}

