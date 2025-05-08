#include <stdio.h>

int main() {
    int n[] = {33, 2, 70, 4, 52, 42, 8, 35, 9, 211}; 
    int even[10], odd[10]; // Arrays to store even and odd numbers

    // Requirement A: Separate even and odd numbers
    for(int i = 0; i < 10; i++) {
        if (n[i] % 2 == 0) {
            even[i] = n[i];
        } else {
            odd[i] = n[i];
        }
    }

    // Requirement B: Display the highest number in the array (without sorting)
    int highest = n[0];; 

    for (int i = 0; i < 10; i++) {
        if (n[i] > highest) {
            highest = n[i]; // Update highest if current number is greater
        }
    }
    printf("Highest number in the array: %d\n", highest);

    // Requirement C: Display the lowest number in the array
    int lowest = n[0];

    for (int i = 0; i < 10; i++) {
        if (n[i] < lowest) {
            lowest = n[i]; // Update lowest if current number is smaller
        }
    }
    printf("Lowest number in the array: %d\n", lowest);

    //Requirement D: Sort the numbers in ascending order
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (n[i] > n[j]) {
                int temp = n[i]; // Swap elements if they are in the wrong order
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", n[i]); // Print sorted array
    }
    printf("\n");
}
