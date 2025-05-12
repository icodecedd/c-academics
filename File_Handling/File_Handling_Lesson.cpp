#include <stdio.h>
#include <string.h>
#include <ctype.h> // For tolower()
#include <conio.h> // For getche()

int main() {
	char name[10], file_name[20], ext[10] = ".txt";
	int age;
	char ans = 'y';
	FILE *fp; // Declare a file pointer

	// Prompt user for the file name
	printf("Enter your file name: ");
	gets(file_name); // Read the file name from the user
	strcat(file_name, ext); // Append ".txt" extension to the file name

	// Open the file in append mode to add records
	fp = fopen(file_name, "a");
	if (fp == NULL) { // Check if the file was opened successfully
		printf("Error opening file!\n");
		return 1; // Exit the program if file opening fails
	}

	// Loop to add multiple records
	while (ans == 'y') {
		printf("\nName: ");
		gets(name); // Read the name from the user

		printf("Age: ");
		scanf("%d", &age); // Read the age from the user

		fprintf(fp, "\n%s %d", name, age); // Write the name and age to the file

		printf("Continue? (y/n): ");
		ans = tolower(getche()); // Get the user's choice and convert to lowercase
		printf("\n"); // Add a newline for better formatting
	}

	fclose(fp); // Close the file
	printf("Records saved successfully.\n");

	return 0; // Exit the program
}
