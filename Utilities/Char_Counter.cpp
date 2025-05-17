/**
 * Program to count the number of characters in a user-inputted phrase.
 * Loops continuously until terminated manually.
 */

#include<header.h>

int main() {
    int x = 0; // Loop control variable
    char phrase[100]; // Buffer to store the input phrase

    while (x != 1) {
        gets(phrase); // Read user input (unsafe, consider using fgets in modern code)
        printf("%d", strlen(phrase)); // Print the length of the input phrase
        getch(); // Wait for a key press
        system("cls"); // Clear the screen
    }

    return 0; // Return success
}
