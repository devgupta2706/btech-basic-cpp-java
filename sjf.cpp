// C++ program to implement Shortest Job first with Arrival
// Time
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void arrangeArrival(int num, int mat[][6])
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (mat[j][1] > mat[j + 1][1])
			{
				for (int k = 0; k < 5; k++)
				{
					swap(mat[j][k], mat[j + 1][k]);
				}
			}
		}
	}
}

void completionTime(int num, int mat[][6])
{
	int temp, val;
	mat[0][3] = mat[0][1] + mat[0][2];
	mat[0][5] = mat[0][3] - mat[0][1];
	mat[0][4] = mat[0][5] - mat[0][2];

	for (int i = 1; i < num; i++)
	{
		temp = mat[i - 1][3];
		int low = mat[i][2];
		for (int j = i; j < num; j++)
		{
			if (temp >= mat[j][1] && low >= mat[j][2])
			{
				low = mat[j][2];
				val = j;
			}
		}
		mat[val][3] = temp + mat[val][2];
		mat[val][5] = mat[val][3] - mat[val][1];
		mat[val][4] = mat[val][5] - mat[val][2];
		for (int k = 0; k < 6; k++)
		{
			swap(mat[val][k], mat[i][k]);
		}
	}
}

int main()
{
	int num = 4, temp;
	int mat[10][6];
//first input
	mat[0][0] = 0;
	mat[0][1] = 0;
	mat[0][2] = 5;
	// second input
	mat[1][0] = 1;
	mat[1][1] = 1;
	mat[1][2] = 3;
	// third input
	mat[2][0] = 2;
	mat[2][1] = 2;
	mat[2][2] = 8;
	// fourth input
	mat[3][0] = 3;
	mat[3][1] = 3;
	mat[3][2] = 6;

	cout << "Before Arrange...\n";
	cout << "Process ID\tArrival Time\tBurst Time\n";
	for (int i = 0; i < num; i++)
	{
		cout << mat[i][0] << "\t\t\t\t\t" << mat[i][1] << "\t\t\t\t\t"
			 << mat[i][2] << "\n";
	}

	arrangeArrival(num, mat);
	completionTime(num, mat);
	cout << "Final Result...\n";
	cout << "Process ID\tArrival Time\tBurst Time\tWaiting "
			"Time\tTurnaround Time\n";
	for (int i = 0; i < num; i++)
	{
		cout << mat[i][0] << "\t\t\t\t" << mat[i][1] << "\t\t\t"
			 << mat[i][2] << "\t\t\t\t" << mat[i][4] << "\t\t\t\t"
			 << mat[i][5] << "\n";
	}
	float average_wait=0,average_turn;
	for (int i = 0; i < num; i++)
	{
		average_wait+=mat[i][4];
		average_turn+=mat[i][5];
	}
	average_wait/=num;
	average_turn/=num;
	cout<<"\nAverage Waiting time:"<<average_wait;
	cout<<"\nAverage Turn-around time:"<<average_turn;
}
