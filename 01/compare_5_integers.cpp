#include <iostream>

int main()
{
    int a, b, c, d, e, t;

    std::cin >> a >> b >> c >> d >> e;

    if(b < a)
        t = a, a = b, b = t;
    if(d < c)
        t = c, c = d, d = t;
    if(c < a)
        a = c;
    if(b < d)
        b = d;
    if(e < a)
        a = e;
    else if(b < e)
        b = e;

    std::cout << a << ' ' << b;

    return 0;
}
