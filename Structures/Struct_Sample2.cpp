/**
 * This program defines a structure to store student grades, including their
 * last name, midterm grade, and final grade. It allows the user to input
 * grades for 5 students, calculates their average grades, and displays the
 * results in a tabular format.
 */

 #include <header.h>

// Define a structure to store student grades
struct student_grade {
	char last[10];  // Student's last name
	float final, mid;  // Final and midterm grades
} test[5];  // Array to store grades for 5 students

int x;

int main() {
	// Input grades for 5 students
	for (x = 0; x <= 4; x++) {
		printf("\nName: ");
		scanf("\n");  // Clear input buffer
		gets(test[x].last);  // Get student's last name

		printf("Midterm Grade: ");
		scanf("%f", &test[x].mid);  // Get midterm grade

		printf("Finals Grade: ");
		scanf("%f", &test[x].final);  // Get final grade
	}

	// Print header for the output table
	printf("\n\tName\tMidterm\tFinals\tAverage");

	// Calculate and display grades for each student
	for (x = 0; x <= 4; x++) {
		float ave;
		ave = (test[x].mid + test[x].final) / 2;  // Calculate average grade

		// Print student details and grades
		printf("\n%d\t%s\t%.2f\t%.2f\t%.2f", x, test[x].last, test[x].mid, test[x].final, ave);
	}

	return 0;  // Indicate successful program termination
}
