#include <iostream>
#include <algorithm>
using namespace std;
long long int period_arr[100000000];
int arr[1000000] = {0};
int iterations = 0;
long long int gcde(long long int a, long long int b);
long long int gcd_of_bids();
void add_bid(long long int bid);
void useAP(int a, int d, int n);
void add_bid(long long int bid)
{
    period_arr[iterations] = bid;
    iterations++;
    return;
}

long long int gcd_of_bids()
{
    if (iterations == 1)
        return period_arr[0];
    long long int temp = gcde(period_arr[0], period_arr[1]);
    if (iterations == 2)
        return temp;
    for (int i = 1; i < iterations - 1; i++)
    {
        temp = gcde(temp, period_arr[i + 1]);
    }
    return temp;
}
void useAP(int a, int d, int n)
{
    if (a + d > n)
        return;
    for (int i = a + d; i <= n; i += d)
    {
        arr[i - 1] = 1;
    }
}
long long int gcde(long long int a, long long int b)
{
    if (a % b == 0)
        return b;
    else if (b % a == 0)
        return a;
    else if (b > a)
        return gcde(b % a, a);
    else
        return gcde(a % b, b);
}

void totalprime(int m, int n)
{
    int count = 0;
    arr[0] = 1;
    long long int period = 2;
    useAP(2, 2, n);
    for (long long int i = 2; i < n; i += 2)
    {
        if (gcde(period, (i + 1)) == 1)
        {
            period = period * (i + 1);
            if (iterations >= 1)
            {
                if (gcde(gcd_of_bids(), period) == 1)
                {
                    arr[i] = 1;
                }
            }
            else
                useAP(i + 1, period, n);
        }
        if (period >= n)
        {
            add_bid(period);
            period = i + 2;
        }
    }
}
long long int add_prime(int m, int n)
{
    long long int add = 0;
    for (int i = m - 1; i < n; i++)
    {
        if (arr[i] == 0)
            add += i + 1;
    }
    return add;
}
int main()
{
    totalprime(100, 10110);
    cout << "\nPrime sum:" << add_prime(100, 10110);
}