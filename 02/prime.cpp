#include <iomanip>
#include <iostream>

bool comp[1001];

int main()
{
    int nol = 0;

    for (int i = 2; i < 32; ++i)
        if (!comp[i])
        {
            std::cout << std::setw(5) << i << (++nol % 5 ? "" : "\n");
            for (int j = i << 1; j < 1001; j += i)
                comp[j] = true;
        }

    for (int i = 37; i < 1000; ++i)
        if (!comp[i])
            std::cout << std::setw(5) << i << (++nol % 5 ? "" : "\n");

    return 0;
}