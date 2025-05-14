/**
 * This program demonstrates the use of structures in C to manage and display
 * student records, including their scores, total items, transmuted grades, 
 * and remarks based on their performance.
 */

#include <stdio.h>
#include <windows.h>
#include <string.h> // Include for strcpy function

// Define a structure to hold the record of each student
struct Record {
    char name[10]; // Name of the student
    int score;     // Score obtained
    int items;     // Total items
};

int main() {
    // Initialize an array of records
    struct Record records[5] = {
        {"flash", 6, 15},   
        {"batman", 7, 15},
        {"aquaman", 8, 15},
        {"superman", 9, 15},
        {"hawkgirl", 5, 15} 
    };

    // Print table header
    printf("\n#  Name\t\tScore\tItems\t TG\tRemarks\n");

    // Loop through each record to calculate and display results
    for (int x = 0; x < 5; x++) {
        // Calculate the transmuted grade
        float transmutedGrade = (float)records[x].score * 50 / records[x].items + 50;

        // Determine remarks based on the transmuted grade
        char remarks[10];
        if (transmutedGrade >= 75.0) {
            strcpy(remarks, "Passed");
        } else {
            strcpy(remarks, "Failed");
        }

        // Print the details of the current record
        printf("%d. %s\t  %d\t %d\t%.2f\t%s\n", 
               x + 1, 
               records[x].name, 
               records[x].score, 
               records[x].items, 
               transmutedGrade, 
               remarks);
    }

    return 0;
}
