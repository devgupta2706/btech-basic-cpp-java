#include <bits/stdc++.h>
using namespace std;
void count_sort(int A[], int B[], int k, int n)
{
    int *C = new int[k];

    for (int i = 0; i < k; i++)
        C[i] = 0;
    for (int j = 0; j < n; j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }
    for (int i = 1; i < k; i++)
        C[i] = C[i] + C[i - 1];
    for (int j = n - 1; j >= 0; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    delete[] C;
}
int main()
{
    int A[] = {2, 5, 3, 0, 2, 3, 0, 3,15,24};
    int n = sizeof(A) / sizeof(int);
    int B[n + 1];
    int minn = A[0], maxx = A[0];
    for (int i = 1; i <= n; i++)
    {
        if (A[i] < minn)
            minn = A[i];
        if (A[i] > maxx)
            maxx = A[i];
    }
    count_sort(A, B, maxx-minn, n);
    for (int i = 1; i <= n; i++)
        cout << B[i] << " ";
    return 0;
}