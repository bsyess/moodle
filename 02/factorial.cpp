#include <iostream>

int main()
{
    long long n, fives = 0;

    std::cin >> n;

    while (n > 4)
        for (long long m = n--; m % 5 == 0; m /= 5)
            ++fives;

    std::cout << fives;

    return 0;
}