#include <stdio.h> // Include standard input-output library
#include <conio.h>
#include <windows.h>
#include <string.h>

// Main function
int main() {
	int y; // Loop variable
	int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Array of integers (10 elements)
	int z[10]; // Array to store user input (10 elements)

	// Display elements of array x
	for (y = 0; y < 10; y++) // Loop from 0 to 9
		printf("\nx[%d] = %d", y, x[y]);

	// Get user input for array z
	for (y = 0; y < 10; y++) // Loop from 0 to 9
	{
		printf("\nEnter number for index %d: ", y);
		scanf("%d", &z[y]); // Store user input in z[y]
	}

	// Display user input
	printf("\nYour input:\n");

	// Display odd numbers from array z
	printf("\nOdd numbers:\n");
	for (y = 0; y < 10; y++) // Loop from 0 to 9
		if (z[y] % 2 == 1) // Check if the number is odd
			printf("\nz[%d] = %d", y, z[y]);

	// Display even numbers from array z
	printf("\nEven numbers:\n");
	for (y = 0; y < 10; y++) // Loop from 0 to 9
		if (z[y] % 2 == 0) // Check if the number is even
			printf("\nz[%d] = %d", y, z[y]);

	return 0; // Return 0 to indicate successful execution
}