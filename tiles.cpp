#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int tiles_count(int n, int r, int b, int g)
{
    int reached;
    int limit = min(n, min(b, r));
    int column = limit;
    r = r - limit;
    b = b - limit;
    int count = r + b + g;
    if (count >= limit)
        return limit;
    while (1)
    {
        if (column == count)
        {
            reached = column;
            break;
        }
        else if (count == column + 1)
        {
            reached = column;
            break;
        }
        else if (column == count + 1)
        {
            reached = count;
            break;
        }
        else
        {
            count += 2;
            column--;
        }
    }
    return reached;
}
int main()
{
    int n, r, b, g;
    n = 2;
    b = 2;
    r = 2;
    g = 0;
    // cin>>n>>r>>b>>g;
    cout << tiles_count(n, r, b, g);
    return 0;
}