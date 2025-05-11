#include <stdio.h>

// Function to modify the values of a, b, and c
void f1(int *a, int *b, int c) {
	*a += 2;          // Increment the value pointed by 'a' by 2
	*b += 5;          // Increment the value pointed by 'b' by 5
	c = *a + *b;      // Update 'c' (local to this function) with the sum of *a and *b
}

int main() {
	int x = 5, y = 4, c = 2;

	// Call f1 with addresses of x, y, and value of c
	f1(&x, &y, c);  
	printf("\n%d %d %d", x, y, c); // Output: 7 9 2
	// Note: 'c' remains unchanged in main because it is passed by value

	// Call f1 with addresses of c, x, and value of y
	f1(&c, &x, y);   
	printf("\n%d %d %d", x, y, c); // Output: 12 9 4
	// Note: 'c' is modified because it is passed by reference

	/*
	// Uncomment this block to test further
	f1(&y, &c, x);  
	printf("\n%d %d %d", x, y, c); // Output: x = 12, y = 11, c = 9
	*/

	return 0; // Indicate successful program termination
}
