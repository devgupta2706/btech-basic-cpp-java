#include <iostream>
#include <utility>


using namespace std;

long long int fib(long long int a, long long int b, unsigned int n)
{
    for(unsigned int i = 2; i < n; ++i)
    {
        long long int temp = a + b*b;
        a = b;
        b = temp;
    }
    return b;
}

int main()
{
    unsigned int a, b, n;

    std::cin >> a >> b >> n;
    std::cout << fib(a, b, n);
}