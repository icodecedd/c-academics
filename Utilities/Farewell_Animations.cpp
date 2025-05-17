/**
 * @file omki.cpp
 * @brief A simple program that displays a graphical interface and a farewell message.
 */

#include <header.h>
#include <Utility.h>

int main() {
	// Display graphical interface using the center function
	center(1, "");
	center(2, "");
	center(3, "");
	center(4, "");
	center(5, "");
	center(6, "");
	center(7, "");
	center(8, "\\ ___ \\                                                                            / ___ /");
	center(9, " |     |                                                                          |     |");
	center(10, " | --- |                                                                          | --- |");
	center(11, " |     |                                                                          |     |");
	center(12, " | --- |                                                                          | --- |");
	center(13, " |     |          ______________________________________________________          |     |");
	center(14, " | --- |        /   __________________________________________________   \\        | --- |");
	center(15, " |     |      /   /            -====                  ===-             \\   \\      |     |");
	center(16, " | --- |     /   /             ~~O O                  O o\"\"             \\   \\     | --- |");
	center(17, " |     |    /   /           ___\\ _ /___            ___\\ _ /___           \\   \\    |     |");
	center(18, " | --- |   /   /___________/ ___\\ / ___\\___________/ |__ || __|\\__________\\   \\   | --- |");
	center(19, "__________/____________________________________________________________________\\__________");

	// Display farewell message using the printxy function
	printxy(20, 5, "+------------------------------------------------+");
	printxy(20, 6, "�                                                �");
	printxy(20, 7, "�        Thank you for using our program!        �");
	printxy(20, 8, "�         We hope to see you again soon.         �");
	printxy(20, 9, "�                    Goodbye!                    �");
	printxy(20, 10, "�                                                �");
	printxy(20, 11, "+------------------------------------------------+");

	// Wait for user input before exiting
	getch();

	return 0;
}
