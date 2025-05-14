#include <header.h> // Include necessary header file

int main() {
	// Define a structure template for student identification
	struct identification {
		char last[10];  // Last name
		char first[10]; // First name
		int age;        // Age
	} record[3];       // Array of 3 records

	int x;

	// Input data for each record
	for (x = 0; x < 3; x++) {
		printf("\nLast Name: ");
		gets(record[x].last); // Get last name

		printf("First Name: ");
		gets(record[x].first); // Get first name

		printf("Age: ");
		scanf("%d", &record[x].age); // Get age
	}

	// Display the data for each record
	for (x = 0; x < 3; x++) {
		printf("\n%s\t%s\t", record[x].last, record[x].first); // Print last and first name
		printf("%d", record[x].age); // Print age
	}

	return 0; // Return success
}
