#include <iostream>

int main()
{
    short n, p, sum = 0;

    for (std::cin >> n >> p; n; --n)
    {
        short pow = 1;

        for (short i = p; i; --i)
            pow *= n;
	sum += pow;
    }

    std::cout << sum;

    return 0;
}
