#include <stdio.h> // Include standard input-output library

int main() {
    // Declare an array to hold 5 integers
    int x[5], sum = 0;

    // Loop to take input for the array
    for (int i = 0; i < 5; i++)
    {
        printf("Enter no. for index %d: ", i);
        scanf("%d", &x[i]);
        sum += x[i]; // Add the input value to the sum
    }

    printf("\n");

    // Loop to print the array in reverse order
    for (int i = 4; i >= 0; i--)
    {
        printf("x[%d] = %d \n", i, x[i]);
    }

    // Print the sum of the array elements
    printf("\nSum is: %d \n", sum);

    return 0; // Indicate successful program termination
}
