#include <stdio.h>

// Function to calculate and print the sum of two numbers
void sum(int num1, int num2) {
    int result = num1 + num2;
    printf("Sum of %d and %d is: %d\n", num1, num2, result);
}

// Function to calculate and print the difference between two numbers
void difference(int num1, int num2) {
    int result = num1 - num2;
    printf("Difference between %d and %d is: %d\n", num1, num2, result);
}

// Function to calculate and return the product of two numbers
int product(int num1, int num2) {
    return num1 * num2;
}

int main() {
    // Declare and initialize two integer variables
    int var1 = 10;
    int var2 = 5;

    // Call the sum function
    sum(var1, var2);

    // Call the difference function
    difference(var1, var2);

    // Call the product function and store the result
    int product_result = product(var1, var2);

    // Print the product result
    printf("Product of %d and %d is: %d\n", var1, var2, product_result);

    return 0; // Indicate successful program termination
}
