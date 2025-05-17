/**
 * @file Kuromi_Animations.cpp
 * @brief A program that displays ASCII art and prompts the user for input.
 */

#include <Utility.h> // Replace with your utility header
#include <stdio.h>
#include <windows.h>

// Color definitions
#define MAGENTA     "\x1b[35m"
#define WHITE       "\x1b[37m"
#define YELLOW      "\x1b[33m"
#define RESET       "\x1b[0m"

int main() {
	// Display the first ASCII art block in yellow
	printf(YELLOW); // Set text color to yellow
	center(8, "_____                                     _____");
	center(9, "( ___ )-----------------------------------( ___ )");
	center(10, "|   |                                     |   |");
	center(11, "|   |  _  ___   _ ____   ___  __  __ ___  |   |");
	center(12, "|   | | |/ / | | |  _ \\ / _ \\|  \\/  |_ _| |   |");
	center(13, "|   | | ' /| | | | |_) | | | | |\\/| || |  |   |");
	center(14, "|   | | . \\| |_| |  _ <| |_| | |  | || |  |   |");
	center(15, "|   | |_|\\_\\\\___/|_| \\_\\\\___/|_|  |_|___| |   |");
	center(16, "|___|                                     |___|");
	center(17, "(_____)-----------------------------------(_____)");
	printf(RESET); // Reset text color

	// Prompt the user to continue
	center(19, "Wanna Continue? >>> ");
	gotoxy(51, 19);
	getch();

	// Clear the screen and display the second ASCII art block in white
	system("cls");
	printf(WHITE); // Set text color to white
	center(2, ".:.                                         ");
	center(3, "###.                                        ");
	center(4, ".:*%#+=-.                                   ");
	center(5, ".%####%#*=-.             .--------:::::++:");
	center(6, "+########## :=++****++==%###########%#**:");
	center(7, ".%#######%%%############%%%%#######%=");
	center(8, "+#####%%########**########%%#####*.");
	center(9, ":%%#%%#######*------*#######%%##-");
	center(10, ".=%########+++--*=*########%+");
	center(11, "*#######++*#+++*#*=*#######+");
	center(12, "#####*=.    :--.    -+#####+");
	center(13, "+###* :@%.        =%# :%##%:");
	center(14, "*%#= .#*    :.   :#+  ##%=");
	center(15, ":+#:       -:       =#+.");
	center(16, ".=+*=.-**=--::-...:-=**:=+:");
	center(17, ":-+#%%#++#%#######%%########++%#+:");
	center(18, ":...-##%*=*#-=#*+: .++##.*%*#%#+---");
	center(19, "-.  ::  ++ .:  - --- .-. .-");
	center(20, "-       :.  -.::  -       -");
	center(21, ".-     :-    --   =:.    ::");
	center(22, "::..:. ::.:.::.:  ::.::.");
	printf(RESET); // Reset text color

	// Display additional messages with delays
	Sleep(700);
	printxy(60, 9, MAGENTA "\"I`m not a bad girl\"" RESET);
	Sleep(800);
	printxy(7, 14, MAGENTA "\"Tee-hee-hee!\"" RESET);

	// Wait for user input before exiting
	getch();

	return 0;
}
