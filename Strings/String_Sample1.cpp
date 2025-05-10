#include <stdio.h>
#include <string.h>

// Note: Some functions like `strrev`, `strupr`, `stricmp`, and `gets` are non-standard or deprecated.
// Consider using standard alternatives for better portability and safety.

int main() {
	char word1[80] = "the quick ";
	char word2[80] = "brown fox";
	char word3[80];
	char word4[80] = "therapist";
	char word5[80] = "the ";
	int x;

	// Calculate the length of word5
	x = strlen(word5); // strlen returns the length of the string
	printf("Length of word5: %d\n", x);

	// Copy word1 into word3
	strcpy(word3, word1); // strcpy copies the content of word1 into word3
	printf("word3 after strcpy: ");
	puts(word3);

	// Concatenate word1 and word2
	strcat(word1, word2); // strcat appends word2 to word1
	printf("word1 after strcat: ");
	puts(word1);

	// Concatenate first 9 characters of word2 to word5
	strncat(word5, word2, 9); // strncat appends at most 9 characters of word2 to word5
	printf("word5 after strncat: ");
	puts(word5);

	// Reverse word2 and print the first character
	// Note: strrev is non-standard. If unavailable, implement a custom reverse function.
	strrev(word2); // strrev reverses the string
	printf("First character of reversed word2: ");
	putchar(word2[0]); // Print the first character of the reversed word2
	printf("\n");

	// Convert word1 to uppercase
	// Note: strupr is non-standard. If unavailable, implement a custom uppercase function.
	strupr(word1); // strupr converts the string to uppercase
	printf("word1 after strupr: ");
	puts(word1);

	// Compare word3 and word1 ignoring case
	// Note: stricmp is non-standard. Use strcasecmp on POSIX systems or _stricmp on Windows.
	x = stricmp(word3, word1); // stricmp compares two strings ignoring case
	printf("Comparison result of word3 and word1 (case-insensitive): %d\n", x);

	// Print every second character of word4, skipping 4 characters
	printf("Every second character of word4, skipping 4 characters: ");
	for (x = 0; x <= strlen(word4) - 4; x += 2) // Loop through word4 with a step of 2
		putchar(word4[x]);
	printf("\n");

	// Print all characters of word1
	printf("All characters of word1: ");
	for (x = 0; x <= strlen(word1) - 1; x++) // Loop through word1
		putchar(word1[x]);
	printf("\n");

	// Read a new string into word1
	// Note: gets is deprecated and unsafe. Use fgets instead.
	printf("Enter a new string for word1: ");
	fgets(word1, sizeof(word1), stdin); // fgets reads a line of input into word1
	word1[strcspn(word1, "\n")] = '\0'; // Remove trailing newline character
	printf("word1 after input: ");
	puts(word1);

	// Uncommented code for additional exercises
	/*
	// #1 PART 4
	int x, y;
	char exam[5] = "bsit";
	for (x = 0; x <= strlen(exam) - 1; x++) {
		for (y = 0; y <= x; y++)
			putchar(exam[x]);
		printf("\n");
	}
	// #2 
	for (x = strlen(exam) - 1; x >= 0; x--) {
		for (y = 0; y <= x; y++)
			putchar(exam[y]);
		printf("\n");
	}
	// #3 
	for (x = strlen(exam) - 1; x >= 0; x--) {
		for (y = x; y >= 0; y--)
			putchar(exam[y]);
		printf("\n");

	}
	*/

	return 0; 
}