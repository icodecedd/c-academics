
/**
 * @file CURRENT_TIME.cpp
 * @brief A program to display the current time dynamically centered in a bordered box on the console.
 * 
 * This program uses Windows-specific console functions to manipulate the console window,
 * draw borders, and center text dynamically. It continuously updates the current time
 * every second and clears the screen to refresh the display.
 * 
 * Functions:
 * - gotoxy: Moves the cursor to a specified position in the console.
 * - line1_lw: Draws a centered box with specified width and height.
 * - line1: Draws a box with specified coordinates, scaled to the console dimensions.
 * - set_console_font_size: Adjusts the console font size.
 * - center_box: Draws a dynamically sized box centered in the console.
 * - print_bold: Prints text in bold style.
 * - center_dynamic: Centers and displays a string in the console.
 */

 //headers/ preprocessors
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

//global/ external declarations

void gotoxy(int x, int y)
{
    HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD row;
    row.X = x;
    row.Y = y;
    SetConsoleCursorPosition(col, row);
}
void line1_lw(int width, int height)
{
    // Get the current console window dimensions
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Calculate the new line positions and lengths based on the console dimensions
    int col1 = (console_width - width) / 2;
    int row1 = (console_height - height) / 2;
    int col2 = col1 + width - 1;
    int row2 = row1 + height - 1;

    // Draw the new line
    int x;
    for (x = col1; x <= col2; x++)
    {
        gotoxy(x, row1);
        putchar(196);
        gotoxy(x, row2);
        putchar(196);
    }
    for (x = row1; x <= row2; x++)
    {
        gotoxy(col1, x);
        putchar(179);
        gotoxy(col2, x);
        putchar(179);
    }
    gotoxy(col1, row1);
    putchar(218);
    gotoxy(col2, row1);
    putchar(191);
    gotoxy(col1, row2);
    putchar(192);
    gotoxy(col2, row2);
    putchar(217);
}

void line1(int col1, int row1, int col2, int row2)
{//left - upper, right - lower
    // Get the current console window dimensions
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Calculate the new line positions and lengths based on the console dimensions
    int new_col1 = (col1 * console_width) / 80;
    int new_row1 = (row1 * console_height) / 25;
    int new_col2 = (col2 * console_width) / 80;
    int new_row2 = (row2 * console_height) / 25;

    // Draw the new line
    int x;
    for (x = new_col1; x <= new_col2; x++)
    {
        gotoxy(x, new_row1);
        putchar(196);
        gotoxy(x, new_row2);
        putchar(196);
    }
    for (x = new_row1; x <= new_row2; x++)
    {
        gotoxy(new_col1, x);
        putchar(179);
        gotoxy(new_col2, x);
        putchar(179);
    }
    gotoxy(new_col1, new_row1);
    putchar(218);
    gotoxy(new_col2, new_row1);
    putchar(191);
    gotoxy(new_col1, new_row2);
    putchar(192);
    gotoxy(new_col2, new_row2);
    putchar(217);
}

void set_console_font_size(int size) {
    CONSOLE_FONT_INFOEX font_info;
    font_info.cbSize = sizeof(font_info);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font_info);
    font_info.dwFontSize.Y = size;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font_info);
}
void center_box(int width, int height)
{
    // Get the current console window dimensions
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Determine the larger dimension of the console window
    int larger_dim = console_width > console_height ? console_width : console_height;

    // Calculate the size of the box based on the larger dimension and the aspect ratio
    float aspect_ratio = (float)width / height;
    int new_size = (int)(larger_dim * 0.8);  // 80% of larger dimension
    int new_width = (int)(new_size * aspect_ratio);
    int new_height = new_size;

    // If the calculated width is too large, reduce the size based on the larger dimension
    if (new_width > (int)(console_width * 0.8)) {
        new_width = (int)(console_width * 0.8);
        new_height = (int)(new_width / aspect_ratio);
    }

    // Calculate the position of the box in the center of the console window
    int col1 = (console_width - new_width) / 2;
    int row1 = (console_height - new_height) / 2;
    int col2 = col1 + new_width - 1;
    int row2 = row1 + new_height - 1;

    // Draw the box
    int x;
    for (x = col1; x <= col2; x++) {
        gotoxy(x, row1);
        putchar(196);
        gotoxy(x, row2);
        putchar(196);
    }
    for (x = row1; x <= row2; x++) {
        gotoxy(col1, x);
        putchar(179);
        gotoxy(col2, x);
        putchar(179);
    }
    gotoxy(col1, row1);
    putchar(218);
    gotoxy(col2, row1);
    putchar(191);
    gotoxy(col1, row2);
    putchar(192);
    gotoxy(col2, row2);
    putchar(217);
}



void print_bold(char* text) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    puts(text);
}
void center_dynamic(char ch[]) {

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int console_width, console_height, col, row;

    // get the console screen buffer information
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // calculate the column position to center the text
    col = (console_width - strlen(ch)) / 2 + 1;

    // calculate the row position to center the text
    row = (console_height / 2) - 1;

    // move the cursor to the specified row and column position
    COORD pos = {col, row};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    // display the text at the center of the screen
    puts(ch);
}

main() {
//this is the main function

while(1){
	
	 time_t t = time(NULL);
    struct tm *tm = localtime(&t);
  line1(20, 10, 60, 15);

center_dynamic(asctime(tm));

   	sleep(1);
   	system("cls"); 	
}
    return 0;
}
