#include <iostream>

int main()
{
    int a, b, t;

    std::cin >> a >> b;

    if(b < a)
        t = a, a = b, b = t;

    std::cout << a << ' ' << b;

    return 0;
}
