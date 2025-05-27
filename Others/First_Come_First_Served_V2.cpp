#include <stdio.h>  // Standard input/output for I/O operations
#include <stdlib.h> // Standard library for functions like malloc() and free()
#include <limits.h> // For limits
#include <math.h>   // For max() function
#include <utility.h>

#define red \033[1;31m

int main();
void displayExitMessage();
void enterProcesses();
void clearScreen();
void detailsHeader();

// Define a structure for Process
struct Process {
    int id;             // Process ID
    int arrivalTime;    // Arrival time of the process
    int burstTime;      // Burst time (CPU time required)
    int waitingTime;    // Waiting time
    int turnAroundTime; // Turnaround time
    int completionTime; // Completion time
};

// Comparator function to sort processes based on process ID
int compareProcessID(const void* a, const void* b) {
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;
    return p1->id - p2->id; // Sort based on Process ID
}

// Display the FCFS header menu
void fcfsHeader() {
    clearScreen();
    box3(4, 0, 116, 29);
    printf("\x1b[1m \033[31m");
    printxy(40, 2, "Polytechnic University of the Philippines");
    printxy(52, 3, "San Juan Campus");
    printxy(38, 5, "Bachelors of Science in Information Technology");
    printxy(51, 6, "Prof. Elias Austria");
    printxy(52, 8, "Operating Systems");
    printf("\033[0m");

    box3(38, 10, 82, 20);
    printf("\x1b[1m \033[33m");
    printxy(52, 12, "{A} Enter Processes");
    printxy(52, 14, "{B} Details");
    printxy(52, 16, "{C} Exit Program");
    printf("\033[0m");

    char choice = ' ';
    while (choice != 'C') {
        printxy(52, 19, "Enter Choice: ");
        gotoxy(66, 19);
        choice = toupper(getche());
        switch (choice) {
            case 'A': {
                enterProcesses();
                break;
            }
            case 'B': {
                detailsHeader();
                break;
            }
            case 'C': {
                displayExitMessage();
                break;
            }
            default: {
                gotoxy(40, 22);
                printf("Invalid input. Please enter a valid choice");
                getch();
                clearportion(66, 19, 75, 19);
                clearportion(38, 22, 82, 22);
                continue;
            }
        }
    }
    getch();
}

// Display the details header
void detailsHeader() {
    clearScreen();
    box3(4, 0, 116, 29);

    box3(7, 1, 41, 25);
    box3(43, 1, 77, 25);
    box3(79, 1, 113, 25);
    printf("\x1b[1m \x1b[36m");
    printxy(12, 3, "Bugayong, Micah Athena D.");
    printxy(47, 3, "Francisco, Sandra Marie O.");
    printxy(87, 3, "Uy, Juztin Ross Y.");
    printf("\x1b[1m \x1b[34m");
    printxy(45, 7, "As the team leader, Sandra Marie");
    printxy(45, 9, "is the driving force behind our");
    printxy(45, 11, "project. She provides the");
    printxy(45, 13, "direction and expertise needed ");
    printxy(45, 15, "to guide our work on the FCFS");
    printxy(45, 17, "algorithm. Her ability to");
    printxy(45, 19, "explain ideas in simple terms");
    printxy(45, 21, "helps the team stay focused");
    printxy(45, 23, "and achieve  our goals.");

    printxy(9, 7, "Micah Athena is our expert in");
    printxy(9, 9, "analyzing the FCFS algorithm.");
    printxy(9, 11, "They run simulations and tests");
    printxy(9, 13, "under different conditions,");
    printxy(9, 15, "helping us find ways to make");
    printxy(9, 17, "it better.");

    printxy(81, 7, "He turns theory into practice");
    printxy(81, 9, "by coding the FCFS algorithm in");
    printxy(81, 11, "languages like C. They make");
    printxy(81, 13, "sure the code is accurate,");
    printxy(81, 15, "efficient, and well-documented,");
    printxy(81, 17, "creating a strong foundation");
    printxy(81, 19, "for testing and experiments.");
    printxy(81, 21, "Their attention to detail");
    printxy(81, 23, "and problem-solving skills");
    printxy(81, 23, "are a big help to the team.");

    printf("\x1b[33m");
    printxy(48, 27, "Press any key to exit....");
    gotoxy(74, 27);
    getch();
    printf("\x1b[0m");

    fcfsHeader();
}

// Get a valid integer input with error handling
int getValidIntInput(const char* prompt) {
    int input;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &input) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            printf("\033[1;31mInvalid input. Please enter a valid number.\033[0m\n");
        } else {
            return input;
        }
    }
}

// Clear the screen
void clearScreen() {
    system("cls"); // Using system("cls") for Windows
}

// Calculate average times and print process details
void findAverageTimes(struct Process* processes, int n) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    // Calculate Completion Time based on Arrival Time
    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;
    for (int i = 1; i < n; i++) {
        processes[i].completionTime = fmax(processes[i].arrivalTime, processes[i - 1].completionTime) + processes[i].burstTime;
    }

    // Calculate Turnaround Time and Waiting Time
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    // Print the table with process details
    printf("\nProcess ID\tArrival\t\tBurst\t\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].completionTime,
               processes[i].turnAroundTime,
               processes[i].waitingTime);
    }

    // Calculate average times
    double averageWaitingTime = (double)totalWaitingTime / n;
    double averageTurnaroundTime = (double)totalTurnAroundTime / n;

    // Print average waiting and turnaround times
    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

// Print the Gantt chart
void printGanttChart(struct Process* processes, int n) {
    const int boxWidth = 10; // Adjust box width for better alignment

    // Top line of the Gantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("+");
        for (int j = 0; j < boxWidth; j++) printf("-");
    }
    printf("+\n");

    // Process IDs inside the boxes
    for (int i = 0; i < n; i++) {
        printf("|  P%d", processes[i].id);
        for (int j = 0; j < boxWidth - 4; j++) printf(" ");
    }
    printf("|\n");

    // Bottom line of the Gantt chart
    for (int i = 0; i < n; i++) {
        printf("+");
        for (int j = 0; j < boxWidth; j++) printf("-");
    }
    printf("+\n");

    // Start and completion times
    printf("0");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < boxWidth - 1; j++) {
            printf(" ");
        }
        printf("%*d", 2, processes[i].completionTime);
    }
    printf("\n");
}

// Display the exit message
void displayExitMessage() {
    clearScreen();
    box3(27, 4, 92, 20);
    box3(32, 6, 87, 14);

    printf("\033[1m\033[35m");
    printxy(37, 8, "Thank you for using [First Come, First Serve]!");
    printxy(37, 10, "     Your session will end, and you can");
    printxy(37, 12, "        restart anytime to continue.");
    printf("\033[33m");
    printxy(48, 16, "Press any key to exit the");
    printxy(41, 18, "application and complete your journey.");
    printf("\033[0m");
    getchar(); // Wait for user input
    clearScreen();

    // Display "Exiting Program..." message
    for (int x = 5; x > 0; x--) {
        gotoxy(49, 12);
        printf("\033[1;33mExiting Program in %d...\033[0m\n", x);
        Sleep(800);
        clearportion(49, 7, 75, 7);
    }
    clearScreen();
    exit(0);
}

// Ask the user if they want to create a new set of processes
void askToCreateNewProcess() {
    char choice;

    printf("\nDo you want to create new processes? (y/n): ");
    while (1) {
        scanf(" %c", &choice); // Space before %c to catch any leftover newline

        if (choice == 'y' || choice == 'Y') {
            clearScreen();
            return;
        } else if (choice == 'n' || choice == 'N') {
            fcfsHeader();
        } else {
            printf("\033[1;31mInvalid choice. Please enter 'Y' or 'N'.\033[0m\n");
        }
    }
}

// Enter processes and calculate FCFS scheduling
void enterProcesses() {
    clearScreen();

    while (1) {
        int n;

        // Input number of processes with validation
        n = getValidIntInput("Enter number of processes: ");
        while (n <= 0) {
            printf("Invalid input. Please enter a positive integer: ");
            n = getValidIntInput("");
        }

        struct Process* processes = (struct Process*)malloc(n * sizeof(struct Process));

        // Input processes, arrival time, and burst time with validation
        for (int i = 0; i < n; i++) {
            processes[i].id = i + 1;

            printf("Enter Arrival Time for P%d: ", processes[i].id);
            processes[i].arrivalTime = getValidIntInput("");
            while (processes[i].arrivalTime < 0) {
                printf("\033[1;31mInvalid input. Please enter a non-negative integer.\033[0m\n");
                printf("Enter Arrival Time for P%d: ", processes[i].id);
                processes[i].arrivalTime = getValidIntInput("");
            }

            printf("Enter Burst Time for P%d: ", processes[i].id);
            processes[i].burstTime = getValidIntInput("");
            while (processes[i].burstTime <= 0) {
                printf("\033[1;31mInvalid input. Please enter a positive integer.\033[0m\n");
                printf("Enter Burst Time for P%d: ", processes[i].id);
                processes[i].burstTime = getValidIntInput("");
            }
        }

        clearScreen();

        // Sort the processes based on Process ID
        qsort(processes, n, sizeof(struct Process), compareProcessID);

        // Calculate average waiting and turnaround times
        findAverageTimes(processes, n);

        // Prompt to continue and clear screen before displaying the Gantt chart
        printf("\nPress Enter to continue to Gantt Chart ");
        getchar(); // To consume the newline left by previous input
        getchar(); // Wait for the user to press Enter

        clearScreen();

        // Print Gantt chart
        printGanttChart(processes, n);

        // Free dynamically allocated memory
        free(processes);

        // Ask if the user wants to create new processes
        askToCreateNewProcess();
    }
}

// Main function
int main() {
    detailsHeader(); // Function call for header
}
