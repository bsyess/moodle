#include <iostream>

int main()
{
    int n, x, sum = 0;

    std::cin >> n;

    while (n--)
    {
        std::cin >> x;
        sum += x;
    }

    std::cout << sum;

    return 0;
}