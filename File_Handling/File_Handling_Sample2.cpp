#include <stdio.h>
#include <ctype.h>
#include <conio.h>

// Main function
int main() {
	// Declare variables
	char name[15];
	int age;
	FILE *fp;

	// Open the file in read mode
	fp = fopen("HAPPY Coding.txt", "r");
	if (fp == NULL) {
		// Check if the file exists
		printf("Error: Could not open file.\n");
		return 1; // Exit with error code
	}

	// Read data from the file
	// fscanf requires pointers for variables, so use & for age
	if (fscanf(fp, "%s %d", name, &age) == 2) {
		// Print the data read from the file
		printf("\nName: %s\nAge: %d\n", name, age);
	} else {
		// Handle case where file content is not as expected
		printf("Error: Could not read data from file.\n");
	}

	// Close the file
	fclose(fp);

	/*
	Notes:
	- fscanf: Reads formatted input from the file.
	- fopen: Opens a file (in this case, in read mode "r").
	- fclose: Closes the file after operations are complete.
	*/

	return 0; // Return success
}
