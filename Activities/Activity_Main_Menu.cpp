#include<utility.h>

// Function to perform arithmetic operations (Addition, Subtraction, Multiplication, Division)
void page2(char opt, char ch[])
{
	float a, b, result = 0;    
	char Continue = 'Y';
	system("cls");
	box2(2, 2, 80, 16);
	box3(3, 3, 78, 5);
	printxy(8, 4, "Operation:  ");
	gotoxy(19, 4); puts(ch);
	box3(3, 7, 78, 14);
	printxy(8, 8, "First Number:  ");
	printxy(8, 10, "Second Number:  ");
	printxy(8, 12, "Result:  ");
	while (Continue == 'Y')
	{
		clearportion(22, 8, 24, 10);
		gotoxy(22, 8); scanf("%f", &a);
		gotoxy(23, 10); scanf("%f", &b);
		if (opt == 'A')
			result = a + b;
		else if (opt == 'B')
			result = a - b;
		else if (opt == 'C')
			result = a * b;
		else 
			result = a / b;
		gotoxy(17, 12); printf("%.2f", result);
		printxy(8, 15, "Continue [Y/N]: ");
		gotoxy(24, 15); Continue = toupper(getch());
		printxy(17, 12, "            ");
		printxy(25, 15, "             ");
	}
}

// Function to display the end screen
void page3()
{
	system("cls");
	box1(11, 11, 69, 15, 178);
	box1(9, 9, 71, 17, 232);
	box1(7, 7, 73, 19, 178);
	box1(5, 5, 75, 21, 232);
	center(13, "This is the End:>>>");    
	getch();
}

// Function to display an error message for invalid input
void error_msg()
{
	center(23, "Invalid Option! Press any key to continue...");
	getch();
	clearportion(10, 23, 77, 23);
}

// Main function to display the main menu and handle user input
int main()
{
	char answer = ' ';
	while (answer != 'E')
	{
		system("cls");
		box2(2, 2, 80, 24);
		box3(3, 3, 78, 7);
		center(4, "Polytechnic University of the Philippines");
		center(5, "San Juan Campus");
		center(6, "San Juan City");
		box3(34, 9, 46, 11);
		center(10, "Main Menu");
		box3(24, 13, 56, 22);
		printxy(26, 15, "A.) Addition");
		printxy(26, 16, "B.) Subtraction");
		printxy(26, 17, "C.) Multiplication");
		printxy(26, 18, "D.) Division");
		printxy(26, 19, "E.) Close");
		printxy(32, 21, "Select an option ");    
		gotoxy(50, 21);
		answer = toupper(getche());
		if (answer == 'A')
			page2('A', "Addition");
		else if (answer == 'B')
			page2('B', "Subtraction");
		else if (answer == 'C')
			page2('C', "Multiplication");
		else if (answer == 'D')
			page2('D', "Division");
		else if (answer == 'E')
			page3();
		else 
			error_msg();
	}
	return 0;
}
