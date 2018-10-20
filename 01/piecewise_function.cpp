#include <iostream>

int f(int x)
{
    return x ? x > 0 ? x * 3.0 + 1.0 : x * x - 1 : 0;
}

int main()
{
    int x;

    std::cin >> x;

    std::cout << f(x);

    return 0;
}
