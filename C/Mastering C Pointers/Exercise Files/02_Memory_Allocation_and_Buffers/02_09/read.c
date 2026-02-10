/*
Saving a Record:
- The structure is allocated as a pointer  
- Contains two members: string name, integer age
- Prompt user to provide both inputs
- Write the structure to the file save.dat
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define structure
    struct person{
        char name[20]; // member cannot have a pointer
        int age;
    };

    // Create and allocate the structure
    struct person *human = (struct person *) malloc(sizeof(struct person) * 1);
    if (human == NULL)
    {
        fprintf(stderr,"Unable to allocate storage\n");
        exit(1);    
    }

    // Prompt user for input
    printf("Enter name: ");
    scanf("%s", &human->name);
    printf("Enter your age: ");
    scanf("%d", &human->age);
    // Echo Test
    printf("\nName: %s ", human->name);
    printf("\nAge: %d ", human->age);

    // Save structure data to file
    FILE *data;
    data = fopen("save.dat", "w");
    if( data == NULL)
	{
		fprintf(stderr,"Unable to create file\n");
		exit(1);
	}

    fwrite(human, sizeof(struct person), 1, data);

    // Close file
    fclose(data);
    
    return 0;
}