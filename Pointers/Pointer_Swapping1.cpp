#include <stdio.h>
#define p printf

// Function to perform a "legit swap" operation
void legitswap(int *a, int *b, int c) {
	*a = c;         // Assign the value of c to *a
	*b = *a + c;    // Assign the sum of *a and c to *b
	c = *a + *b;    // Update c to the sum of *a and *b
}

int main() {
	int a = 5, b = 2, c = 6;

	// Print original values
	p("\nOriginal values:");
	p("\na = %d | b = %d | c = %d", a, b, c);

	// Perform the first legitswap operation
	legitswap(&a, &b, c);
	p("\n\nAfter first legitswap:");
	p("\na = %d | b = %d | c = %d", a, b, c);

	// Perform the second legitswap operation
	legitswap(&c, &b, a);
	p("\n\nAfter second legitswap:");
	p("\na = %d | b = %d | c = %d", a, b, c);

	// Perform the third legitswap operation
	legitswap(&b, &a, c);
	p("\n\nAfter third legitswap:");
	p("\na = %d | b = %d | c = %d", a, b, c);

	// Perform the fourth legitswap operation
	legitswap(&c, &a, b);
	p("\n\nAfter fourth legitswap:");
	p("\na = %d | b = %d | c = %d", a, b, c);

	// Perform the fifth legitswap operation
	legitswap(&a, &a, a);
	p("\n\nAfter fifth legitswap:");
	p("\na = %d | b = %d | c = %d", a, b, c);

	return 0; // Indicate successful program termination
}
