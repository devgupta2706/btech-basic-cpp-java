#include <bits/stdc++.h>
using namespace std;
void spiral(int *A, int r, int c)
{
    int max_i = r - 1;
    int min_i = 0;
    int max_j = c - 1;
    int min_j = 0;
    while (1)
    {
        if (min_i > max_i && max_j < min_j)
            break;

        for (int j = min_j; j <= max_j; j++)
            cout << A[min_i*(c-1)+j] << " ";
        min_i++;
        for (int i = min_i; i <= max_i; i++)
            cout << A[i*(c-1)+max_j] << " ";
        max_j--;
        for (int j = max_j; j >= min_j; j--)
            cout << A[max_i*(c-1)+j] << " ";
        max_i--;
        for (int i = max_i; i >= min_i; i--)
            cout << A[i*(c-1)+min_j] << " ";
        min_j++;
    }
}
int main()
{
    int m,n;
    cout << " Enter Number of rows and columns:";
    cin>>m>>n;
    int *A=new int[m*n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i*(n-1)+j] = rand() % 10;
        }
    }
    cout<<"Matrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i*(n-1)+j] << " ";
        }
        cout << "\n";
    }
    cout<<"\n\nSpiral :";
    spiral(A, m, n);
    return 0;
}