#include <utility.h>
#include <header.h>
#include <colors.h>

// Global declarations
FILE *fp;
char firstn[20], lastn[20], stnum[20], stnum2[20];
float midterm, finals;

// A] New File
// Function to create a new file, erasing the existing contents
void add_file() {
	p(BOLD YELLOW); // Set text color to bold yellow
	center(24, "WARNING!!! This will erase the contents of the file!");
	center(25, "Do you want to Continue[Y/N]: ");
	gotoxy(56, 25);
	p(RESET);
	char input = tolower(getche());

	if (input == 'y') { // If 'Y', a new file will be created
		fp = fopen("st_records.txt", "w");
		clearportion(5, 23, 76, 25);
		printf(CYAN); // Change color to CYAN
		center(24, "A NEW FILE HAS BEEN CREATED!");
		printf(RESET);
		center(25, "Press any key to continue...");
		gotoxy(57, 25);
		getch();
		clearportion(5, 23, 76, 25); // Clear the "a new file has been created" message
	} else if (input == 'n') { // If 'N', the records will not be erased
		clearportion(5, 23, 76, 25); // Clear the warning message
	}
}

// B] Add Records
// Function to add a new student record to the file
void add_record() {
	fp = fopen("st_records.txt", "a"); // Open file in append mode
	system("cls");
	box2(2, 2, 80, 27);
	box3(4, 4, 78, 7);
	printxy(6, 5, "You have selected option B");
	printxy(6, 6, "Adding a record to the text file");
	box3(29, 9, 51, 11);
	center(10, "Fill up the details");
	box3(4, 8, 78, 22);

	printf(GREEN);
	printxy(15, 14, "Student Number: ");
	printxy(15, 15, "First Name: ");
	printxy(15, 16, "Last Name: ");
	printxy(15, 17, "Midterm: ");
	printxy(15, 18, "Finals: ");
	printf(RESET);

	gotoxy(34, 14);
	scanf("\n");
	gets(stnum);
	gotoxy(34, 15);
	gets(firstn);
	gotoxy(34, 16);
	gets(lastn);
	gotoxy(34, 17);
	scanf("%f", &midterm);
	gotoxy(34, 18);
	scanf("%f", &finals);

	// Write the input to the file
	fprintf(fp, "%s,%s,%s, %.2f %.2f\n", stnum, firstn, lastn, midterm, finals);
	center(20, "Your input is stored in the text file!");
	gotoxy(61, 20);
	fclose(fp);
	getch();
}

// C] Search Student
// Function to search for a specific student record
void search() {
	fp = fopen("st_records.txt", "r");
	system("cls");
	box2(2, 2, 80, 27);
	box3(4, 4, 78, 7);
	printxy(6, 5, "You have selected option C");
	printxy(6, 6, "Search Record");

	printf(GREEN); // Set color to green
	printxy(15, 12, "Student Number: ");
	printxy(15, 14, "First Name: ");
	printxy(15, 16, "Last Name: ");
	printxy(15, 18, "Midterm: ");
	printxy(15, 20, "Finals: ");
	printxy(45, 23, "Enter Student No. to Search: ");
	printf(RESET);
	gotoxy(34, 12);
	getch();
}

// D] Display Records
// Function to display all student records
void add_display() {
	int lctr = 0, row = 10, page = 0, count = 0, sw = 0, passed = 0, failed = 0, total = 0;
	char remarks[15];

	fp = fopen("st_records.txt", "r"); // Open file in read mode
	system("cls");
	center(2, YELLOW "\tPolytechnic University of the Philippines"); // Header
	center(3, "\tSan Juan City Campus" RESET);
	printxy(9, 7, "#  \tStudent Name \t\tMidterms  Finals  Average  Remarks\n");
	hline(8, 9, 73, '=');
	printxy(9, 5, "Page: ");
	gotoxy(16, 5);
	p("%d", page);

	while (fscanf(fp, "%[^,],%[^,],%[^,], %f %f\n", stnum, firstn, lastn, &midterm, &finals) != EOF) {
		if (sw == 0) {
			sw = 1;
			page++;
			center(2, YELLOW "\tPolytechnic University of the Philippines");
			center(3, "\tSan Juan City Campus" RESET);
			printxy(9, 7, "#  \tStudent Name \t\tMidterms  Finals  Average  Remarks\n");
			hline(8, 9, 73, '=');
			printxy(9, 5, "Page: ");
			gotoxy(16, 5);
			p("%d", page);
		}
		lctr++;
		count++;
		double ave = (midterm + finals) / 2; // Compute for the average
		if (ave <= 3.12) { // Check if the student passed or failed
			strcpy(remarks, "Passed");
			passed++;
			total++; // Count the total students
		} else {
			strcpy(remarks, "Failed");
			failed++;
			total++; // Count the total students
		}
		gotoxy(9, row);
		printf("%d.\t%s %s\t", lctr, firstn, lastn);
		gotoxy(34, row);
		printf("\t  %.2f\t   %.2f\t   %.2f    %s\n", midterm, finals, ave, remarks);
		if (count == 3) {
			sw = 0;
			count = 0;
			row = 9;
			getch();
			system("cls");
		}
		row++;
	}

	// Display the total number of students passed/failed
	box3(8, 16, 46, 22);
	printf(BOLD YELLOW);
	gotoxy(10, 18);
	p("Total number of Students: ");
	gotoxy(36, 18);
	p("%d", total);
	gotoxy(10, 19);
	p("Total number of Students Passed: ");
	gotoxy(43, 19);
	p("%d", passed);
	gotoxy(10, 20);
	p("Total number of Students Failed: ");
	gotoxy(43, 20);
	p("%d", failed);
	printf(RESET);
	getch();
	fclose(fp);
}

// E] Close the program
// Function to close the program with a delay and animation
void close() {
	int x = 0;
	int delay = 800;
	int time = 3;
	system("cls");

	for (int i = time; i >= 0; --i) {
		system("cls");
		gotoxy(40, 12);
		p("Closing in %d . . .\n", i);
		Sleep(delay);
	}
	// Animation logic here (omitted for brevity)
	return;
}

// Function for error message
void error_msg() {
	center(24, "Invalid Option! Press any key to continue...");
	gotoxy(65, 24);
	getch();
	clearportion(10, 22, 77, 23);
}

// Function for main page
void main_page() {
	char answer = ' ';
	while (answer != 'E') {
		system("cls");
		box2(2, 2, 80, 27);
		box3(4, 3, 78, 7);
		center(4, "Polytechnic University of the Philippines");
		center(5, "San Juan Campus");
		center(6, "San Juan City");
		box3(32, 9, 49, 11);
		center(10, "Student Record");
		box3(4, 8, 78, 22);
		printxy(31, 14, "A.) New File");
		printxy(31, 15, "B.) Add Records");
		printxy(31, 16, "C.) Search Records");
		printxy(31, 17, "D.) Display Records");
		printxy(31, 18, "E.) Close the Program");
		printxy(32, 20, "Select an option ");
		gotoxy(50, 20);
		answer = toupper(getche());
		switch (answer) {
			case 'A':
				add_file();
				break;
			case 'B':
				add_record();
				break;
			case 'C':
				search();
				break;
			case 'D':
				add_display();
				break;
			case 'E':
				close();
				break;
			default:
				error_msg();
		}
	}
}

int main() {
	main_page();
	return 0;
}
