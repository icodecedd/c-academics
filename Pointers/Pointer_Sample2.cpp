#include <header.h> // Include necessary header file

// Function to modify values pointed by a and b, and update c
void f1(int *a, int *b, int c)
{
	*a += 2;           // Increment the value pointed by a by 2
	*b += 5;           // Increment the value pointed by b by 5
	c += *a + *b;      // Update c with the sum of *a and *b
}

int main()
{
	int x = 5, y = 4, c = 2;

	// Call f1 with addresses of x, y, and value of c
	f1(&x, &y, c);
	printf("\n x: %d   | y: %d   | c: %d", x, y, c);

	// Call f1 with addresses of c, x, and value of y
	f1(&c, &x, y);
	printf("\n c: %d   | x: %d   | y: %d", c, x, y);

	// Call f1 with addresses of y, c, and value of x
	f1(&y, &c, x);
	printf("\n y: %d   | c: %d   | x: %d", y, c, x);

	return 0; // Return 0 to indicate successful execution
}
