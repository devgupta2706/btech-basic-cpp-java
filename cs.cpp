#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Job
{
    string job_name = "$";
    int deadline;
    int penalty;
    bool shld = 0;
};
void swap(Job *a, Job *b)
{
    Job t = *a;
    *a = *b;
    *b = t;
}
int partition(Job arr[], int low, int high)
{
    int pivot = arr[high].penalty;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].penalty >= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort_in_desc(Job arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort_in_desc(arr, low, pi - 1);
        quickSort_in_desc(arr, pi + 1, high);
    }
    return;
}
void print_scheduling(Job J[], int n)
{
    cout << "Task scheduled :";
    for (int i = 0; i < n; i++)
    {
        if (J[i].shld == true)
            cout << J[i].job_name << " ";
    }
    return;
}
void insert(Job J[], Job p)
{
    if (J[0].job_name == "$")
    {
        J[0] = p;
        J[0].shld = 1;
        if (p.deadline == 1)
            return;
    }
    for (int i = 1; i < p.deadline - 1; i++)
    {
        if (J[i].job_name == "$")
        {
            J[i] = p;
            if (p.job_name == J[i - 1].job_name)
            {
                J[i - 1].job_name = "$";
                J[i - 1].shld = 0;
            }
        }
    }
    return;
}
int penalties(Job J[], Job A[], int n)
{
    int count_pen = 0;
    for (int i = 0; i < n; i++)
    {
        if (J[i].shld == false)
            count_pen += A[i].penalty;
    }

    return count_pen;
}
int main()
{
    Job A[] = {
        {"a1", 4, 70, 1},
        {"a2", 2, 60, 1},
        {"a3", 4, 50, 1},
        {"a4", 3, 40, 1},
        {"a5", 1, 30, 1},
        {"a6", 4, 20, 1},
        {"a7", 6, 10, 1},
    };
    int n = sizeof(A) / sizeof(Job);
    Job schedule[n];
    quickSort_in_desc(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        insert(schedule, A[i]);
    }
    print_scheduling(schedule, n);
    cout << "\n Total penalty :" << penalties(schedule, A, n);
    return 0;
}