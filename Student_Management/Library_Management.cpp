/**
 * A simple Library Management System implemented in C. 
 * Features include adding books, listing available books, 
 * deleting books, issuing books to students, and displaying 
 * the list of issued books. The system uses file handling 
 * to store and retrieve data persistently.
 * 
 * Key Features:
 * - Add new books with details such as ID, name, author, and date.
 * - View a list of all available books.
 * - Remove books by their ID.
 * - Issue books to students by recording student details and book information.
 * - Display a list of all issued books with student details.
 * 
 * @credits Provided by the user. Original author unknown.
 */

 #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

// Structure to store book details
struct books {
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
} b;

// Structure to store student details
struct student {
    int id;
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName[50];
    char date[12];
} s;

FILE *fp;

// Function prototypes
void addBook();
void booksList();
void del();
void issueBook();
void issueList();

int main() {
    int ch;

    while (1) {
        system("cls");
        printf("<== Library Management System ==>\n");
        printf("1. Add Book\n");
        printf("2. Books List\n");
        printf("3. Remove Book\n");
        printf("4. Issue Book\n");
        printf("5. Issued Book List\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 0:
                exit(0);

            case 1:
                addBook();
                break;

            case 2:
                booksList();
                break;

            case 3:
                del();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                issueList();
                break;

            default:
                printf("Invalid Choice...\n\n");
        }
        printf("Press Any Key To Continue...");
        getch();
    }

    return 0;
}

// Function to add a new book
void addBook() {
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fp = fopen("books.txt", "ab");

    printf("Enter book id: ");
    scanf("%d", &b.id);

    printf("Enter book name: ");
    fflush(stdin);
    gets(b.bookName);

    printf("Enter author name: ");
    fflush(stdin);
    gets(b.authorName);

    printf("Book Added Successfully\n");

    fwrite(&b, sizeof(b), 1, fp); // Write book details to file
    fclose(fp);
}

// Function to display the list of available books
void booksList() {
    system("cls");
    printf("<== Available Books ==>\n\n");
    printf("%-10s %-30s %-20s %s\n\n", "Book id", "Book Name", "Author", "Date");

    fp = fopen("books.txt", "rb");
    while (fread(&b, sizeof(b), 1, fp) == 1) {
        printf("%-10d %-30s %-20s %s\n", b.id, b.bookName, b.authorName, b.date);
    }

    fclose(fp);
}

// Function to delete a book by its ID
void del() {
    int id, f = 0;
    system("cls");
    printf("<== Remove Books ==>\n\n");
    printf("Enter Book id to remove: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("books.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (id == b.id) {
            f = 1; // Book found
        } else {
            fwrite(&b, sizeof(b), 1, ft); // Write other books to temp file
        }
    }

    if (f == 1) {
        printf("\n\nDeleted Successfully.\n");
    } else {
        printf("\n\nRecord Not Found!\n");
    }

    fclose(fp);
    fclose(ft);

    remove("books.txt"); // Remove old file
    rename("temp.txt", "books.txt"); // Rename temp file to original file name
}

// Function to issue a book to a student
void issueBook() {
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(s.date, myDate);

    int f = 0;

    system("cls");
    printf("<== Issue Books ==>\n\n");

    printf("Enter Book id to issue: ");
    scanf("%d", &s.id);

    // Check if the book with the given ID exists
    fp = fopen("books.txt", "rb");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.id == s.id) {
            strcpy(s.bookName, b.bookName);
            f = 1; // Book found
            break;
        }
    }

    fclose(fp);

    if (f == 0) {
        printf("No book found with this id\n");
        printf("Please try again...\n\n");
        return;
    }

    fp = fopen("issue.txt", "ab");

    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.sName);

    printf("Enter Student Class: ");
    fflush(stdin);
    gets(s.sClass);

    printf("Enter Student Roll: ");
    scanf("%d", &s.sRoll);

    printf("Book Issued Successfully\n\n");

    fwrite(&s, sizeof(s), 1, fp); // Write issued book details to file
    fclose(fp);
}

// Function to display the list of issued books
void issueList() {
    system("cls");
    printf("<== Book Issue List ==>\n\n");

    printf("%-10s %-30s %-20s %-10s %-30s %s\n\n", "S.id", "Name", "Class", "Roll", "Book Name", "Date");

    fp = fopen("issue.txt", "rb");
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        printf("%-10d %-30s %-20s %-10d %-30s %s\n", s.id, s.sName, s.sClass, s.sRoll, s.bookName, s.date);
    }

    fclose(fp);
}
