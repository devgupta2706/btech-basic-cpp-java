// C++ program for implementation of FCFS cpu sheduling
#include <iostream>
using namespace std;
void findWaitTime(string process[], int n,int bt[], int wt[])
{
    wt[0] = 0;// waiting time for first process is 0
    // calculating waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

// Function to calculate turn around time
void findTurnAroundTime(string process[], int n,int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(string processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    // Function to find waiting time 
    findWaitTime(processes, n, bt, wt);
    // Function to find turn around time 
    findTurnAroundTime(processes, n, bt, wt, tat);
    // Display processes along with all details
    cout << "Processes   Burst time   Waiting time   Turn around time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "    P" << i << "\t\t\t" << bt[i] << "\t\t\t"<< wt[i] << "\t\t\t\t" << tat[i] << endl;
    }
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
    // process id's
    string process[] = {"P0", "P1", "P2", "P3"};
    int n = sizeof process / sizeof process[0];
    int burst_time[] = {5, 3, 8, 6};
    findavgTime(process, n, burst_time);
    return 0;
}