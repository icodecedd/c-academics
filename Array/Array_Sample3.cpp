#include <stdio.h>
#include <string.h>

// Function to demonstrate passing an array to a function
void pass_array(int x[]) {
	int y;
	// Loop to modify the array elements
	for (y = 0; y <= 4; y++) {
		x[y] = 2; // Assign value 2 to each element
	}

	printf("\nNew values in the array:\n");
	// Loop to print the modified array elements
	for (y = 0; y <= 4; y++) {
		printf("%d ", x[y]);
	}
	printf("\n");
}

int main() {
	int x = 10; // Integer variable
	char name1[10] = "gaara"; // String variable
	char name2[10]; // Empty string for copying
	char name3[10] = "temari"; // Another string variable

	// Print the original string
	puts(name1);

	// Convert the string to uppercase
	strupr(name1);
	puts(name1);

	// Copy the uppercase string to name2
	strcpy(name2, name1);
	puts(name2);

	// Compare the strings ignoring case
	x = stricmp(name1, name2);
	printf("\nComparison result: %d\n", x);

	// Check if the strings are the same (ignoring case)
	if (stricmp(name1, name2) == 0) {
		printf("Same content but different case\n");
	} else {
		printf("Different content\n");
	}

	// Concatenate name1 and name3
	strcat(name1, name3);
	puts(name1);
	puts(name3);

	// Reverse the concatenated string
	strrev(name1);
	puts(name1);

	// Print the 5th character of the reversed string
	putchar(name1[4]);
	printf("\n");

	return 0; // Return 0 to indicate successful execution
}
