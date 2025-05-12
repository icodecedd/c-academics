#include <Utility.h>  // Custom utility header (assumed)
#include <header.h>   // Custom header file (assumed)
#include <colors.h>   // Header for color definitions (assumed)

// Main function
int main() {
	FILE *fp;
	char lastn[15], firstn[15], cc;
	int row = 9, lctr = 0, page = 0, count = 0, sw = 0;

	// Open the file in read mode
	fp = fopen("record.txt", "r");
	if (fp == NULL) {
		perror("Error opening file");
		return 1;
	}

	// Read data from the file and process it
	while (fscanf(fp, "%s %s %c\n", lastn, firstn, &cc) != EOF) {
		// Initialize the page header if needed
		if (sw == 0) {
			sw = 1;
			page++;

			// Print page header
			center(2, RED "Polytechnic University of the Philippines");
			center(3, "San Juan City Campus" RESET);
			printxy(5, 5, "Page: ");
			gotoxy(11, 5);
			p("%d", page);
			printxy(5, 7, "#\t\tStudent name\t\tCourse");
			printxy(5, 8, "==============================================");
		}

		// Print student details
		lctr++;
		count++;
		gotoxy(5, row);
		p("%d", lctr);
		gotoxy(14, row);
		printf("\t%s %s \t\t", lastn, firstn);

		// Determine and print the course based on the code
		if (cc == 'A') {
			p("Accounting");
		} else if (cc == 'B') {
			p("Business");
		} else if (cc == 'C') {
			p("Comsci");
		}

		// Handle page break after 3 entries
		if (count == 3) {
			sw = 0;
			count = 0;
			row = 8;
			gotoxy(24, 70);
			getch();  // Wait for user input before clearing the screen
			system("cls");
		}

		row++;
	}

	// Close the file
	fclose(fp);

	return 0;
}
