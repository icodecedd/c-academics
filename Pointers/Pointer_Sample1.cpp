#include <header.h>

// Function to modify values based on pointers
void value(int *a, int *b, int *c) {
	*a = *c;          // Assign the value of *c to *a
	*b = (*a) * (*c); // Assign the product of *a and *c to *b
	*c += 3;          // Increment *c by 3
}

int main() {
	int a = 2, b = 1, c = 2;

	// First call to value function
	value(&b, &a, &c); 
	printf("%d %d %d", a, b, c); // Print the values of a, b, and c

	// Second call to value function
	value(&a, &c, &b);
	printf("\n\n%d %d %d", a, b, c); // Print the updated values of a, b, and c

	// Third call to value function
	value(&c, &b, &a);
	printf("\n\n%d %d %d", a, b, c); // Print the final values of a, b, and c

	return 0; // Indicate successful program termination
}
