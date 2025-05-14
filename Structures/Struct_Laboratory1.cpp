#include <Utility.h>
#include <header.h>

// Global declaration of struct
struct Record {
	char firstn[15];  // First name
	char lastn[15];   // Last name
	float midterm;    // Midterm grade
	float finals;     // Finals grade
} student[3];

// Function prototypes
void main_page();
void page2();
void page3();
void page4();

// Global variable for indexing
int x;

// Function for adding student records
void page2() {
	system("cls"); // Clear the screen

	for (x = 0; x <= 2; x++) {
		// Input student details
		p("Last Name: ");
		scanf("%s", student[x].lastn);

		p("First Name: ");
		scanf("%s", student[x].firstn);

		p("Midterm: ");
		scanf("%f", &student[x].midterm);

		p("Finals: ");
		scanf("%f", &student[x].finals);
	}

	// Confirmation message
	p("\nStudents added successfully");
	p("."); Sleep(100); p("."); Sleep(100); p("."); Sleep(100);

	getch(); // Wait for user input
	main_page(); // Return to main menu
}

// Function for displaying student records
void page3() {
	int i;
	system("cls"); // Clear the screen

	// Display header
	p("# Student Name\tMidterm\tFinals\tAverage\tRemarks");

	for (i = 0; i <= 2; i++) {
		struct Record s = student[i];
		float ave = (s.midterm + s.finals) / 2; // Calculate average
		char remark;

		// Display student details
		p("\n%d. %s %s", i + 1, s.lastn, s.firstn);
		p("\t%.2f", s.midterm);
		p("\t%.2f", s.finals);
		p("\t%.2f", ave);

		// Determine and display remarks
		if (ave >= 75)
			p("\tPassed!");
		else
			p("\tFailed!");
	}

	getch(); // Wait for user input
	main_page(); // Return to main menu
}

// Function for closing the program
void page4() {
	system("cls"); // Clear the screen

	// Display closing message
	center(6, "\\\\\\\\\\/////");
	center(7, "/ _   _ \\ ");
	center(8, "(| (.) (.) |) ");
	center(9, ".---------------.OOOOo---()---oOOOO.--------------.");
	center(10, "|                                                 |");
	center(11, "|                                                 |");
	center(12, "|                                                 |");
	center(13, "|                                                 |");
	center(14, "|                                                 |");
	center(15, ".-------------------------------------------------.");
	center(11, "\"HARD WORK IS WORTHLESS FOR"); Sleep(300);
	center(12, "THOSE THAT DON\'T BELIEVE IN"); Sleep(300);
	center(13, "THEMSELVES.\" - NARUTO UZUMAKI"); Sleep(300);

	getch(); // Wait for user input
	main_page(); // Return to main menu
}

// Main menu function
void main_page() {
	char answer = ' ';

	while (answer != 'C') {
		system("cls"); // Clear the screen

		// Display menu options
		box2(24, 8, 50, 17);
		printxy(26, 11, "A.] ADD");
		printxy(26, 12, "B.] DISPLAY");
		printxy(26, 13, "C.] CLOSE");
		printxy(28, 15, "Select an option ");
		gotoxy(45, 15);

		// Get user input
		answer = toupper(getche());

		// Navigate to the selected page
		if (answer == 'A')
			page2();
		else if (answer == 'B')
			page3();
		else
			page4();
	}
}

// Main function
int main() {
	main_page(); // Start the program with the main menu
	return 0;
}
