/**
 * Utility_Tester.cpp
 * Demonstrates the usage of utility functions for drawing boxes, 
 * filling the screen, and printing text.
 */

#include <Utility.h>

int main() {
	// Draw a box with specific dimensions and border style
	box1(2, 2, 78, 24, 232);

	// Draw another box inside the first one
	box2(4, 4, 76, 22);

	// Draw a third box inside the second one
	box3(6, 6, 74, 20);

	// Fill a portion of the screen with a specific pattern
	fillscreen(7, 7, 73, 19, 178);

	// Clear a portion of the screen
	clearportion(9, 9, 71, 17);

	// Print centered text at a specific line
	center(10, "Testing of header file");

	// Print text at specific coordinates
	printxy(11, 11, "pup san juan");

	// Wait for a key press
	getch();

	// Clear the screen
	system("cls");

	return 0;
}
