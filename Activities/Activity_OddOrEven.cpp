#include <stdio.h>
#include <windows.h>

// Main function
int main() {
    int y, sum_odd = 0, sum_even = 0;
    int x[10];

    // Input loop to get numbers from the user
    for (y = 0; y < 10; y++) {
        printf("Enter number for index [%d]: ", y);
        scanf("%d", &x[y]); 
        system("CLS"); // Clear the screen
    }

    // Display odd numbers and calculate their sum
    printf("\nODD NUMBERS\n");
    for (y = 0; y < 10; y++)  {
        if (x[y] % 2 != 0) // Check if the number is odd
        {
            printf("\nx[%d] = %d", y, x[y]); 
            sum_odd += x[y];
        }
    }
    printf("\nSum of odd: %d", sum_odd); // Print the sum of odd numbers

    // Display even numbers and calculate their sum
    printf("\n\nEVEN NUMBERS\n");
    for (y = 0; y < 10; y++) {
        if (x[y] % 2 == 0) // Check if the number is even
        {
            printf("\nx[%d] = %d", y, x[y]); 
            sum_even += x[y]; 
        }
    }
    printf("\nSum of even: %d", sum_even); // Print the sum of even numbers

    return 0; // Indicate successful program termination
}