#include <stdio.h>
#include <string.h>

// Custom implementation of strrev() - Function to reverse a string
void strrev_string(char *str) {
    int length = strlen(str); // Get the length of the string
    char temp;
    for (int i = 0; i < length / 2; i++) { // Swap characters from both ends
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str1[20] = "Hello"; // Initialize str1
    char str2[20] = "World"; // Initialize str2
    char buffer[50]; // Buffer to hold concatenated strings

    // strlen() - Calculates the length of a string
    printf("Length of str1: %lu\n", strlen(str1));

    // strcpy() - Copies one string to another
    strcpy(buffer, str1); // Copy str1 into buffer
    printf("strcpy: %s\n", buffer);

    // strcat() - Concatenates two strings
    strcat(buffer, " "); // Append a space to buffer
    strcat(buffer, str2); // Append str2 to buffer
    printf("strcat: %s\n", buffer);

    // strcmp() - Compares two strings
    int cmp = strcmp(str1, str2); // Compare str1 and str2
    if (cmp < 0)
        printf("str1 is less than str2\n");
    else if (cmp > 0)
        printf("str1 is greater than str2\n");
    else
        printf("str1 is equal to str2\n");

    // strchr() - Locates the first occurrence of a character in a string
    char *ptr = strchr(str1, 'l'); // Find the first occurrence of 'l' in str1
    if (ptr != NULL)
        printf("First occurrence of 'l' in str1: %s\n", ptr);
    else
        printf("'l' not found in str1\n");

    // strstr() - Locates the first occurrence of a substring in a string
    ptr = strstr(buffer, "World"); // Find the substring "World" in buffer
    if (ptr != NULL)
        printf("Substring 'World' found in buffer: %s\n", ptr);
    else
        printf("Substring 'World' not found in buffer\n");

    // strncpy() - Copies a certain amount of characters from one string to another
    char src[40] = "Copy this string partially"; // Source string
    char dest[12]; // Destination buffer
    strncpy(dest, src, 11); // Copy first 11 characters from src to dest
    dest[11] = '\0'; // Ensure null-termination
    printf("strncpy: %s\n", dest);

    // strncat() - Concatenates a certain amount of characters from one string to another
    strncat(dest, "and more", 5); // Append first 5 characters of "and more" to dest
    printf("strncat: %s\n", dest);

    // strncmp() - Compares a certain amount of characters between two strings
    cmp = strncmp(str1, str2, 3); // Compare first 3 characters of str1 and str2
    if (cmp < 0)
        printf("First 3 characters of str1 are less than first 3 characters of str2\n");
    else if (cmp > 0)
        printf("First 3 characters of str1 are greater than first 3 characters of str2\n");
    else
        printf("First 3 characters of str1 are equal to first 3 characters of str2\n");

    return 0;
}
