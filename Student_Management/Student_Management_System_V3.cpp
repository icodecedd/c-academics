/**
 * This program was created by The Unknown Coder.
 * All rights reserved to the original author.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Function prototypes
int add();
int read();
int update();
int delete_data();

int main() {
	int choose;
	do {
		system("cls");
		int option;

		// Display menu
		printf("\nThe Unknown Coder !");
		printf("\n------------------");
		printf("\n\n1. Add to file");
		printf("\n2. Read from file");
		printf("\n3. Update File");
		printf("\n4. Delete File");
		printf("\n0. Exit");
		printf("\n\nSelect an option: ");
		scanf("%d", &option);
		fflush(stdin);

		// Handle menu options
		switch (option) {
			case 1:
				choose = add();
				break;
			case 2:
				choose = read();
				break;
			case 3:
				choose = update();
				break;
			case 4:
				choose = delete_data();
				break;
			case 0:
				return 0;
		}
	} while (choose != 0);

	getch();
	return 0;
}

// Function to add a record to the file
int add() {
	system("cls");
	int id, choose;
	char name[20];
	char password[15];

	FILE *fp = fopen("list.txt", "a");
	if (fp == NULL) {
		printf("Error opening file!");
		return 0;
	}

	printf("Enter id: ");
	scanf("%d", &id);
	fflush(stdin);
	printf("Enter name: ");
	gets(name);
	fflush(stdin);
	printf("Enter password: ");
	gets(password);
	fflush(stdin);

	fprintf(fp, "\n%d %s %s", id, name, password);
	fclose(fp);

	printf("\n\nDo you want to continue?");
	printf("\n1. Continue");
	printf("\n2. Exit");
	printf("\nChoose an option: ");
	scanf("%d", &choose);

	return (choose == 1) ? 1 : 0;
}

// Function to read and display records from the file
int read() {
	system("cls");
	int id, choose;
	char name[20], password[15];

	FILE *fp = fopen("list.txt", "r");
	if (fp == NULL) {
		printf("Error opening file!");
		return 0;
	}

	printf("\nID\tNAME\t\tPASSWORD");
	while (fscanf(fp, "%d %s %s\n", &id, name, password) != EOF) {
		printf("\n%d\t%s\t\t%s", id, name, password);
	}
	fclose(fp);

	printf("\n\nDo you want to continue?");
	printf("\n1. Continue");
	printf("\n2. Exit");
	printf("\nChoose an option: ");
	scanf("%d", &choose);

	return (choose == 1) ? 1 : 0;
}

// Function to update a record in the file
int update() {
	system("cls");
	int id, id1, choice, choose;
	char name[20], password[15];
	char new_name[20], new_password[15];

	printf("\nEnter the id you want to update: ");
	scanf("%d", &id1);
	fflush(stdin);

	FILE *fp = fopen("list.txt", "r");
	FILE *fp1 = fopen("temp.txt", "w");
	if (fp == NULL || fp1 == NULL) {
		printf("Error opening file!");
		return 0;
	}

	while (fscanf(fp, "%d %s %s\n", &id, name, password) != EOF) {
		if (id == id1) {
			printf("\nWhat do you want to update?");
			printf("\n1. Name");
			printf("\n2. Password");
			printf("\n0. Exit");
			printf("\nSelect an option: ");
			scanf("%d", &choice);
			fflush(stdin);

			if (choice == 1) {
				printf("\nEnter new username: ");
				gets(new_name);
				fflush(stdin);
				fprintf(fp1, "%d %s %s\n", id, new_name, password);
			} else if (choice == 2) {
				printf("\nEnter new password: ");
				gets(new_password);
				fflush(stdin);
				fprintf(fp1, "%d %s %s\n", id, name, new_password);
			} else {
				fclose(fp);
				fclose(fp1);
				remove("temp.txt");
				return 0;
			}
		} else {
			fprintf(fp1, "%d %s %s\n", id, name, password);
		}
	}
	fclose(fp);
	fclose(fp1);

	remove("list.txt");
	rename("temp.txt", "list.txt");

	printf("\n\nDo you want to continue?");
	printf("\n1. Continue");
	printf("\n2. Exit");
	printf("\nChoose an option: ");
	scanf("%d", &choose);

	return (choose == 1) ? 1 : 0;
}

// Function to delete a record from the file
int delete_data() {
	system("cls");
	int id, id1, choose;
	char name[20], password[15];

	printf("\nWhich record do you want to delete?");
	printf("\nEnter id of that record: ");
	scanf("%d", &id1);
	fflush(stdin);

	FILE *fp = fopen("list.txt", "r");
	FILE *fp1 = fopen("temp.txt", "w");
	if (fp == NULL || fp1 == NULL) {
		printf("Error opening file!");
		return 0;
	}

	while (fscanf(fp, "%d %s %s\n", &id, name, password) != EOF) {
		if (id != id1) {
			fprintf(fp1, "%d %s %s\n", id, name, password);
		}
	}
	fclose(fp);
	fclose(fp1);

	remove("list.txt");
	rename("temp.txt", "list.txt");

	printf("\n\nDo you want to continue?");
	printf("\n1. Continue");
	printf("\n2. Exit");
	printf("\nChoose an option: ");
	scanf("%d", &choose);

	return (choose == 1) ? 1 : 0;
}
