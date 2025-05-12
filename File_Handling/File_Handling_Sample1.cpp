#include <stdio.h>

// File handling in C
// Steps:
// 1. Declare a file pointer (e.g., FILE *fptr;).
// 2. Open the file using fopen() with the desired mode.
//    MODES:
//    - "w"  : Write (creates a new file or overwrites an existing file).
//    - "a"  : Append (adds data to the end of an existing file or creates a new file).
//    - "r"  : Read (opens an existing file for reading).
//    - "w+" : Read and write (creates a new file or overwrites an existing file).
//    - "a+" : Read and append (opens an existing file or creates a new file).
//    - "r+" : Read and write (opens an existing file for both reading and writing).
// 3. Perform file operations (e.g., read, write).
// 4. Close the file using fclose() to release resources.

int main() {
	// Data to be written to the file
	char name[15] = "Wolverine";
	int age = 100;

	// Declare a file pointer
	FILE *fptr;

	// Open the file "Sample.txt" in write mode ("w")
	// This will create the file if it doesn't exist or overwrite it if it does
	fptr = fopen("Sample.txt", "w");
	if (fptr == NULL) { // Check if the file was opened successfully
		perror("Error opening file");
		return 1; // Exit with an error code
	}

	// Write data to the file using fprintf
	fprintf(fptr, "%s %d\n", name, age);

	// Inform the user that the record has been added
	puts("Record has been added to the file.");
	puts("To view the file, you can open 'Sample.txt' using a text editor.");

	// Close the file to release resources
	fclose(fptr);

	return 0; // Indicate successful execution
}
