#include <stdio.h>

int main() {
	// Declare an integer variable and assign a value
	int a;
	a = 10;

	// Declare a pointer to an integer and assign it the address of 'a'
	int *p_a;
	p_a = &a;

	// Print the value of 'a'
	printf("%d\n", a);

	// Print the memory address stored in the pointer 'p_a'
	printf("%p\n", (void *)p_a);

	// Print the value at the memory address stored in 'p_a'
	printf("%d\n", *p_a);

	/*
	Notes for pointers:
	- '&' gives the memory address of a variable.
	- '*' gives the value at the memory address.
	Syntax for declaring a pointer:
		(datatype) *(pointer name);
		Example: int *p_a;
	Assigning value to a pointer:
		p_a = &a;
	*/

	// Declare another integer variable and a pointer
	int num = 10;   // Declare an integer variable and assign a value
	int *ptr;       // Declare a pointer variable

	// Assign the address of 'num' to the pointer 'ptr'
	ptr = &num;

	// Print the value of 'num' using the pointer
	printf("Value of num using pointer: %d\n", *ptr);

	// Print the address of 'num'
	printf("Address of num: %p\n", (void *)&num);

	// Print the value of 'ptr' (which is the address of 'num')
	printf("Value of ptr (address of num): %p\n", (void *)ptr);

	// Modify the value of 'num' indirectly through the pointer
	*ptr = 20;
	printf("Modified value of num: %d\n", num);

	return 0;
}
