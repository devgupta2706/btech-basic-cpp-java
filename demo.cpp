#include<iostream>
using namespace std;
int gcde(int a, int b)
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
int main()
{
    cout<<gcde(2,16);
}