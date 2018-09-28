#include <iostream>

int main()
{
    int n;

    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = n - i; j; --j)
            std::cout << '.';
        for (int j = i; j; --j)
            std::cout << '*';
        std::cout << std::endl;
    }

    return 0;
}