#include <stdio.h>

// Function 1: Determines if a number is odd or even by taking input inside the function
void odd_even1() 
{
	int x;
	printf("Enter number for x: ");
	scanf("%d", &x);
	if (x % 2 == 0)
		printf("\nNumber is even\n");
	else
		printf("\nNumber is odd\n");
}

// Function 2: Determines if a number is odd or even using a parameter
void odd_even2(int x) 
{
	if (x % 2 == 0)
		printf("\nNumber is even\n");
	else
		printf("\nNumber is odd\n");
}

// Function 3: Determines if a number is odd or even by taking input inside the function and returning a result
int odd_even3() 
{
	int x;
	printf("Enter number for x: ");
	scanf("%d", &x);
	if (x % 2 == 0)
		return 0; // Return 0 for even
	else
		return 1; // Return 1 for odd
}

// Function 4: Determines if a number is odd or even using a parameter and returning a result
int odd_even4(int x) 
{
	if (x % 2 == 0)
		return 0; // Return 0 for even
	else
		return 1; // Return 1 for odd
}

int main()
{
	// Uncomment the desired function call to test

	// Function 1: Input and output handled inside the function
	// odd_even1();

	// Function 2: Input handled in main, output handled in the function
	// int x;
	// printf("Enter number for x: ");
	// scanf("%d", &x);
	// odd_even2(x);

	// Function 3: Input handled in the function, result returned to main
	// int result;
	// result = odd_even3();
	// if (result == 0)
	//     printf("\nNumber is even\n");
	// else
	//     printf("\nNumber is odd\n");

	// Function 4: Input handled in main, result returned to main
	// int x, result;
	// printf("Enter number for x: ");
	// scanf("%d", &x);
	// result = odd_even4(x);
	// if (result == 0)
	//     printf("\nNumber is even\n");
	// else
	//     printf("\nNumber is odd\n");

	return 0; 
}
