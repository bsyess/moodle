#include <iostream>

int main()
{
    unsigned long long n, factorial = 1;

    std::cin >> n;

    while (n)
        factorial *= n--;

    std::cout << factorial;

    return 0;
}