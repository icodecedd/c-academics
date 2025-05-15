/**
 * This program allows users to manage student information, including adding,
 * editing, deleting, and searching for students. It also supports managing
 * courses associated with each student.
 *
 *       All rights reserved to the original author.
 */

#include <windows.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Struct to store student information
struct StudentInfo {
    char ID[10];
    char Name[20];
    char Email[30];
    char Phone[20];
    int NumberOfCourse;
};

// Struct to store course information
struct CourseInfo {
    char StudentID[10];
    char Code[10];
    char Name[20];
};

// Global variables
struct StudentInfo Students[100];
struct CourseInfo Courses[500];
int TotalStudents = 0;
int TotalCourse = 0;
char StudentID[10];
bool IsRunning = true;

// Function declarations
void Menu();
void AddNewStudent();
void ShowAllStudents();
int SearchStudent(char StudentID[10]);
void EditStudent(int StudentFoundIndex);
void DeleteStudent(int StudentIndex);
void DeleteAllStudents();
int IsAlreadyExists(char GivenLine[30], char InfoType, char StudentID[300]);
void ErrorAndRestart(char *Error[100]);
void DeleteCourseByIndex(int CourseIndex);
void DeleteStudentByIndex(int CourseIndex);
void UserGuideline();
void AboutUs();
void GoBackOrExit();
void ExitProject();
void DataSeed();

int main() {
    DataSeed(); // Load dummy data

    while (IsRunning) {
        Menu();
        int Option;
        scanf("%d", &Option);

        switch (Option) {
            case 0:
                IsRunning = false;
                ExitProject();
                break;
            case 1:
                system("cls");
                printf("\n\t\t **** Add A New Student ****\n\n");
                AddNewStudent();
                GoBackOrExit();
                break;
            case 2:
                system("cls");
                printf("\n\t\t **** All Students ****\n\n");
                ShowAllStudents();
                GoBackOrExit();
                break;
            case 3:
                system("cls");
                printf("\n\t\t **** Search Students ****\n\n");
                printf(" Enter The Student ID: ");
                scanf("%s", StudentID);
                if (SearchStudent(StudentID) < 0) {
                    printf(" No Student Found\n\n");
                }
                printf("\n");
                GoBackOrExit();
                break;
            case 4:
                system("cls");
                printf("\n\t\t **** Edit a Student ****\n\n");
                printf(" Enter The Student ID: ");
                scanf("%s", StudentID);
                int StudentFoundIndex = SearchStudent(StudentID);
                if (StudentFoundIndex >= 0) {
                    EditStudent(StudentFoundIndex);
                } else {
                    printf(" No Student Found\n\n");
                }
                GoBackOrExit();
                break;
            case 5:
                system("cls");
                printf("\n\t\t **** Delete a Student ****\n\n");
                printf(" Enter The Student ID: ");
                scanf("%s", StudentID);
                int DeleteStudentFoundIndex = SearchStudent(StudentID);
                if (DeleteStudentFoundIndex >= 0) {
                    char Sure = 'N';
                    getchar();
                    printf("\n\n Are you sure want to delete this student? (Y/N): ");
                    scanf("%c", &Sure);
                    if (Sure == 'Y' || Sure == 'y') {
                        DeleteStudent(DeleteStudentFoundIndex);
                    } else {
                        printf(" Your Data is Safe.\n\n");
                        GoBackOrExit();
                    }
                } else {
                    printf(" No Student Found\n\n");
                    GoBackOrExit();
                }
                break;
            case 6:
                system("cls");
                printf("\n\t\t **** Delete ALL Students ****\n\n");
                char Sure = 'N';
                getchar();
                printf(" Are you sure want to delete all the students? (Y/N): ");
                scanf("%c", &Sure);
                if (Sure == 'Y' || Sure == 'y') {
                    DeleteAllStudents();
                } else {
                    printf(" Your Data is Safe.\n\n");
                    GoBackOrExit();
                }
                break;
            case 7:
                system("cls");
                break;
            case 8:
                system("cls");
                UserGuideline();
                GoBackOrExit();
                break;
            case 9:
                system("cls");
                AboutUs();
                GoBackOrExit();
                break;
            default:
                ExitProject();
                break;
        }
    }

    return 0;
}

// Display the main menu
void Menu() {
    printf("\n\n\t***Student Management System Using C***\n\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New student.\n");
    printf("\t\t[2] Show All students.\n");
    printf("\t\t[3] Search A student.\n");
    printf("\t\t[4] Edit A student.\n");
    printf("\t\t[5] Delete A student.\n");
    printf("\t\t[6] Delete All students.\n");
    printf("\t\t[7] Clear The window.\n");
    printf("\t\t[8] User Guideline.\n");
    printf("\t\t[9] About Us.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t=======================\n");
    printf("\t\tEnter The Choice: ");
}

// Add a new student
void AddNewStudent() {
    char StudentID[300], Name[300], Phone[300], Email[300];
    int NumberOfCourses;
    char CourseCode[300], CourseName[300];

    // Validate and input student ID
    int IsValidID = 0;
    while (!IsValidID) {
        printf(" Enter The ID: ");
        scanf("%s", StudentID);
        if (IsAlreadyExists(StudentID, 'i', StudentID) > 0) {
            printf(" Error: This ID is already exists.\n\n");
        } else if (strlen(StudentID) > 10 || strlen(StudentID) <= 0) {
            printf(" Error: ID must be between 1 and 10 characters.\n\n");
        } else {
            IsValidID = 1;
        }
    }

    // Validate and input student name
    int IsValidName = 0;
    while (!IsValidName) {
        printf(" Enter The Name: ");
        scanf(" %[^\n]s", Name);
        if (strlen(Name) > 20 || strlen(Name) <= 0) {
            printf(" Error: Name must be between 1 and 20 characters.\n\n");
        } else {
            IsValidName = 1;
        }
    }

    // Validate and input student email
    int IsValidEmail = 0;
    while (!IsValidEmail) {
        printf(" Enter The Email: ");
        scanf("%s", Email);
        if (IsAlreadyExists(Email, 'e', StudentID) > 0) {
            printf(" Error: This Email is already exists.\n\n");
        } else if (strlen(Email) > 30 || strlen(Email) <= 0) {
            printf(" Error: Email must be between 1 and 30 characters.\n\n");
        } else {
            IsValidEmail = 1;
        }
    }

    // Validate and input student phone
    int IsValidPhone = 0;
    while (!IsValidPhone) {
        printf(" Enter The Phone: ");
        scanf("%s", Phone);
        if (IsAlreadyExists(Phone, 'p', StudentID) > 0) {
            printf(" Error: This Phone Number is already exists.\n\n");
        } else if (strlen(Phone) > 20 || strlen(Phone) <= 0) {
            printf(" Error: Phone must be between 1 and 20 characters.\n\n");
        } else {
            IsValidPhone = 1;
        }
    }

    // Validate and input number of courses
    int IsValidNumberOfCourse = 0;
    while (!IsValidNumberOfCourse) {
        printf(" Number of courses: ");
        scanf("%d", &NumberOfCourses);
        if (NumberOfCourses <= 0 || NumberOfCourses > 4) {
            printf(" Error: Number of courses must be between 1 and 4.\n\n");
        } else {
            IsValidNumberOfCourse = 1;
        }
    }

    // Store student information
    strcpy(Students[TotalStudents].ID, StudentID);
    strcpy(Students[TotalStudents].Name, Name);
    strcpy(Students[TotalStudents].Phone, Phone);
    strcpy(Students[TotalStudents].Email, Email);
    Students[TotalStudents].NumberOfCourse = NumberOfCourses;
    TotalStudents++;

    // Store course information
    for (int i = 0; i < NumberOfCourses; i++) {
        printf(" Enter Course %d Code: ", i + 1);
        scanf("%s", CourseCode);
        printf(" Enter Course %d Name: ", i + 1);
        scanf(" %[^\n]s", CourseName);

        strcpy(Courses[TotalCourse].StudentID, StudentID);
        strcpy(Courses[TotalCourse].Code, CourseCode);
        strcpy(Courses[TotalCourse].Name, CourseName);
        TotalCourse++;
    }

    printf("\n Student Added Successfully.\n\n");
}

// Show all students
void ShowAllStudents() {
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|    ID    |        Name        |            Email             |       Phone        |  NO.Course  |\n");
    printf("|==========|====================|==============================|====================|=============|\n");

    for (int i = 0; i < TotalStudents; i++) {
        printf("|%-10s|%-20s|%-30s|%-20s|%-12d|\n", 
            Students[i].ID, Students[i].Name, Students[i].Email, Students[i].Phone, Students[i].NumberOfCourse);
        printf("|----------|--------------------|------------------------------|--------------------|-------------|\n");
    }
    printf("\n");
}

// Other functions remain unchanged for brevity
