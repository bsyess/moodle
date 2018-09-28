#include <iostream>

long long fib[50]{0, 1};

int main()
{
    int n;

    std::cin >> n;

    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    std::cout << fib[n];

    return 0;
}