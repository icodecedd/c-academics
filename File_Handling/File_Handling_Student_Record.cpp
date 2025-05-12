#include <stdio.h>  // For file handling and standard I/O functions
#include <stdlib.h> // For system() and other utility functions
#include <conio.h>  // For getch() and getche()
#include <ctype.h>  // For toupper()
#include <utility.h> // Custom utility header (assumed)

char ans = ' ';
FILE *fp;

// Function to display a goodbye message and wait for a key press
void goodbye()
{
	printf("Goodbye!\n");
	getch();
}

// Function to add a new student record to the file
void addRecord()
{
	char StudNum[30], FN[30], LN[30];
	float MidTerm, Finals;

	// Open the file in append mode
	fp = fopen("studentRec.txt", "a");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		return;
	}

	system("cls"); // Clear the screen

	// Prompt user for input
	printf("You have selected option B: Adding a record to the text file\n");
	printf("Fill up the details:\n");
	printf("Student Number: ");
	scanf("%s", StudNum);
	printf("Last Name: ");
	scanf("%s", LN);
	printf("First Name: ");
	scanf("%s", FN);
	printf("Midterms: ");
	scanf("%f", &MidTerm);
	printf("Finals: ");
	scanf("%f", &Finals);

	// Write the record to the file
	fprintf(fp, "%s,%s,%s,%.2f,%.2f\n", StudNum, LN, FN, MidTerm, Finals);
	fclose(fp); // Close the file

	printf("Record added successfully!\n");
	system("pause"); // Wait for user input before clearing the screen
	system("cls");
}

// Function to display all student records from the file
void dispRec()
{
	char StudNum[30], FN[30], LN[30];
	float MidTerm, Finals;
	int x = 0;

	system("cls"); // Clear the screen

	// Open the file in read mode
	fp = fopen("studentRec.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file or file does not exist!\n");
		system("pause");
		return;
	}

	// Print table header
	printf("#  Student Name\t\tMidterms\tFinals\t\tAverage\n");
	printf("============================================================\n");

	// Read and display each record
	while (fscanf(fp, "%[^,],%[^,],%[^,],%f,%f\n", StudNum, LN, FN, &MidTerm, &Finals) != EOF)
	{
		printf("%d. %s %s\t\t%.2f\t\t%.2f\t\t%.2f\n", x + 1, FN, LN, MidTerm, Finals, (MidTerm + Finals) / 2);
		x++;
	}

	fclose(fp); // Close the file
	printf("Press any key to go back to the menu...\n");
	getch();
	system("cls");
}

// Function to create a new file (deletes existing records)
void newRecord()
{
	char ans2 = ' ';
	while (ans2 != 'Y' && ans2 != 'N')
	{
		printf("Warning: This will delete the current record. Continue? [Y/N]: ");
		ans2 = toupper(getch());
		if (ans2 == 'N')
		{
			printf("\nOperation canceled.\n");
		}
		else if (ans2 == 'Y')
		{
			// Open the file in write mode to overwrite it
			fp = fopen("studentRec.txt", "w");
			if (fp == NULL)
			{
				printf("Error creating file!\n");
				return;
			}
			fclose(fp); // Close the file
			printf("\nFile cleared successfully!\n");
			system("pause");
			system("cls");
		}
	}
}

// Function to display the main menu and handle user input
void mainScreen()
{
	system("cls"); // Clear the screen

	// Display menu options
	printf("Polytechnic University of the Philippines\n");
	printf("San Juan Campus\n");
	printf("Student Record\n");
	printf("A] New File\n");
	printf("B] Add Record\n");
	printf("C] Display Records\n");
	printf("D] Close the Program\n");
	printf("Select an option: ");

	ans = toupper(getche()); // Get user input and convert to uppercase

	// Handle user input
	if (ans == 'A')
	{
		newRecord();
	}
	else if (ans == 'B')
	{
		addRecord();
	}
	else if (ans == 'C')
	{
		dispRec();
	}
	else if (ans == 'D')
	{
		goodbye();
	}
	else
	{
		printf("\nInvalid Option!\n");
		system("pause");
	}
}

// Main function
int main()
{
	while (ans != 'D') // Loop until the user selects 'D'
	{
		mainScreen();
	}
	return 0;
}
