#include <iomanip>
#include <iostream>

bool comp[1001]{true, true};

int main()
{
    for (int i = 2; i < 32; ++i)
        if (!comp[i])
            for (int j = i << 1; j < 1001; j += i)
                comp[j] = true;

    int a, n, sum = 0;

    std::cin >> n;

    while (n--)
    {
        std::cin >> a;
        if (!comp[a])
            sum += a;
    }

    std::cout << sum;

    return 0;
}