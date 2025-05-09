#include <stdio.h>

// Function to find the lowest number in the array
int lowest(int arr[], int size) {
    int min = arr[0]; // Assume the first element as the minimum
    
    // Iterate through the array to find the minimum
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) { 
            min = arr[i];
        }
    }
    return min; // Return the smallest number
}

// Function to find the highest number in the array
int highest(int arr[], int size) {
    int max = arr[0]; // Assume the first element as the maximum
    
    // Iterate through the array to find the maximum
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) { 
            max = arr[i];
        }
    }
    return max; // Return the largest number
}

int main() {
    // Array containing 10 integers
    int numbers[10] = {10, 5, 3, 7, 15, 20, 8, 2, 11, 6};
    
    // Print the original list of numbers
    printf("Original list of numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]); 
    }
    printf("\n");
    
    // Find the lowest number in the array
    int min = lowest(numbers, 10);
    printf("Lowest number: %d\n", min); 
    
    // Find the highest number in the array
    int max = highest(numbers, 10);
    printf("Highest number: %d\n", max); 

    return 0; 
}
