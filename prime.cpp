#include <iostream>
#include <algorithm>
using namespace std;
long long int period_arr[100000000];
long long int iterations = 0;
long long int gcd_of_bids();
void add_bid(long long int bid);
long long int gcde(long long int a, long long int b);
int getAP(int a, int d, int n);
long long int totalprime(int n);

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

int getAP(int a, int d, int n)
{
    int terms = ((n - a) / d);
    return terms;
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

long long int totalprime(int n)
{
    int count = 0;
    long long int period = 2;
    count += getAP(2, 2, n);
    for (long long int i = 2; i < n; i += 2)
    {
        if (gcde(period, (i + 1)) == 1)
        {
            period = period * (i + 1);
            if (iterations >= 1)
            {
                if (gcde(gcd_of_bids(), period) == 1)
                {
                    count++;
                }
            }
            else
                count += getAP(i + 1, period, n);
        }
        if (period >= 10000000000000)
        {
            add_bid(period);
            period = i + 2;
        }
    }
    return n - count - 1;
}
int main()
{
    long long int n = 10000;
    cout << n;
    cout << "\nTotal prime Numbers:"
         << totalprime(n);
    return 0;
}
