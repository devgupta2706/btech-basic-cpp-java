#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void bucket_sort(float A[], int size)
{
    vector<float> B[size];
    for (int i = 0; i < size; i++)
    {
        int indx = size * A[i];
        B[indx].push_back(A[i]);
    }
    for (int i = 0; i < size; i++)
        sort(B[i].begin(), B[i].end());
    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < B[i].size(); j++)
            A[index++] = B[i][j];
}
int main()
{
    float arr[] = {.94, 0.57, 0.576, 0.345, 0.461};
    int n = sizeof(arr) / sizeof(float);
    cout << "Bucket sort\n";
    bucket_sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}