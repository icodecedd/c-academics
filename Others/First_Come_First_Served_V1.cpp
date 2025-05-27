#include <iostream>  // Standard input/output stream for I/O operations
#include <vector>    // Vector container for dynamic arrays
#include <iomanip>   // Functions for controlling input/output formatting
#include <algorithm> // Algorithms such as sort()
#include <sstream>   // Used to convert data types to strings
#include <cstdlib>   // General-purpose functions like system()
#include <limits>    // Use numeric_limits for input validation
#include <utility.h> // Custom utility header (assumed to exist)

using namespace std;

// Structure to represent a process
struct Process {
    int id;             // Process ID
    int arrivalTime;    // Arrival time of the process
    int burstTime;      // Burst time (CPU time required)
    int waitingTime;    // Waiting time
    int turnAroundTime; // Turnaround time
    int completionTime; // Completion time
};

// Comparator function to sort processes by arrival time (and burst time if equal)
bool compareArrivalTime(Process p1, Process p2) {
    if (p1.arrivalTime == p2.arrivalTime) {
        return p1.burstTime < p2.burstTime;
    }
    return p1.arrivalTime < p2.arrivalTime;
}

// Function to handle invalid inputs and retry
int getValidIntInput(string prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
        } else {
            return input;
        }
    }
}

// Function to calculate average waiting and turnaround times
void findAverageTimes(vector<Process>& processes, vector<Process>& originalProcesses) {
    int n = processes.size();
    int totalWaitingTime = 0, totalTurnAroundTime = 0;

    // Calculate completion time
    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;
    for (int i = 1; i < n; i++) {
        processes[i].completionTime = max(processes[i].arrivalTime, processes[i - 1].completionTime) + processes[i].burstTime;
    }

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    // Print process details
    cout << "\nProcess ID\tArrival\t\tBurst\t\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; ++i) {
        cout << processes[i].id << "\t\t"
             << processes[i].arrivalTime << "\t\t"
             << processes[i].burstTime << "\t\t"
             << processes[i].completionTime << "\t\t"
             << processes[i].turnAroundTime << "\t\t"
             << processes[i].waitingTime << endl;
    }

    // Print average times
    double averageWaitingTime = (double)totalWaitingTime / n;
    double averageTurnaroundTime = (double)totalTurnAroundTime / n;
    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << averageTurnaroundTime << endl;
}

// Function to print the Gantt chart
void printGanttChart(const vector<Process>& processes) {
    int n = processes.size();
    const int boxWidth = 10;

    // Top line of the Gantt chart
    cout << "\nGantt Chart:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "+";
        for (int j = 0; j < boxWidth; j++) cout << "-";
    }
    cout << "+" << endl;

    // Process IDs inside the boxes
    for (int i = 0; i < n; i++) {
        cout << "|  P" << processes[i].id;
        for (int j = 0; j < boxWidth - 4; j++) cout << " ";
    }
    cout << "|" << endl;

    // Bottom line of the Gantt chart
    for (int i = 0; i < n; i++) {
        cout << "+";
        for (int j = 0; j < boxWidth; j++) cout << "-";
    }
    cout << "+" << endl;

    // Start and completion times
    cout << "0";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < boxWidth - 1; j++) cout << " ";
        cout << processes[i].completionTime;
    }
    cout << endl;
}

// Function to clear the screen
void clearScreen() {
    system("CLS");
}

int main() {
    int n;
    char cont = ' ';

    // Input number of processes
    cout << "Enter number of processes: ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer: ";
    }

    vector<Process> processes(n);
    vector<Process> originalProcesses(n);

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        originalProcesses[i].id = i + 1;

        cout << "Enter Arrival Time for P" << processes[i].id << ": ";
        while (!(cin >> processes[i].arrivalTime) || processes[i].arrivalTime < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative integer: ";
        }
        originalProcesses[i].arrivalTime = processes[i].arrivalTime;

        cout << "Enter Burst Time for P" << processes[i].id << ": ";
        while (!(cin >> processes[i].burstTime) || processes[i].burstTime <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer: ";
        }
        originalProcesses[i].burstTime = processes[i].burstTime;
    }

    // Clear the console
    cout << "\nPress Enter to continue to Computation ";
    cin.ignore();
    cin.get();
    clearScreen();

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), compareArrivalTime);

    // Calculate and display average times
    findAverageTimes(processes, originalProcesses);

    cout << "\nPress Enter to continue to Gantt Chart ";
    cin.get();
    clearScreen();

    // Display Gantt chart
    printGanttChart(processes);

    // Loop for continuation
    while (cont != 'N') {
        cout << "Do you want to continue (Y/N): ";
        cin >> cont;
        cont = toupper(cont);

        switch (cont) {
            case 'Y':
                main();
                break;
            case 'N':
                cout << "Goodbye!";
                break;
            default:
                cout << "Invalid input. Please enter a valid choice.\n";
                break;
        }
    }

    return 0;
}
