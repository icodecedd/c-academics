#include <stdio.h> // Corrected header inclusion
#define p printf
#define s scanf

// Function to demonstrate pass by value
void pass_by_value(int x)
{
	x += 5; // Modifies the local copy of x
}

// Function to demonstrate pass by reference
void pass_by_ref(int *x) // Function accepts a pointer
{
	*x += 5; // Modifies the value at the address of x
}

// Function to demonstrate swapping without pointers (ineffective)
void fakeswap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp; // Changes are local to this function
}

// Function to demonstrate swapping using pointers (effective)
void legitswap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; // Swaps the values at the addresses of a and b
}

int main() // Added return type for main
{
	int x = 10, y = 10;

	// Demonstrating pass by value
	printf("x before any function call: %d", x);
	pass_by_value(x); // Function call by value
	printf("\nx after function call by value: %d", x);

	// Demonstrating pass by reference
	pass_by_ref(&x); // Function call by reference
	printf("\nx after function call by reference: %d", x);

	// Demonstrating swapping
	printf("\nOriginal value x = %d, y = %d", x, y);
	legitswap(&x, &y); // Swapping using pointers
	printf("\nNew value x = %d, y = %d", x, y);

	return 0; // Added return statement
}

//---------------AVERAGE-------------------//
// Function to calculate the average of two numbers
// void average(float a, float b, float *aver)
// { 
//     *aver = (a + b) / 2; // Stores the average in the address pointed by aver
// }
// int main()
// {
//     float a, b, aver = 0;
//     p("Enter 1st number: "); s("%f", &a);
//     p("Enter 2nd number: "); s("%f", &b);
//     average(a, b, &aver); // Passing address of aver
//     p("Average is %.2f", aver);
//     return 0; // Added return statement
// }