#include <stdio.h>

// Function to get a number from the user and return it
double Square() { 

	double num;
	printf("Enter a number: "); 
	scanf("%lf", &num); 
	return num; // Return the inputted value to the calling function
}

int main() {
	double number = 0;
	number = Square(); // Call the Square function and store the returned value in 'number'
	
	printf("The square of the number is %.2lf\n", number * number);
	return 0; 
}
