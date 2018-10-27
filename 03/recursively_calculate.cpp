#include <iostream>

int main()
{
    long long f1, f2, a, b, c, n;
    std::cin >> f1 >> f2 >> a >> b >> c >> n;
    if (n == 1)
    {
        std::cout << f1;
        return 0;
    }
    for (long long temp; n > 2; --n)
    {
        temp = (a * f1 + b * f2 + c + 1000007000) % 1000007;
        f1 = f2;
        f2 = temp;
    }
    std::cout << f2;
    return 0;
}
