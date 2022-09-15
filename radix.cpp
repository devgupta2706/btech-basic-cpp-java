#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void radix_sort(int A[], int B[], int k, int n, int exp)
{
    int a;
    int *C = new int[k];
    int p = pow(10, exp);
    int p2 = pow(10, exp - 1);
    for (int i = 0; i < k; i++)
        C[i] = 0;
    for (int j = 0; j < n; j++)
    {
        a = ((A[j] % p) / p2);
        C[a] = C[a] + 1;
    }
    for (int i = 1; i < k; i++)
        C[i] = C[i] + C[i - 1];
    for (int j = n - 1; j >= 0; j--)
    {
        a = ((A[j] % p) / p2);
        B[C[a]-1] = A[j];
        C[a] = C[a] - 1;
    }
    delete[] C;
}
int main()
{
    int A[] = {22, 15, 19, 34, 23,243};
    int n = sizeof(A) / sizeof(int);
    int maxx = A[0], digit = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] > maxx)
            maxx = A[i];
    }
    while (maxx)
    {
        digit++;
        maxx = maxx / 10;
    }
    int B[digit][n + 1], m;
    radix_sort(A, B[0], 10, n, 1);
    for (int i = 1; i < digit; i++)
    {
        radix_sort(B[i - 1], B[i], 10, n, i + 1);
    }
    for (int i = 0; i < n; i++)
        cout << B[digit - 1][i] << " ";
    return 0;
}