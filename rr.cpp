// C++ program for implementation of RR scheduling
#include <iostream>
using namespace std;
void findWaitingTime(string processes[], int n, int bt[], int wt[], int quantum)
{
	// Make a copy of burst times bt[] to store remaining burst times.
	int rem_bt[n];
	for (int i = 0; i < n; i++)
		rem_bt[i] = bt[i];
	int t = 0; // Current time
	while (1)
	{
		bool done = true;
		for (int i = 0; i < n; i++)
		{
			if (rem_bt[i] > 0)
			{
				done = false;
				if (rem_bt[i] > quantum)
				{
					t += quantum;
					rem_bt[i] -= quantum;
				}
				else
				{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true)
			break;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(string processes[], int n,
						int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(string processes[], int n, int bt[], int quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	// Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt, quantum);
	// Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);
	// Display processes along with all details
	cout << "Processes  Burst time  Waiting time  Turn around time\n";
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << "P" << i << "\t\t\t" << bt[i] << "\t\t "
			 << wt[i] << "\t\t\t " << tat[i] << endl;
	}
	cout << "Average waiting time = "
		 << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		 << (float)total_tat / (float)n;
}

// Driver code
int main()
{
	// process id's
	string process[] = {"P0", "P1", "P2", "P3"};
	int n = sizeof process / sizeof process[0];
	int quantum = 2; // in microsecond
	int burst_time[] = {5, 3, 8, 6};
	findavgTime(process, n, burst_time, quantum);
	return 0;
}
