#include <utility.h>
#include <header.h>
#include <colors.h>

// Global declarations
FILE *fp;
char firstn[20], lastn[20], stnum[20];
float midterm, finals;

// A] New File
// Function to create a new file or clear the contents of an existing file
void add_file() {
	p(BOLD YELLOW); // Set text color to bold yellow
	center(23, "WARNING!!! This will erase the contents of the file! Continue...");
	gotoxy(74, 23);
	p(RESET);
	char input = tolower(getche());

	if (input == 'y') {
		// Open file in write mode to clear its contents
		fp = fopen("alpags.txt", "w");
		clearportion(5, 22, 76, 24); // Clear the warning message
		center(23, "The content of the file has been cleared");
		gotoxy(62, 23);
		getch();
	} else if (input == 'n') {
		// Clear the warning message if user chooses not to proceed
		clearportion(5, 22, 76, 24);
	}
}

// B] Add Records
// Function to add a new student record to the file
void add_record() {
	// Open file in append mode to add new records without overwriting existing ones
	fp = fopen("alpags.txt", "a");
	system("cls"); // Clear the screen
	box2(2, 2, 80, 26); // Draw the main box
	box3(4, 4, 78, 7); // Draw the header box
	printxy(6, 5, "You have selected option B");
	printxy(6, 6, "Adding a record to the text file");
	box3(29, 9, 51, 11); // Draw the input prompt box
	center(10, "Fill up the details");
	box3(4, 8, 78, 21); // Draw the input fields box

	// Prompt user for input
	printxy(15, 14, "Student Number: ");
	printxy(15, 15, "First Name: ");
	printxy(15, 16, "Last Name: ");
	printxy(15, 17, "Midterm: ");
	printxy(15, 18, "Finals: ");

	// Get user input for student details
	gotoxy(34, 14);
	gets(stnum);
	gotoxy(34, 15);
	gets(firstn);
	gotoxy(34, 16);
	gets(lastn);
	gotoxy(34, 17);
	scanf("%f", &midterm);
	gotoxy(34, 18);
	scanf("%f", &finals);

	// Write the input to the file in a formatted manner
	fprintf(fp, "%s,%s,%s,%.2f %.2f\n", stnum, firstn, lastn, midterm, finals);
	center(20, "Your input is stored in the text file!");
	gotoxy(61, 20);
	fclose(fp); // Close the file to save changes
	getch();
}

// C] Display Records
// Function to display all student records from the file
void add_display() {
	int x = 0;
	// Open file in read mode to read existing records
	fp = fopen("alpags.txt", "r");
	system("cls"); // Clear the screen
	printf("#  \tStudent Name \t\tMidterms  Finals  Average\n");
	hline(1, 0, 56, '='); // Draw a horizontal line for formatting

	// Read and display each record from the file
	while (fscanf(fp, "%[^,],%[^,],%[^,],%f %f\n", stnum, firstn, lastn, &midterm, &finals) != EOF) {
		double ave = (midterm + finals) / 2; // Compute the average
		gotoxy(0, 2 + x);
		printf("%d. %s %s", x + 1, firstn, lastn); // Display student name
		gotoxy(34, 2 + x);
		printf("%.2f\t   %.2f\t   %.2f\n", midterm, finals, ave); // Display scores and average
		x++;
	}
	fclose(fp); // Close the file after reading
	getch();
}

// D] Close the Program
// Function to display a closing animation and exit the program
void page3() {
	int x = 0;
	int delay = 1000; // Delay for countdown
	int time = 5; // Countdown duration
	system("cls");

	// Countdown before closing
	for (int i = time; i >= 0; --i) {
		system("cls");
		gotoxy(40, 12);
		p("Closing in %d . . .\n", i);
		Sleep(delay);
	}

	// Animation (simplified for brevity)
	for (int i = 0; i != 1; i++) {
		for (x = 0; x <= 30; x++) {
			printf(BOLD WHITE);
			clearportion(7, 3, 60, 19); // Clear animation area
			Sleep(120);
			// Animation details omitted for brevity
			printf(RESET);
		}
	}

	// Closing messages
	gotoxy(29, 5);
	putchar('<');
	box3(30, 2, 72, 6); // Draw closing message box
	printf(RED);
	gotoxy(31, 4);
	Sleep(550);
	p("I am C-3PO, ");
	Sleep(300);
	printxy(43, 4, "Thanks");
	Sleep(500);
	printxy(50, 4, "for using");
	Sleep(500);
	printxy(60, 4, "the Program!");
	printf(RESET);

	// Final message
	printf(WHITE);
	Sleep(300);
	printxy(60, 9, "*Bleep-");
	Sleep(350);
	printxy(67, 9, "bloop-");
	Sleep(300);
	printxy(73, 9, "blip!*");
	Sleep(400);
	printxy(32, 11, "\"Whooo-");
	Sleep(600);
	printxy(39, 11, "ooo!\"");
	Sleep(700);
	system("cls");
	box3(28, 6, 59, 14); // Draw final closing box
	center(10, "Closing the Program");
	gotoxy(50, 10);
	p(". ");
	Sleep(400);
	p(". ");
	Sleep(400);
	p(". ");
	Sleep(400);
	p(". ");
	Sleep(400);
	printf(RESET);
	clearportion(28, 6, 59, 14); // Clear the final box
	return;
}

// Function for error message
void error_msg() {
	center(23, "Invalid Option! Press any key to continue...");
	gotoxy(65, 23);
	getch();
	clearportion(10, 23, 77, 23); // Clear the error message
}

// Function for main page
void main_page() {
	char answer = ' ';
	while (answer != 'D') {
		system("cls");
		box2(2, 2, 80, 26); // Draw the main box
		box3(4, 3, 78, 7); // Draw the header box
		center(4, "Polytechnic University of the Philippines");
		center(5, "San Juan Campus");
		center(6, "San Juan City");
		box3(32, 9, 49, 11); // Draw the title box
		center(10, "Student Record");
		box3(4, 8, 78, 21); // Draw the options box
		printxy(30, 14, "A.) New File");
		printxy(30, 15, "B.) Add Records");
		printxy(30, 16, "C.) Display Records");
		printxy(30, 17, "D.) Close the Program");
		printxy(32, 19, "Select an option ");
		gotoxy(50, 19);
		answer = toupper(getche()); // Get user input for menu selection
		if (answer == 'A')
			add_file(); // Call function to create/clear file
		else if (answer == 'B')
			add_record(); // Call function to add a record
		else if (answer == 'C')
			add_display(); // Call function to display records
		else if (answer == 'D')
			page3(); // Call function to close the program
		else
			error_msg(); // Display error message for invalid input
	}
}

// Main function
int main() {
	center(12, "Press any key to Start!");
	gotoxy(53, 12);
	getch();
	system("cls");
	center(12, "Opening the Student Record");
	gotoxy(55, 12);
	p(". ");
	Sleep(350);
	p(". ");
	Sleep(350);
	p(". ");
	Sleep(350);
	p(". ");
	Sleep(350);
	system("cls");
	center(12, "Loading the data");
	gotoxy(50, 12);
	p(". ");
	Sleep(400);
	p(". ");
	Sleep(400);
	p(". ");
	Sleep(400);
	p(". ");
	Sleep(400);
	main_page(); // Call the main page function
	return 0;
}
