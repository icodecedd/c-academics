#include <stdio.h>

int main() {
    FILE *filePointer; // File pointer to handle file operations
    char data[100];    // Buffer to store data read from the file

    // Writing to a file
    filePointer = fopen("example.txt", "w"); // Open file in write mode
    if (filePointer == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(filePointer, "This is a sample text written to a file.\n");
    fclose(filePointer);
    printf("Data written to file successfully!\n");

    // Reading from a file
    filePointer = fopen("example.txt", "r");
    if (filePointer == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Reading data from file:\n");
    while (fgets(data, sizeof(data), filePointer) != NULL) {
        printf("%s", data);
    }
    fclose(filePointer);

    // Appending to a file
    filePointer = fopen("example.txt", "a");
    if (filePointer == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(filePointer, "This line is appended to the file.\n");
    fclose(filePointer);
    printf("Data appended to file successfully!\n");

    return 0;
}
