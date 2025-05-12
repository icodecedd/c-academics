#include <stdio.h>

int main() {
	// Uncomment the following block to write to the file in "write" mode (overwrites the file)
	/*
	FILE *fp; // File pointer
	fp = fopen("student.txt", "w"); // Open file in write mode
	char name[10];
	int age;

	// Get user input
	printf("Name: ");
	gets(name); // Note: gets() is unsafe and deprecated, consider using fgets() instead
	printf("Age: ");
	scanf("%d", &age);

	// Write data to the file
	fprintf(fp, "\n%s %d", name, age);
	fclose(fp); // Close the file
	puts("Your input is stored to the text file!");
	*/

	// Uncomment the following block to write to the file in "append" mode (adds to the file)
	/*
	FILE *fp; // File pointer
	fp = fopen("student.txt", "a"); // Open file in append mode
	char name[10];
	int age;

	// Get user input
	printf("Name: ");
	gets(name); // Note: gets() is unsafe and deprecated, consider using fgets() instead
	printf("Age: ");
	scanf("%d", &age);

	// Append data to the file
	fprintf(fp, "\n%s %d", name, age);
	fclose(fp); // Close the file
	puts("Your input is stored to the text file!");
	*/

	// Reading from the file
	char fn[15], ln[15], cc; // Variables to store data read from the file
	FILE *fp; // File pointer

	fp = fopen("record.txt", "r"); // Open file in read mode
	if (fp == NULL) { // Check if the file exists or can be opened
		printf("Error: Could not open file.\n");
		return 1; // Exit the program with an error code
	}

	// Print header for the output
	printf("Student Name\tCourse\n");
	printf("========================\n");

	// Read data from the file until the end of the file (EOF) is reached
	while (fscanf(fp, "%s %s %c", fn, ln, &cc) != EOF) { // Read first name, last name, and course code
		printf("\n%s %s\t", fn, ln); // Print the student's name

		// Determine the course based on the course code
		if (cc == 'A')
			printf("Accounting");
		else if (cc == 'B')
			printf("Business");
		else
			printf("Comsci");
	}

	fclose(fp); // Close the file
	return 0; // Exit the program successfully
}
