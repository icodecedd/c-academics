#include<stdio.h> // Include standard input-output library

int main() {
	// Declare an array to hold 10 integers
	int arr[10];
	int y;

	// Prompt the user to enter 10 numbers
	printf("Enter 10 numbers for the array:\n");
	for (y = 0; y < 10; y++) {
		// Read each number and store it in the array
		scanf("%d", &arr[y]);
	}
	
	// Display the numbers entered by the user
	printf("You entered:\n");
	for (y = 0; y < 10; y++) {
		// Print each element of the array followed by a space
		printf("%d ", arr[y]);
	}
	printf("\n");
	
	// Return 0 to indicate successful execution
	return 0;
}