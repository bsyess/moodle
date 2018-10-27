#include <iostream>

int main()
{
    long long m, n = 1;
    std::cin >> m;
    while (m--)
    {
        n <<= 1;
        n %= 1000000;
    }
    std::cout << n - 1;
    return 0;
}
