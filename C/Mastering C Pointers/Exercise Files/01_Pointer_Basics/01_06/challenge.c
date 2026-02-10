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


