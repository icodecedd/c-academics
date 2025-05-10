#include <stdio.h>  
#include <string.h> 

int main() {
	char word1[25]; // Array to store the input word
	char word2[25]; // Array to store the reversed word

	// Prompt the user to enter a word
	printf("Enter a word: ");
	gets(word1); 

	// Copy the original word to another array
	strcpy(word2, word1);

	// Reverse the original word
	strrev(word1);

	// Compare the reversed word with the original (case-insensitive)
	if (stricmp(word1, word2) == 0) {
		printf("\nThe Word is Palindrome\n");
	} else {
		printf("\nThe Word is not Palindrome\n");
	}

	return 0; // Indicate successful program termination
}
