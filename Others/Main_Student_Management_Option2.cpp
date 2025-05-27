/**
 * @file Activity - Main Student Records - Option 2.cpp
 * @brief A program to manage student records, including creating new files, 
 * 		  adding records, searching, displaying, and closing the program.
 */

#include<utility.h>
#include<header.h>
#include<colors.h>

// Global declarations
FILE *fp;
char firstn[25], lastn[25], stnum[15];
float midterm, finals;

// A] New File
void add_file() {
	p(BOLD YELLOW); // Set text color to bold yellow
	center(24, "WARNING!!! this will erase the contents of the file!");
	center(25, "Do you want to Continue[Y/N]: ");
	gotoxy(56, 25); p(RESET);
	char input = tolower(getche());

	if (input == 'y') { // If Y, a new file will be created
		fp = fopen("st_records.txt", "w");
		clearportion(5, 23, 76, 25);
		printf(CYAN); // Change color to CYAN
		center(24, "A NEW FILE HAS BEEN CREATED!");
		printf(RESET);
		center(25, "Press any key to continue...");
		gotoxy(57, 25);
		getch();
		clearportion(5, 23, 76, 25); // Clear the "a new file has been created"
	} else if (input == 'n') { // If N, the records will not be erased
		clearportion(5, 23, 76, 25); // Clear the WARNING!!!
	}
}

// B] Add Records
void add_record() {
	fp = fopen("st_records.txt", "a"); // Append to the stream
	system("cls");
	box2(2, 2, 80, 27);
	box3(4, 4, 78, 7);
	printxy(6, 5, "You have selected option B");
	printxy(6, 6, "Adding of record to the text file");
	box3(29, 9, 51, 11);
	center(10, "Fill up the details");
	box3(4, 8, 78, 22);

	printf(GREEN);
	printxy(15, 14, "Student Number: ");
	printxy(15, 15, "Last Name: ");
	printxy(15, 16, "First Name: ");
	printxy(15, 17, "Midterm: ");
	printxy(15, 18, "Finals: ");
	printf(RESET);

	gotoxy(34, 14); scanf("\n"); gets(stnum);
	gotoxy(34, 15); gets(lastn);
	gotoxy(34, 16); gets(firstn);
	gotoxy(34, 17); scanf("%f", &midterm);
	gotoxy(34, 18); scanf("%f", &finals);

	// Send the input to the stream
	fprintf(fp, "%s,%s,%s, %.2f %.2f\n", stnum, firstn, lastn, midterm, finals);
	center(20, "Your input is stored to the text file!");
	gotoxy(61, 20);
	fclose(fp);
	getch();
}

// C] Search Student
void search() {
	char answer;
	do {
		fp = fopen("st_records.txt", "r");
		system("cls");

		// Display record
		box2(2, 2, 80, 27);
		box3(4, 4, 78, 7);
		printxy(6, 5, "You have selected option C");
		printxy(6, 6, "Search Record");

		printf(GREEN); // Set color to green
		printxy(15, 12, "Student Number: ");
		printxy(15, 14, "Last Name: ");
		printxy(15, 16, "First Name: ");
		printxy(15, 18, "Midterm: ");
		printxy(15, 20, "Finals: ");
		printxy(30, 23, "Enter Student No. to Search: ");
		printf(RESET);

		// Process to search student record
		char stnum2[15];
		int check, found = 0;

		gotoxy(59, 23); gets(stnum2); // Get the input of the user

		while (fscanf(fp, "%[^,],%[^,],%[^,], %f %f\n", stnum, firstn, lastn, &midterm, &finals) != EOF) {
			check = strcmp(stnum, stnum2); // Compare input to stnum in file
			if (check == 0) { // Found
				found = 1;
				gotoxy(34, 12); printf("%s", stnum);
				gotoxy(34, 14); printf("%s", lastn);
				gotoxy(34, 16); printf("%s", firstn);
				gotoxy(34, 18); printf("%.2f", midterm);
				gotoxy(34, 20); printf("%.2f", finals);
				fclose(fp);
			}
		}

		if (found == 0) { // Not found
			printf(BRIGHT_RED);
			center(25, "Student number does not exist!");
			printf(RESET);
		}

		getch();
		clearportion(15, 25, 60, 25);

		// Ask if the user wants to search for another student ID
		printxy(5, 25, "Search for another student ID? (Y/N): ");
		gotoxy(43, 25); answer = toupper(getche());

	} while (answer == 'Y');

	fclose(fp);
}

// D] Display Records
void add_display() {
	int lctr = 0, row = 10, page = 0, count = 0, sw = 0, passed = 0, failed = 0, total = 0;
	char remarks[15];

	fp = fopen("st_records.txt", "r");
	system("cls");
	center(2, YELLOW "\tPolytechnic University of the Philippines");
	center(3, "\tSan Juan City Campus" RESET);
	printxy(9, 7, "#   \tStudent Name \t\tMidterms  Finals  Average  Remarks\n");
	hline(8, 9, 73, '=');
	printxy(9, 5, "Page: ");
	gotoxy(16, 5); p("%d", page);

	while (fscanf(fp, "%[^,],%[^,],%[^,], %f %f\n", stnum, firstn, lastn, &midterm, &finals) != EOF) {
		if (sw == 0) {
			system("cls");
			sw = 1;
			page++;
			center(2, YELLOW "\tPolytechnic University of the Philippines");
			center(3, "\tSan Juan City Campus" RESET);
			printxy(9, 7, "#   \tStudent Name \t\tMidterms  Finals  Average  Remarks\n");
			hline(8, 9, 73, '=');
			printxy(9, 5, "Page: ");
			gotoxy(16, 5); p("%d", page);
		}

		lctr++;
		count++;
		double ave = (midterm + finals) / 2; // Compute average
		if (ave <= 3.12) { // Check if passed or failed
			strcpy(remarks, "Passed");
			passed++;
			total++;
		} else {
			strcpy(remarks, "Failed");
			failed++;
			total++;
		}

		gotoxy(9, row); printf("%d.\t%s %s\t", lctr, firstn, lastn);
		gotoxy(34, row); printf("\t  %.2f\t   %.2f\t   %.2f    %s\n", midterm, finals, ave, remarks);

		if (count == 3) {
			sw = 0;
			count = 0;
			row = 9;
			getch();
		}
		row++;
	}

	// Display total students passed/failed
	printf(BOLD YELLOW);
	gotoxy(10, 18); p("Total number of Students: ");
	gotoxy(36, 18); p("%d", total);
	gotoxy(10, 19); p("Total number of Students Passed: ");
	gotoxy(43, 19); p("%d", passed);
	gotoxy(10, 20); p("Total number of Students Failed: ");
	gotoxy(43, 20); p("%d", failed);
	printf(RESET);

	getch();
	fclose(fp);
}

// E] Close the program
void close() {
	int x = 0, delay = 800, time = 5;
	system("cls");

	for (int i = time; i >= 0; --i) {
		system("cls");
		gotoxy(40, 12); p("Closing in %d . . .\n", i);
		Sleep(delay);
	}

	for (int i = 0; i != 1; i++) {
		for (x = 0; x <= 30; x++) { // Droid 1
			printf(BOLD WHITE);
			clearportion(7, 3, 60, 19); Sleep(120);
			printxy(20 + x, 9, "------");
			printxy(19 + x, 10, "/   () \\");
			printxy(17 + x, 11, "_|________|_");
			printxy(16 + x, 12, "| |  ====  | |");
			printxy(16 + x, 13, "|_|   ()   |_|");
			printxy(17 + x, 14, "||   ()   ||");
			printxy(17 + x, 15, "||___\\*\\*___||");
			printxy(15 + x, 16, "|\\~  \\______/  \\~|");
			printxy(15 + x, 17, "/=\\   /==\\   /=\\");
			printxy(15 + x, 18, "[_]   [__]   [_]");
			printf(RESET);
			printf(YELLOW); // Droid 2
			printxy(51 - x, 4, "/ ~ \\");
			printxy(50 - x, 5, "|()() )");
			printxy(49 - x, 6, "__\\ = /__");
			printxy(48 - x, 7, "/    _    \\");
			printxy(47 - x, 8, "/ /|/ @ \\|\\ \\");
			printxy(47 - x, 9, "\\ \\  \\_/   | |");
			printxy(48 - x, 10, "\\ |\\   /| | |");
			printxy(48 - x, 11, "#   _ _ / #");
			printxy(50 - x, 12, "|  |  |");
			printxy(50 - x, 13, "|  |  |");
			printxy(50 - x, 14, "|  |  |");
			printxy(50 - x, 15, "[ ]|[ ]");
			printxy(50 - x, 16, "|  |  |");
			printxy(50 - x, 17, "|  |  |");
			printxy(49 - x, 18, "/_]   [_\\");
			printf(RESET);
		}
	}

	// First message
	gotoxy(29, 5); putchar('<');
	box3(30, 2, 72, 6);
	printf(RED);
	gotoxy(31, 4); Sleep(550); p("I am C-3PO, ");
	Sleep(300); printxy(43, 4, "Thanks");
	Sleep(500); printxy(50, 4, "for using");
	Sleep(500); printxy(60, 4, "the Program!");
	printf(RESET);

	// Second message
	printf(WHITE);
	Sleep(300); printxy(60, 9, "\\*Bleep-");
	Sleep(350); printxy(67, 9, "bloop-");
	Sleep(300); printxy(73, 9, "blip!\\*");
	Sleep(400); printxy(32, 11, "\"Whooo-");
	Sleep(600); printxy(39, 11, "ooo!\"");
	Sleep(700); system("cls");
	box3(28, 6, 59, 14);
	center(10, "Closing the Program");
	gotoxy(50, 10); p(". "); Sleep(200); p(". "); Sleep(200); p(". "); Sleep(200); p(". "); Sleep(200);
	printf(RESET);
	clearportion(28, 6, 59, 14);
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
