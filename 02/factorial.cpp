#include <iostream>

int main()
{
    long long n, twos = 0, fives = 0;

    std::cin >> n;

    if (n > 4)
    {
        while (n)
        {
            long long m = n--;
            while ((m & 1) == 0)
            {
                m >>= 1;
                ++twos;
            }
            while (m % 5 == 0)
            {
                m /= 5;
                ++fives;
            }
        }
        if (fives < twos)
            twos = fives;
    }

    std::cout << twos;

    return 0;
}