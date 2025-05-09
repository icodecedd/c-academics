#include <stdio.h> // Include standard input/output header

// Global variable
int x;

// Function f1: Placeholder function (currently does nothing)
void f1()
{
	// Function body is empty
}

// Function f2: Placeholder function (currently does nothing with the array)
void f2(int array1[])
{
	// Function body is empty
}

// Function f3: Increments each element of the array by 1
void f3(int array1[])
{
	for (x = 0; x < 3; x++) // Loop through the array (size is 3)
	{
		array1[x] += 1; // Increment each element by 1
	}
}

// Main function
int main()
{
	// Declare and initialize an array with 3 elements
	int array1[3] = {12, 4, 56};

	// Call f3 to modify the array
	f3(array1);

	// Print the modified array
	for (x = 0; x < 3; x++)
	{
		printf("\n%d", array1[x]); // Print each element of the array
	}

	return 0; // Indicate successful program termination
}
