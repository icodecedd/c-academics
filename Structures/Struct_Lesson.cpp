#include <header.h>

int main() {
	// Define a structure template for student records
	struct student {
		char last[10], first[10], course;
	} record[3]; // Array of 3 student records

	int x;

	// Input student details
	for (x = 0; x <= 2; x++) {
		p("\nLast Name: ");
		gets(record[x].last); // Get last name

		p("First Name: ");
		gets(record[x].first); // Get first name

		p("Course: ");
		record[x].course = getche(); // Get course (single character)
	}

	// Display student details
	for (x = 0; x <= 2; x++) {
		p("\n%s %s \t", record[x].last, record[x].first); // Print name

		// Determine and print course name based on course code
		if (record[x].course == 'a') {
			p("accounting");
		} else if (record[x].course == 'b') {
			p("business");
		} else {
			p("comsci");
		}
	}

	return 0; // Indicate successful program termination
}
