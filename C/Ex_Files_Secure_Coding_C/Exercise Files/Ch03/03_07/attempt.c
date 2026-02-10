#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

int main() {

	char buffer[SIZE], output[SIZE];
	int ctr = 0;
	int index = 0;
	float net;

	printf("Enter your total winnings in dollars: ");
	
	/* test for a null string */
	if(fgets(buffer, SIZE-1, stdin) == NULL )
		buffer[0] = '\0';
	
	buffer[SIZE-1] = '\0';	  
		
	/* scan for and remove the newline */
	if( strcmp(buffer,"nan")==0 || strcmp(buffer,"inf")==0 )
	{
		puts("Invalid input");
		exit(1);
	}
		
	/* Filter out commas */
	while (buffer[ctr] != '\0') {
	
		if (buffer[ctr] != ',') {
		
			output[index] = buffer[ctr];
			index++;
		}
		ctr++;
	}
	
	/* convert string to floating point */
	net = strtof(output, NULL); 
	
	/* Apply tax */
	net *= 0.55;
	
	printf("User's net winnings total $ %0.2f", net);	

return 0;
}

