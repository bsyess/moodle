#include <cmath>
#include <iostream>

int main()
{
    long double eps = 1e-6;
    long double a, b, c, delta;

    std::cin >> a >> b >> c;

    delta = b * b - 4 * a * c;

    if (-delta >= eps)
        std::cout << "no root";
    else
    {
        long double sqrt_d = std::sqrt(delta);
        long double neg_2a = -2 * a;
        long double x1 = (b + sqrt_d) / neg_2a;
        long double x2 = (b - sqrt_d) / neg_2a;
        long double temp;

        if (x1 - x2 >= eps)
            temp = x1, x1 = x2, x2 = temp;
        if (std::abs(x1) < eps)
            x1 = 0;
        if (std::abs(x2) < eps)
            x2 = 0;

        std::cout << x1;
        if (x2 - x1 >= eps)
            std::cout << ' ' << x2;
    }

    return 0;
}