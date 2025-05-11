#include <header.h> // Include necessary header file

// Function to modify values using pointers
void pass1(int *a, int *b, int c) {
	*a = c;          // Assign the value of c to the variable pointed by a
	*b = *a + c;     // Assign the sum of *a and c to the variable pointed by b
	c = *a + *b;     // Update c to the sum of *a and *b
}

int main() {
	int a = 5, b = 2, c = 6;

	// Call pass1 and print the values of a, b, and c
	pass1(&a, &b, c);
	p("\na=%d b=%d c=%d", a, b, c);

	pass1(&c, &b, a);
	p("\na=%d b=%d c=%d", a, b, c);

	pass1(&b, &a, c);
	p("\na=%d b=%d c=%d", a, b, c);

	pass1(&c, &a, b);
	p("\na=%d b=%d c=%d", a, b, c);

	pass1(&a, &a, a);
	p("\na=%d b=%d c=%d", a, b, c);

	return 0; // Return 0 to indicate successful execution
}
