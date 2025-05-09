#include <stdio.h> 
#define p printf // Define a macro `p` for convenience in printing

// Declare and define an external global variable `x`
extern int x = 2;

// Function f1: Demonstrates the use of an auto (local) variable
void f1() {
	int x = 5; 
	x++;
	p("\nx in f1 is %d", x); 
}

// Function f2: Modifies the global variable `x`
void f2() {
	x += 2; 
	p("\nx in f2 is %d", x); 
	x--; 
}

// Function f3: Demonstrates the use of a static variable
void f3() {
	static int x = 7; 
	x++;
	p("\nx in f3 is %d", x); 
}

// Main function: Entry point of the program
// Calls the functions f1, f2, and f3 in a specific order and prints the value of `x`
int main() {
	f2(); 
	f2(); 
	f1(); 
	x += 2; 
	f3(); 
	f1(); 
	f2(); 
	p("\nx in main is %d", x);
	f3(); 
	p("\n in main is %d", x); 
	f3();
	return 0; 
}
