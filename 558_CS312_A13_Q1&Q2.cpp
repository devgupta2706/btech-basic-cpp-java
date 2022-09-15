#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int M[50][50], S[50][50];
int dp[50][50];
int matrixChainMemoised(int *p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int *p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}
void matrix_chain_bottomup(int P[], int n)
{
    int j, q;
    for (int i = 0; i <= n; i++)
    {
        M[i][i] = 0;
    }

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                q = M[i][k] + M[k + 1][j] + P[i - 1] * P[k] * P[j];
                if (q < M[i][j])
                {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}
void print_optimal_subsequence(int i, int j)
{
    if (i == j)
        cout << "A[" << i << "]";
    else
    {
        cout << "(";
        print_optimal_subsequence(i, S[i][j]);
        print_optimal_subsequence(S[i][j] + 1, j);
        cout << ")";
    }
    return;
}

int main()
{
    int p[] = {5, 4, 6, 2, 7};
    int size = sizeof(p) / sizeof(p[0]);
    cout << "\nMatrix chain Multiplication Bottom-up approach\n";
    matrix_chain_bottomup(p, size - 1);
    print_optimal_subsequence(1, size - 1);
    cout << "\nMinimum number of multiplications is "
         << M[1][size - 1];

    memset(dp, -1, sizeof(dp));
    cout << "\n\nMatrix chain Multiplication Topdown approach\n";
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(p, size) << "\n";
    print_optimal_subsequence(1, size - 1);

    return 0;
}