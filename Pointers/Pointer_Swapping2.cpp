#include <stdio.h>

// Function to swap the values of two integers using pointers
void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1; // Store the value pointed to by ptr1 in a temporary variable
    *ptr1 = *ptr2;    // Assign the value pointed to by ptr2 to ptr1
    *ptr2 = temp;     // Assign the value stored in temp to ptr2
}

int main() {
    int b = 10; // Initialize variable b with value 10
    int d = 20; // Initialize variable d with value 20
    
    int *a = &b; // Pointer a points to the address of b
    int *c = &d; // Pointer c points to the address of d

    // Print values before swapping
    printf("Before swapping:\n");
    printf("Value of b: %d\n", *a);
    printf("Value of d: %d\n", *c);

    // Call the swap function to swap the values of b and d
    swap(a, c);

    // Print values after swapping
    printf("\nAfter swapping:\n");
    printf("Value of b: %d\n", *a);
    printf("Value of d: %d\n", *c);

    return 0; // Indicate successful program termination
}
