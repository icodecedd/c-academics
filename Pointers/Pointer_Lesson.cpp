#include <header.h>
#define p printf
#define s scanf

// POINTERS - A variable that stores the memory address
// & - Unary operator that returns the memory address of its operand
// * - The "indirection operator" which returns the value of the variable
// Default int is considered as long integer
// long integer - occupies 4 bytes of memory
// short integer - occupies 2 bytes of memory
// char - occupies 1 byte of memory
// float - occupies 4 bytes of memory
// double - occupies 8 bytes of memory

main() {
	// Declare integer pointers
	int *ptr1, *ptr2;
	int x = 5, y = 10;

	// Assign memory addresses of x and y to pointers
	ptr1 = &x;
	ptr2 = &y;

	// Print memory addresses of x and y
	p("\nMemory address of x is %d", ptr1);
	p("\nMemory address of y is %d", ptr2);

	// Modify values of x and y using pointers
	*ptr1 += 3;
	*ptr2 += 5;

	// Print updated values of x and y
	p("\nValue of x is %d", *ptr1);
	p("\nValue of y is %d", *ptr2);

	// Declare char pointers
	char *ptr3, *ptr4;
	char a = 'a', b = 'b';

	// Assign memory addresses of a and b to pointers
	ptr3 = &a;
	ptr4 = &b;

	// Print memory addresses of a and b
	p("\nMemory address of a is %d", ptr3);
	p("\nMemory address of b is %d", ptr4);

	// Declare float pointers
	float *ptr5, *ptr6;
	float c = 1.5, d = 2.5;

	// Assign memory addresses of c and d to pointers
	ptr5 = &c;
	ptr6 = &d;

	// Print memory addresses of c and d
	p("\nMemory address of c is %d", ptr5);
	p("\nMemory address of d is %d", ptr6);

	// Modify values of c and d using pointers
	*ptr5 += 3.5;
	*ptr6 += 5.5;

	// Print updated values of c and d
	p("\nValue of c is %f", *ptr5);
	p("\nValue of d is %f", *ptr6);

	// Declare double pointers
	double *douptr1, *douptr2;
	double e = 2.5, f = 4.5;

	// Assign memory addresses of e and f to pointers
	douptr1 = &e;
	douptr2 = &f;

	// Print memory addresses of e and f
	p("\nMemory address of e is %d", douptr1);
	p("\nMemory address of f is %d", douptr2);

	// Modify values of e and f using pointers
	*douptr1 += 5.5;
	*douptr2 += 7.5;

	// Print updated values of e and f
	p("\nValue of e is %f", *douptr1);
	p("\nValue of f is %f", *douptr2);
}
