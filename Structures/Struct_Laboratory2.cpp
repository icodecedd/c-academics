#include <stdio.h>
#include <utility.h>

// Global variables
float eq, tg;

// Function to calculate equivalent grade
int eqcalc(float scor, float total) {
	tg = (scor / total * 50) + 50;
	if (tg < 59)
		eq = 5.00;
	else if (tg < 60)
		eq = 4.25;
	else if (tg < 65)
		eq = 4.00;
	else if (tg < 70)
		eq = 3.75;
	else if (tg < 72)
		eq = 3.50;
	else if (tg < 75)
		eq = 3.25;
	else if (tg < 76)
		eq = 3.00;
	else if (tg < 79)
		eq = 2.75;
	else if (tg < 82)
		eq = 2.50;
	else if (tg < 85)
		eq = 2.25;
	else if (tg < 88)
		eq = 2.00;
	else if (tg < 91)
		eq = 1.75;
	else if (tg < 94)
		eq = 1.50;
	else if (tg < 97)
		eq = 1.25;
	else if (tg <= 100)
		eq = 1.00;
}

// Function to display exit animation
void exitbox() {
	box2(1, 1, 78, 24);
	for (int x = 2; x <= 23; x++) {
		center(x, "Salamat sa paggamit");
		Sleep(100);
		center(x, "                         ");
		Sleep(1);
	}
	for (int x = 23; x >= 2; x--) {
		center(x, "Salamat sa paggamit");
		Sleep(100);
		center(x, "                         ");
		Sleep(1);
	}
	for (int x = 2; x <= 12; x++) {
		center(x, "Salamat sa paggamit");
		Sleep(100);
		center(x, "                         ");
		Sleep(1);
	}
	center(12, "Salamat sa paggamit");
}

// Main function
int main() {
	char sagot = ' ';
	struct struct1 {
		char ln[30], fn[30];
		float q1, q2, t1, t2;
	} record[3];

	// Main menu loop
	while (sagot != 'C') {
		box2(27, 4, 51, 12);
		printxy(32, 6, "A] ADD");
		printxy(32, 7, "B] DISPLAY");
		printxy(32, 8, "C] CLOSE");
		printxy(32, 10, "SELECT AN OPTION");
		gotoxy(32, 11);
		sagot = toupper(getch());
		system("cls");

		// Option A: Add records
		if (sagot == 'A') {
			system("cls");
			for (int x = 0; x <= 2; x++) {
				printf("Record %d\n", x + 1);
				puts("LAST NAME: ");
				scanf("\n");
				gets(record[x].ln);
				puts("FIRST NAME: ");
				gets(record[x].fn);
				puts("Quiz 1:       ");
				scanf("\n");
				scanf("%f", &record[x].q1);
				puts("No. of items: ");
				scanf("%f", &record[x].t1);

				// Validate input for Quiz 1
				while (record[x].q1 > record[x].t1) {
					gotoxy(0, 5);
					puts("                              \n                           \n                         \n                        ");
					gotoxy(0, 5);
					puts("Quiz 1:       ");
					scanf("\n");
					scanf("%f", &record[x].q1);
					puts("No. of items: ");
					scanf("%f", &record[x].t1);
				}

				puts("Quiz 2:        ");
				scanf("%f", &record[x].q2);
				puts("No. of items: ");
				scanf("%f", &record[x].t2);

				// Validate input for Quiz 2
				while (record[x].q2 > record[x].t2) {
					gotoxy(0, 9);
					puts("                              \n                           \n                         \n                        ");
					gotoxy(0, 9);
					puts("Quiz 2:       ");
					scanf("\n");
					scanf("%f", &record[x].q2);
					puts("No. of items: ");
					scanf("%f", &record[x].t2);
				}
				system("cls");
			}
		}

		// Option B: Display records
		if (sagot == 'B') {
			puts("#    STUDENT NAME\t\tQUIZ 1\t# of items\tTG\tEQ\tQUIZ 2\t# of items\tTG\tEQ");
			for (int x = 0; x <= 110; x++) {
				gotoxy(x, 1);
				putchar(205);
			}
			printxy(0, 2, "1");
			printxy(0, 3, "2");
			printxy(0, 4, "3");

			for (int x = 0; x <= 2; x++) {
				eqcalc(record[x].q1, record[x].t1);
				gotoxy(5, x + 2);
				printf("%s %s\t\t\t%.f\t%.f\t\t%.2f\t%.2f\t", record[x].fn, record[x].ln, record[x].q1,
					   record[x].t1, (record[x].q1 / record[x].t1 * 50) + 50, eq);

				eqcalc(record[x].q2, record[x].t2);
				printf("%.f\t%.f\t\t%.2f\t%.2f", record[x].q2,
					   record[x].t2, (record[x].q2 / record[x].t2 * 50) + 50, eq);
			}
			getch();
			system("cls");
		}

		// Option C: Exit
		if (sagot == 'C') {
			exitbox();
		}
	}
	return 0;
}
