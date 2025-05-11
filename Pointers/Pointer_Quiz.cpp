#include <stdio.h>
#define p printf
#define s scanf

// Problem 1: Function to print multiples of 'a' from 'a' to 'b'
void pass(int a, int b)
{
	int c;
	for (c = a; c <= b; c += a) // Loop to print multiples of 'a'
		p("%d ", c); // Print each multiple followed by a space
	p("\n"); // Print a newline after each call
}

int main() // Added return type 'int' for main
{
	pass(1, 5);   // Prints: 1 2 3 4 5
	pass(5, 15);  // Prints: 5 10 15
	pass(2, 10);  // Prints: 2 4 6 8 10
	pass(1, 1);   // Prints: 1
	pass(15, 45); // Prints: 15 30 45
	return 0; // Added return statement for main
}

//-----------------------------------------------//

// Problem 2: Function to perform arithmetic operations based on a character input
/*
void test(char a, int b, int c)
{
	switch (a)
	{
		case 'b': p("\n%d", b * c); break; // Multiplication
		case 'd': p("\n%d", b / c); break; // Division
		case 'a': p("\n%d", b + c); break; // Addition
		case 'c': p("\n%d", b - c); break; // Subtraction
		default: p("\ninvalid call"); // Invalid input
	}
}

int main() // Added return type 'int' for main
{
	test('a', 5, 10);  // Prints: 15
	test('b', 10, 5);  // Prints: 50
	test('c', 25, 25); // Prints: 0
	test('d', 625, 25);// Prints: 25
	test('e', 5, 10);  // Prints: invalid call
	return 0; // Added return statement for main
}
*/

//-----------------------------------------------//

// Problem 3: Demonstrating the behavior of global, static, and local variables
/*
int x = 5; // Global variable

void c1() {
	x++; // Increment global variable
	p("\n%d", x);
}

void c2() {
	static int x = 5; // Static variable, retains its value between calls
	p("\n%d", x);
	x -= 2; // Decrement static variable
}

void c3() {
	x -= 2; // Decrement global variable
}

int main() // Added return type 'int' for main
{
	int x = 2; // Local variable
	p("\n%d", x); // Prints: 2 (local x)
	c1();        // Prints: 6 (global x incremented)
	c3();        // Decrements global x to 4
	p("\n%d", x); // Prints: 2 (local x remains unchanged)
	c2();        // Prints: 5 (static x initialized)
	c2();        // Prints: 3 (static x decremented)
	c2();        // Prints: 1 (static x decremented)
	p("\n%d", x); // Prints: 2 (local x remains unchanged)
	c3();        // Decrements global x to 2
	c1();        // Prints: 3 (global x incremented)
	p("\n%d", x); // Prints: 2 (local x remains unchanged)
	return 0; // Added return statement for main
}
*/
