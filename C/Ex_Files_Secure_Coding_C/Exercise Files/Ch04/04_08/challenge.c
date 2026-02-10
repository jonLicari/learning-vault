#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SIZE = 5 digits + terminating character */
#define SIZE 6

int main() {

	const char updated[] = "new";
	char usrpin[SIZE] = "\0";
	char *buffer;
	int a,result;

	printf("Enter 5-digit PIN: ");
	
	/* Read in user PIN */
	result = fgets(usrpin, SIZE, stdin);
	
	/* Test for null string */
	if(result == NULL )
	{
		puts("Invalid input");
		exit(1);
	}
	
	/* Remove new line character */
	for(a=0; a < SIZE; a++) {
		if (usrpin[a] == '\n')
			usrpin[a] = '\0';
	}
	
	/* Filter out undefined values */
	if( strcmp(usrpin,"nan")==0 || strcmp(usrpin,"inf")==0 )
	{
		puts("Invalid input");
		exit(1);
	}
	
	/* Ensure User PIN is 5 digits in length */
	if(strlen(usrpin) != 5)
	{
		printf("Size = %d ", strlen(usrpin));
		puts("PIN must be 5 digits!");
		
		exit(1);
	}	   
	
	/* Allocate buffer memory */
	buffer = (char *)malloc (sizeof(char)* (strlen(usrpin)+strlen(updated))+1);
	
	if (buffer == NULL) {
		fprintf(stderr, "Unable to allocate memory");
		exit(1);
	}
	
	/* Copy user PIN into buffer */
	strcpy(buffer, usrpin);
	
	/* Concatenate the suffix string to the user PIN */
	strcat(buffer, updated);
	printf("Updated passcode is: %s \n", buffer);
	
	/* Buffer Scrub */
	for (a=0; a < SIZE; a++) {
		usrpin[a] = '\0';
	}
	for (a=0; a < strlen(buffer); a++) {
		*(buffer+a) = '\0';
	}
	
	return 0;
}

