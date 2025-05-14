/**
 * This program defines a structure `Test` to store the name and age of members.
 * It initializes the structure with names, takes user input for ages, and modifies
 * the ages using a function. The program then displays the current and updated ages.
 *
 * Functions:
 * - pass_struct: Modifies the age of members in the structure array by adding 5 years.
 */

 #include <stdio.h>

// Define a structure named Test
struct Test
{ 
	char name[10]; // Name of the member
	int age;       // Age of the member
} sv[2] = {{"neji"}, {"hinata"}}; // Initialize the structure array with names

// Function to modify the age of members in the structure array
void pass_struct(struct Test x[])
{ 
	int z;
	for (z = 0; z < 2; z++) // Loop through the array (0 to 1)
	{ 
		x[z].age += 5; // Add 5 years to the age of each member
	}
}

int main() // Corrected: Added return type for main
{
	int z;

	// Input ages for the members
	puts("Enter Neji's age: ");
	scanf("%d", &sv[0].age); // Read age for Neji
	puts("Enter Hinata's age: ");
	scanf("%d", &sv[1].age); // Read age for Hinata

	// Display current ages of the members
	puts("Member's age at present");
	printf("Name\tAge");
	for (z = 0; z < 2; z++) // Loop through the array (0 to 1)
	{ 
		printf("\n%s", sv[z].name); // Print name
		printf("\t%d", sv[z].age);  // Print age
	}

	// Call the function to modify the ages
	pass_struct(sv);

	// Display ages of the members 5 years from now
	printf("\nMember's age 5 years from now");
	for (z = 0; z < 2; z++) // Loop through the array (0 to 1)
	{ 
		printf("\n%s", sv[z].name); // Print name
		printf("\t%d", sv[z].age);  // Print updated age
	}

	return 0; // Corrected: Added return statement for main
}
