/**
 * @file Student_Record_Search.cpp
 * @brief A student management system for creating, adding, searching, and displaying student records.
 * 
 * This program provides functionalities to manage student records, including creating a new file,
 * adding records, searching for a specific record, and displaying all records with computed averages
 * and remarks. It also includes utility functions for user interaction and screen management.
 * 
 * @author Cedrick Mariano
 */

#include <Utility.h>
#include <windows.h>

// Display an error message for invalid options
void err_mess() {
	center(23, "Invalid option. Press any key to continue...");
	getch();
	clearportion(10, 23, 77, 23);
}

// Display the closing screen
void close_screen() {
	system("cls");
	box2(10, 5, 70, 21);

	const char *art[] = {
		// ASCII art can be added here
	};

	for (int i = 0; i < 6; ++i) {
		center(7 + i, (char *)art[i]);
	}

	center(16, "Thank you for using the program!");
	center(18, "Press any key to exit...");
	getch();
	system("cls");
}

// Clear the input area on the screen
void clear_input_area() {
	for (int i = 14; i <= 18; i++) {
		gotoxy(28, i);
		printf("                         ");
	}
}

// Print the footer with passed and failed counts
void printFooter(int passed, int failed, int row) {
	gotoxy(5, row + 2);
	printf("Total Students Passed: %d", passed);
	gotoxy(5, row + 3);
	printf("Total Students Failed: %d", failed);
}

// Create a new file and warn the user about overwriting
void optionA() {
	char ch = ' ';
	center(22, "Warning! This will erase the contents of the file");
	center(23, "Continue? (y/n): ");
	gotoxy(49, 23);
	ch = getch();

	if (ch == 'y') {
		clearportion(5, 22, 76, 24);
		FILE *fp = fopen("StudRecord.txt", "w");
		fclose(fp);
		center(23, "A new File has been Created");
	} else if (ch == 'n') {
		system("cls");
	} else {
		clearportion(5, 22, 76, 24);
		center(23, "Invalid option");
		getche();
		clearportion(5, 22, 76, 24);
		system("cls");
	}
}

// Add a new record to the file
void optionB() {
	system("cls");
	box2(2, 2, 78, 25);
	box3(4, 5, 76, 8);
	box3(4, 9, 76, 21);

	printxy(6, 6, "You have selected option B");
	printxy(6, 7, "Adding of record to text file");
	box3(29, 10, 51, 12);
	center(11, "Fill up the details");

	FILE *fp = fopen("StudRecord.txt", "a");
	char student_number[6], last_name[10], first_name[10];
	float midterm, finals;
	char add_another = 'y';

	while (add_another == 'y' || add_another == 'Y') {
		clear_input_area();

		printxy(10, 14, "Student Number: ");
		printxy(10, 15, "Last Name: ");
		printxy(10, 16, "First Name: ");
		printxy(10, 17, "Midterm: ");
		printxy(10, 18, "Finals: ");

		gotoxy(28, 14);
		scanf("%s", student_number);
		gotoxy(28, 15);
		scanf("%s", last_name);
		gotoxy(28, 16);
		scanf("%s", first_name);
		gotoxy(28, 17);
		scanf("%f", &midterm);
		gotoxy(28, 18);
		scanf("%f", &finals);

		fprintf(fp, "\n%s %s %s %.2f %.2f", student_number, last_name, first_name, midterm, finals);

		printxy(10, 23, "Do you want to add another record? (Y/N): ");
		gotoxy(52, 23);
		add_another = getch();
		printxy(10, 23, "        '?'                                 ");
	}

	fclose(fp);
	system("cls");
}

// Display records from the file
void optionC() {
	system("cls");
	FILE *fp = fopen("StudRecord.txt", "r");

	char student_number[6], last_name[10], first_name[10];
	float midterm, finals, average;
	int row = 10, lctr = 0, page = 0, count = 0, sw = 0, passed = 0, failed = 0;

	while (fscanf(fp, "%s %s %s %f %f", student_number, last_name, first_name, &midterm, &finals) != EOF) {
		if (sw == 0) {
			sw = 1;
			page++;
			center(2, "Polytechnic University of the Phils.");
			center(3, "San Juan City Campus");
			printxy(5, 5, "Page: ");
			gotoxy(11, 5);
			printf("%d", page);
			printxy(5, 7, "#		Student No. & Name		Midterm		Finals		Average		Remarks");
			printxy(5, 8, "==========================================================================================");
		}

		lctr++;
		count++;
		gotoxy(5, row);
		printf("%d", lctr);

		average = (midterm + finals) / 2;

		gotoxy(16, row);
		printf("%s %s %s\t\t%.2f\t\t%.2f\t\t%.2f", student_number, first_name, last_name, midterm, finals, average);

		if (average <= 3.12) {
			printf("\t\tPassed");
			passed++;
		} else {
			printf("\t\tFailed");
			failed++;
		}

		if (count == 3) {
			sw = 0;
			count = 0;
			row = 10;
			getch();
			system("cls");
		}

		row++;
	}

	fclose(fp);
	printFooter(passed, failed, row);
	getch();
	system("cls");
}

// Search for a record by student number
void search() {
	char student_number[6], last_name[10], first_name[10];
	float midterm, finals;
	char stdnum[20];
	FILE *fp;
	int cmp;

	system("cls");
	box2(2, 2, 78, 25);
	box3(4, 5, 76, 8);
	box3(4, 9, 76, 21);

	printxy(6, 6, "Option C");
	printxy(6, 7, "Search Record");

	printxy(10, 14, "Student Number: ");
	printxy(10, 15, "Last Name: ");
	printxy(10, 16, "First Name: ");
	printxy(10, 17, "Midterm: ");
	printxy(10, 18, "Finals: ");

	center(19, "Enter Student No. to Search ");
	gotoxy(55, 19);
	gets(stdnum);

	fp = fopen("StudRecord.txt", "r");

	while (fscanf(fp, "%s %s %s %f %f", student_number, last_name, first_name, &midterm, &finals) != EOF) {
		cmp = strcmp(stdnum, student_number);

		if (cmp == 0) {
			printxy(27, 14, student_number);
			printxy(27, 15, last_name);
			printxy(27, 16, first_name);
			gotoxy(27, 17);
			printf("%.2f", midterm);
			gotoxy(27, 18);
			printf("%.2f", finals);
			fclose(fp);
			getch();
			return;
		}
	}

	fclose(fp);
	system("cls");
}

// Main function to display the menu and handle user input
int main() {
	char ans = ' ';

	while (ans != 'E') {
		clearportion(50, 19, 51, 20);
		box2(2, 2, 78, 25);
		box3(4, 5, 76, 8);
		center(6, "Polytechnic University of the Phils.");
		center(7, "San Juan City Campus");
		box3(4, 9, 76, 21);
		box3(31, 10, 51, 12);
		center(11, "Student Record");

		printxy(30, 14, " A] NEW FILE");
		printxy(30, 15, " B] ADD");
		printxy(30, 16, " C] SEARCH");
		printxy(30, 17, " D] DISPLAY");
		printxy(30, 18, " E] CLOSE");
		center(19, "Select an option ");
		gotoxy(50, 19);
		ans = toupper(getche());

		if (ans == 'A')
			optionA();
		else if (ans == 'B')
			optionB();
		else if (ans == 'C')
			search();
		else if (ans == 'D')
			optionC();
		else if (ans == 'E')
			close_screen();
		else
			err_mess();
	}

	return 0;
}
