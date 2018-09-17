#include <iostream>

int main()
{
    int a, b, mul, t;

    std::cin >> a >> b;

    mul = a * b;
    while (a != 0)
    {
        t = b % a;
        b = a;
        a = t;
    }

    std::cout << b << ' ' << mul / b;

    return 0;
}