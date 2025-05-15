/**
 * Features include creating, deleting, modifying records, generating marksheets, 
 * searching, and displaying records. Password protection is implemented for secure access.
 * 
 * @credits Provided by the user. Original author unknown.
 */

#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Global variable to track the number of students
static int n = 0;

// Structure to store student details
struct STUDENT {
	int age, roll_no, maths, physics, science, total;
	char name[10];
	float avg;
};

// Function prototypes
void add();
void password();
void displayAll();
void record();
void del();
void marksheet();
void modify();
void changePassword();

int main() {
	int choice;

	while (1) {
		// Display menu options
		printf("\n\t\t==================================================\n");
		printf("\n\t\t\t   Student Data Management System\n");
		printf("\n\t\t==================================================\n");
		printf("\n\t\t----------------------");
		printf("\n\t\tSelect an option:");
		printf("\n\t\t----------------------");
		printf("\n\t\t1. Create Student Record");
		printf("\n\t\t2. Delete Student Record");
		printf("\n\t\t3. Modify Student Record");
		printf("\n\t\t4. Generate Student Marksheet");
		printf("\n\t\t5. Search Record");
		printf("\n\t\t6. Display Records");
		printf("\n\t\t7. Exit");
		printf("\n\t\t----------------------\n");
		printf("\t\tEnter your choice: ");
		scanf("%d", &choice);

		// Handle menu options
		switch (choice) {
			case 1:
				password();
				system("cls");
				add();
				break;
			case 2:
				password();
				system("cls");
				del();
				break;
			case 3:
				password();
				system("cls");
				modify();
				break;
			case 4:
				system("cls");
				marksheet();
				break;
			case 5:
				system("cls");
				record();
				break;
			case 6:
				system("cls");
				displayAll();
				break;
			case 7:
				exit(0);
			default:
				printf("\n\t\tInvalid choice! Please try again.");
		}
	}
}

// Function to add a new student record
void add() {
	system("cls");
	struct STUDENT s;
	FILE *fp = fopen("student_data.dat", "ab");

	printf("\n\t\tEnter Roll No: ");
	scanf("%d", &s.roll_no);
	printf("\t\tEnter Name: ");
	scanf("%s", s.name);
	printf("\t\tEnter Age: ");
	scanf("%d", &s.age);
	printf("\t\tEnter Math marks: ");
	scanf("%d", &s.maths);
	printf("\t\tEnter Physics marks: ");
	scanf("%d", &s.physics);
	printf("\t\tEnter Science marks: ");
	scanf("%d", &s.science);

	s.total = s.maths + s.physics + s.science;
	s.avg = s.total / 3.0;

	fwrite(&s, sizeof(s), 1, fp);
	fclose(fp);

	printf("\n\t\tRecord Successfully Added");
}

// Function to validate user password
void password() {
	FILE *fp = fopen("password.txt", "r");
	char stored_password[6], entered_password[6];
	int i, match_count = 0;

	printf("\n\t\tEnter password: ");
	for (i = 0; i < 6; i++) {
		entered_password[i] = getch();
		printf("*");
	}

	fread(stored_password, sizeof(char), 6, fp);
	fclose(fp);

	for (i = 0; i < 6; i++) {
		if (entered_password[i] == stored_password[i]) {
			match_count++;
		}
	}

	if (match_count == 6) {
		printf("\n\t\tLogin Success");
	} else {
		printf("\n\t\tLogin Failed");
		password();
	}
}

// Function to display all student records
void displayAll() {
	FILE *fp = fopen("student_data.dat", "rb");
	struct STUDENT s;

	printf("\n\t========================================================\n\n");
	printf("\t\t\t All Student Details\n\n");
	printf("\t========================================================\n\n");

	while (fread(&s, sizeof(s), 1, fp)) {
		printf("\n\tRoll No: %d", s.roll_no);
		printf("\tName: %s", s.name);
		printf("\tAge: %d", s.age);
		printf("\tTotal: %d\n", s.total);
	}

	printf("\t========================================================\n\n");
	fclose(fp);
}

// Function to search for a student record by roll number
void record() {
	FILE *fp = fopen("student_data.dat", "rb");
	struct STUDENT s;
	int id, found = 0;

	printf("\n\t\tEnter the student roll no: ");
	scanf("%d", &id);

	while (fread(&s, sizeof(s), 1, fp)) {
		if (s.roll_no == id) {
			found = 1;
			printf("\n\t========================================================\n\n");
			printf("\t\t\t Student Record of %d\n\n", s.roll_no);
			printf("\t========================================================\n\n");
			printf("\tRoll No: %d ", s.roll_no);
			printf("\tName: %s ", s.name);
			printf("\tAge: %d ", s.age);
			printf("\tTotal: %d \n", s.total);
			printf("\t========================================================\n\n");
		}
	}

	if (!found) {
		printf("\nSorry, No Record Found");
	}

	fclose(fp);
}

// Function to delete a student record
void del() {
	FILE *fp = fopen("student_data.dat", "rb");
	FILE *fp1 = fopen("temp.dat", "wb");
	struct STUDENT s;
	int id, found = 0;

	printf("\n\t\tEnter Student Roll No you want to Delete: ");
	scanf("%d", &id);

	while (fread(&s, sizeof(s), 1, fp)) {
		if (s.roll_no == id) {
			found = 1;
		} else {
			fwrite(&s, sizeof(s), 1, fp1);
		}
	}

	fclose(fp);
	fclose(fp1);

	if (!found) {
		printf("\t\tSorry, No Record Found\n\n");
	} else {
		fp = fopen("student_data.dat", "wb");
		fp1 = fopen("temp.dat", "rb");

		while (fread(&s, sizeof(s), 1, fp1)) {
			fwrite(&s, sizeof(s), 1, fp);
		}

		fclose(fp);
		fclose(fp1);
	}
}

// Function to generate a student's marksheet
void marksheet() {
	FILE *fp = fopen("student_data.dat", "rb");
	struct STUDENT s;
	int id, found = 0;

	printf("\n\t\tEnter Student Roll No: ");
	scanf("%d", &id);

	while (fread(&s, sizeof(s), 1, fp)) {
		if (s.roll_no == id) {
			found = 1;
			printf("\n\t========================================================\n\n");
			printf("\t\t\t Student Marksheet of %d\n\n", s.roll_no);
			printf("\t========================================================\n\n");
			printf("\tRoll No: %d\t", s.roll_no);
			printf("\tName: %s\n", s.name);
			printf("\tMaths: %d\t", s.maths);
			printf("\tPhysics: %d\t", s.physics);
			printf("\tScience: %d\t\n", s.science);
			printf("\tTotal: %d\t", s.total);
			printf("\tAverage: %.2f\n", s.avg);
			printf("\t========================================================\n\n");
		}
	}

	if (!found) {
		printf("\nSorry, No Record Found");
	}

	fclose(fp);
}

// Function to modify a student record
void modify() {
	FILE *fp = fopen("student_data.dat", "rb");
	FILE *fp1 = fopen("temp.dat", "wb");
	struct STUDENT s;
	int id, found = 0;

	printf("\n\t\tEnter Student Roll No you want to Modify: ");
	scanf("%d", &id);

	while (fread(&s, sizeof(s), 1, fp)) {
		if (s.roll_no == id) {
			found = 1;
			printf("\t\tEnter new Roll No: ");
			scanf("%d", &s.roll_no);
			printf("\t\tEnter new Name: ");
			scanf("%s", s.name);
			printf("\t\tEnter new Age: ");
			scanf("%d", &s.age);
			printf("\t\tEnter new Math marks: ");
			scanf("%d", &s.maths);
			printf("\t\tEnter new Physics marks: ");
			scanf("%d", &s.physics);
			printf("\t\tEnter new Science marks: ");
			scanf("%d", &s.science);

			s.total = s.maths + s.physics + s.science;
			s.avg = s.total / 3.0;

			fwrite(&s, sizeof(s), 1, fp1);
		} else {
			fwrite(&s, sizeof(s), 1, fp1);
		}
	}

	fclose(fp);
	fclose(fp1);

	if (!found) {
		printf("\t\tSorry, No Record Found\n\n");
	} else {
		fp = fopen("student_data.dat", "wb");
		fp1 = fopen("temp.dat", "rb");

		while (fread(&s, sizeof(s), 1, fp1)) {
			fwrite(&s, sizeof(s), 1, fp);
		}

		fclose(fp);
		fclose(fp1);
	}
}

// Function to change the password
void changePassword() {
	FILE *fp = fopen("password.txt", "w");
	char new_password[6], confirm_password[6];
	int i, match_count = 0;

	printf("\nEnter new password (6 characters): ");
	scanf("%s", new_password);
	printf("\nRe-enter password: ");
	scanf("%s", confirm_password);

	for (i = 0; i < 6; i++) {
		if (new_password[i] == confirm_password[i]) {
			match_count++;
		}
	}

	if (match_count == 6) {
		fprintf(fp, "%s", new_password);
		printf("\nPassword successfully changed");
	} else {
		printf("\nPasswords do not match");
		changePassword();
	}

	fclose(fp);
}
