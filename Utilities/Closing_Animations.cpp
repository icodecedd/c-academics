/**
 * @file Closing_Animations.cpp
 * @brief This program contains various animation functions for displaying creative ASCII art and messages.
 *        It includes animations for robots, droids, characters, and other graphical elements.
 */

#include<header.h>
#include<Utility.h>
#include<colors.h>

// Function to display left and right robots with messages
void robot1() {
	system("cls");

	// Left-side robot
	box3(1, 3, 7, 5); Sleep(100);
	gotoxy(2, 4); putchar('^'); Sleep(100);
	gotoxy(4, 4); putchar('-'); Sleep(100);
	gotoxy(6, 4); putchar('^'); Sleep(100);
	gotoxy(1, 5); putchar('['); Sleep(100);
	gotoxy(1, 6); putchar('['); Sleep(100);
	gotoxy(7, 5); putchar(']'); Sleep(100);
	gotoxy(7, 6); putchar(']'); Sleep(100);
	gotoxy(2, 7); putchar('|'); Sleep(100);
	gotoxy(6, 7); putchar('|'); Sleep(100);
	gotoxy(4, 7); putchar('|'); Sleep(100);
	gotoxy(2, 8); putchar('['); Sleep(100);
	gotoxy(5, 8); putchar(']'); Sleep(100);
	gotoxy(7, 8); putchar(']'); Sleep(100);
	gotoxy(3, 8); putchar('_'); Sleep(100);
	gotoxy(4, 8); putchar('_'); Sleep(100);
	gotoxy(6, 8); putchar('_'); Sleep(100);
	gotoxy(9, 4); putchar('<'); Sleep(100);
	box3(10, 2, 28, 6); Sleep(100);
	printxy(11, 4, "Maraming Salamat!"); Sleep(100);

	// Right-side robot
	box3(73, 3, 79, 5); Sleep(100);
	gotoxy(74, 4); putchar('^'); Sleep(100);
	gotoxy(76, 4); putchar('-'); Sleep(100);
	gotoxy(78, 4); putchar('^'); Sleep(100);
	gotoxy(73, 5); putchar('['); Sleep(100);
	gotoxy(73, 6); putchar('['); Sleep(100);
	gotoxy(79, 5); putchar(']'); Sleep(100);
	gotoxy(79, 6); putchar(']'); Sleep(100);
	gotoxy(74, 7); putchar('|'); Sleep(100);
	gotoxy(76, 7); putchar('|'); Sleep(100);
	gotoxy(78, 7); putchar('|'); Sleep(100);
	gotoxy(73, 8); putchar('['); Sleep(100);
	gotoxy(75, 8); putchar('['); Sleep(100);
	gotoxy(78, 8); putchar(']'); Sleep(100);
	gotoxy(74, 8); putchar('_'); Sleep(100);
	gotoxy(76, 8); putchar('_'); Sleep(100);
	gotoxy(77, 8); putchar('_'); Sleep(100);
	gotoxy(71, 4); putchar('>'); Sleep(100);
	box3(50, 2, 70, 6); Sleep(100);
	printxy(51, 4, "Thank you so much!!"); Sleep(100);

	// Footer message
	box1(22, 10, 58, 15, 177); Sleep(150);
	center(12, "Made by: Cedrick Joseph H. Mariano"); Sleep(150);
	center(13, "BSIT 1-1"); Sleep(150);
	getch();
}

// Function to display a moving droid animation
void droid() {
	int x = 0;
	system("cls");

	for (int i = 0; i != 1; i++) {
		for (x = 0; x <= 30; x++) {
			printf(BOLD WHITE);
			clearportion(7, 3, 60, 19); Sleep(100);
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
			printf(YELLOW);
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
	gotoxy(50, 10); p(". "); Sleep(400); p(". "); Sleep(400); p(". "); Sleep(400); p(". "); Sleep(400);
	printf(RESET);
	clearportion(28, 6, 59, 14);
}

// Additional functions for animations (century20th, moon, tc14, yoda, at_atwalker, kuromi, luffy) follow the same structure.
// Each function should be formatted similarly with proper indentation and concise comments.

main() {
	// Main function to display initial animation and summary
	printf(CYAN);
	printxy(12, 5, "####");
	printxy(11, 6, "{\"O O}");
	printxy(12, 7, "{ =}");
	printxy(9, 8, "{~~   //~}");
	printxy(8, 9, "{{~{  //}~}}");
	printxy(8, 10, "{} {//   } {}");
	printxy(9, 11, "{}         {}");
	printf(RESET);
	printxy(3, 12, "-----------------------------------------===---------------");
	printxy(3, 13, "|                                                         |");
	printxy(3, 14, "|                                                         |");
	printxy(3, 15, "|                                                         |");
	printxy(3, 16, "|                                                         |");
	printxy(3, 17, "|                                                         |");
	printxy(3, 18, "|_________________________________________________________|");

	gotoxy(23, 6); putchar('<');
	box3(24, 3, 60, 9);
	printf(BOLD YELLOW);
	gotoxy(25, 5); Sleep(550); p("Total number of Students: ");
	// gotoxy(54, 5); Sleep(700); p("%d", total);
	gotoxy(25, 6); Sleep(550); p("Total number of Students Passed: ");
	// gotoxy(56, 6); Sleep(700); p("%d", passed);
	gotoxy(25, 7); Sleep(550); p("Total number of Students Failed: ");
	// gotoxy(56, 7); Sleep(700); p("%d", failed);
	printf(RESET);
}
