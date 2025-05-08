#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <dos.h> // Note: <dos.h> is not supported in modern compilers. Consider removing it if unnecessary.

int main()
{
	int mama; // Variable to store results of string operations
	char word1[20] = "ahldrn", word2[20] = "santos", word3[20]; // Initialize strings
	char words[80]; // Unused variable, can be removed if not needed

	// Uncommented and fixed code with proper comments:

	// Display the first word
	puts(word1);

	// strlen = count the length of the string
	mama = strlen(word2);
	printf("Length of word2: %d\n", mama);

	// strcpy = copy a string to another variable
	strcpy(word3, word1);
	printf("Copied word1 to word3: ");
	puts(word3);

	// strupr = turn a string into uppercase
	strupr(word3);
	printf("Uppercase word3: ");
	puts(word3);

	// strlwr = turn a string into lowercase
	strlwr(word3);
	printf("Lowercase word3: ");
	puts(word3);

	// stricmp = compare two strings (case-insensitive)
	strupr(word3); // Convert word3 to uppercase for comparison
	mama = stricmp(word1, word3);
	printf("Case-insensitive comparison of word1 and word3: %d\n", mama);

	// strcmp = compare two strings (case-sensitive)
	mama = strcmp(word1, word3);
	printf("Case-sensitive comparison of word1 and word3: %d\n", mama);

	// strncat = concatenate strings (up to a specified length)
	strncat(word1, word2, 6); // Combine word1 and word2 (up to 6 characters of word2)
	printf("Concatenated word1 and word2: ");
	puts(word1);

	// strrev = reverse a string
	strrev(word1);
	printf("Reversed word1: ");
	puts(word1);

	return 0;
}
