/*
 * ASCII_Character.cpp
 * This program displays ASCII characters and their corresponding values.
 * It uses gotoxy to position the cursor and clears the screen after displaying a set of characters.
 */

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define p printf

// Function to move the cursor to a specific position on the console
void gotoxy(int x, int y) {
	HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD row;
	row.X = x;
	row.Y = y;
	SetConsoleCursorPosition(col, row);
}

int main() {
	int x, row = 2;

	// Loop through ASCII values from 1 to 250
	for (x = 1; x <= 250; x++) {
		gotoxy(5, row); // Move cursor to position
		p("this is ascii # %d %c", x, x); // Print ASCII value and character
		row++;

		// Clear screen and reset row after displaying 18 characters
		if (row == 20) {
			row = 2;
			getch(); // Wait for user input
			system("cls"); // Clear the screen
		}
	}

	getch(); // Wait for final user input before exiting
	return 0;
}
