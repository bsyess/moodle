#include <iostream>

int main()
{
    int a, b, c, t;

    std::cin >> a >> b >> c;

    if (b < a)
        t = a, a = b, b = t;
    if (c < b)
        t = b, b = c, c = t;
    if (b < a)
        t = a, a = b, b = t;

    std::cout << a << ' ' << b << ' ' << c;

    return 0;
}
