#include <iostream>
#include <assert.h>

int main() {
    int input_data[] = {8, 1, 9, 5, 2, 10, 6, 3, 7, 4};

    auto length = sizeof(input_data) / sizeof(input_data[0]);

    printf("First = %d, Last = %d", input_data[0], input_data[length - 1]);

    // Sort data by implementing a quick sort & return sorted array
    auto sorted = quickSort(input_data, length);

    return 0;
}

// pass the input data by reference
// Return the address of the sorted array
int* quickSort(int * addr, int length) {
    assert(length > 0);
    int sorted[length];

    if (length == 1) {
        sorted[0] = (*addr);
        return sorted;
    }
    
    // pick a pivot
    const int pivot = length / 2;
    // split left & right
    // recursion perversion
}