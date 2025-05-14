#include <utility.h>
#include <header.h>

// Function declarations
void main_page();

// Structure to store student records
struct Record {
	char lastn[15];      // Last name
	char firstn[15];     // First name
	float quizAve;       // Quiz average
	float labAve;        // Lab average
	float mtEq;          // Midterm equivalent
	double midGrade;     // Midterm grade
} student[3];

int x;

// Function to add student records
void page2() {
	system("cls"); // Clear the screen

	for (x = 0; x <= 2; x++) {
		// Input student details
		p("Last Name: ");
		scanf("%s", student[x].lastn);

		p("First Name: ");
		scanf("%s", student[x].firstn);

		p("Quiz Average: ");
		scanf("%f", &student[x].quizAve);

		p("Lab Average: ");
		scanf("%f", &student[x].labAve);

		p("Midterm Equivalent: ");
		scanf("%f", &student[x].mtEq);

		// Compute midterm grade
		student[x].midGrade = (student[x].quizAve * 0.35) + (student[x].labAve * 0.35) + (student[x].mtEq * 0.30);
	}

	// Confirmation message
	p("\nStudents added successfully");
	p("."); Sleep(100); p("."); Sleep(100); p("."); Sleep(100);

	getch(); // Wait for user input
	main_page(); // Return to main page
}

// Function to display student records
void page3() {
	system("cls"); // Clear the screen

	// Display header
	p("# Student Name\t\tQuiz Ave\tLab Ave\t\tMT EQ\t\tMidterm Grade");

	// Loop through and display each student's record
	for (int i = 0; i <= 2; i++) {
		struct Record s = student[i];
		p("\n%d. %s %s", i + 1, s.firstn, s.lastn);
		p("\t%.2f", s.quizAve);
		p("\t\t%.2f", s.labAve);
		p("\t\t%.2f", s.mtEq);
		p("\t\t  %.2f", s.midGrade);
	}

	getch(); // Wait for user input
	main_page(); // Return to main page
}

// Function to display a motivational message
void page4() {
	system("cls"); // Clear the screen

	// Display ASCII art and motivational quote
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
	center(12, "THOSE THAT DON’T BELIEVE IN"); Sleep(300);
	center(13, "THEMSELVES.\" - NARUTO UZUMAKI"); Sleep(300);

	getch(); // Wait for user input
	main_page(); // Return to main page
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

		// Navigate to the corresponding page
		if (answer == 'A') {
			page2();
		} else if (answer == 'B') {
			page3();
		} else {
			page4();
		}
	}
}

// Entry point of the program
main() {
	main_page(); // Start with the main menu
}
