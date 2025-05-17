/*
 * Utility_Header.cpp
 * This program provides utility functions for creating boxes, filling the screen,
 * clearing portions of the screen, and printing text at specific positions in the console.
 * It uses Windows-specific APIs for console manipulation.
 */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

// Moves the cursor to the specified (x, y) position in the console
void gotoxy(int x, int y) {
	HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD row;
	row.X = x;
	row.Y = y;
	SetConsoleCursorPosition(col, row);
}

// Draws a box with a specified character
void box1(int x1, int y1, int x2, int y2, char ch) {
	int x;
	for (x = x1; x <= x2; x++) {
		gotoxy(x, y1); putchar(ch);
		gotoxy(x, y2); putchar(ch);
	}
	for (x = y1; x <= y2; x++) {
		gotoxy(x1, x); putchar(ch);
		gotoxy(x2, x); putchar(ch);
	}
}

// Draws a box with double-line borders
void box2(int x1, int y1, int x2, int y2) {
	int x;
	for (x = x1; x <= x2; x++) {
		gotoxy(x, y1); putchar(205); // Horizontal line
		gotoxy(x, y2); putchar(205);
	}
	for (x = y1; x <= y2; x++) {
		gotoxy(x1, x); putchar(186); // Vertical line
		gotoxy(x2, x); putchar(186);
	}
	gotoxy(x1, y1); putchar(201); // Top-left corner
	gotoxy(x2, y1); putchar(187); // Top-right corner
	gotoxy(x1, y2); putchar(200); // Bottom-left corner
	gotoxy(x2, y2); putchar(188); // Bottom-right corner
}

// Draws a box with single-line borders
void box3(int x1, int y1, int x2, int y2) {
	int x;
	for (x = x1; x <= x2; x++) {
		gotoxy(x, y1); putchar(196); // Horizontal line
		gotoxy(x, y2); putchar(196);
	}
	for (x = y1; x <= y2; x++) {
		gotoxy(x1, x); putchar(179); // Vertical line
		gotoxy(x2, x); putchar(179);
	}
	gotoxy(x1, y1); putchar(218); // Top-left corner
	gotoxy(x2, y1); putchar(191); // Top-right corner
	gotoxy(x1, y2); putchar(192); // Bottom-left corner
	gotoxy(x2, y2); putchar(217); // Bottom-right corner
}

// Fills a rectangular area with a specified character
void fillscreen(int x1, int y1, int x2, int y2, char ch) {
	int col, row;
	for (col = x1; col <= x2; col++) {
		for (row = y1; row <= y2; row++) {
			gotoxy(col, row); putchar(ch);
		}
	}
}

// Clears a rectangular portion of the screen
void clearportion(int x1, int y1, int x2, int y2) {
	int col, row;
	for (col = x1; col <= x2; col++) {
		for (row = y1; row <= y2; row++) {
			gotoxy(col, row); putchar(' ');
		}
	}
}

// Prints a string at a specific (col, row) position
void printxy(int col, int row, char ch[]) {
	gotoxy(col, row); puts(ch);
}

// Centers a string horizontally on a specific row
void center(int row, char ch[]) {
	int col;
	col = (80 - strlen(ch)) / 2 + 1;
	gotoxy(col, row); puts(ch);
}

// Main function
int main() {
	// Fill the screen with a pattern
	fillscreen(2, 2, 78, 24, 178);
	fillscreen(4, 4, 76, 22, 232);
	clearportion(6, 6, 74, 20);

	// Draw nested boxes
	box1(7, 7, 73, 19, 178);
	box2(9, 9, 71, 17);
	box3(11, 11, 69, 15);

	getch();
	system("cls");

	// Centered text display
	center(5, "polytechnic");
	center(6, "university");
	center(7, "of the");
	center(8, "philippines");

	return 0;
}
