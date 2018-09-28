#include <iostream>

int main()
{
    int n, a = 0, x = -1;

    std::cin >> n;

    int M[n][n], l = n, y = n - 1;
    while (true)
    {
        for (int i = l; i; --i)
            M[++x][y] = ++a;
        if (--l == 0)
            break;
        for (int i = l; i; --i)
            M[x][--y] = ++a;
        for (int i = l; i; --i)
            M[--x][y] = ++a;
        if (--l == 0)
            break;
        for (int i = l; i; --i)
            M[x][++y] = ++a;
    }

    for (x = 0; x < n; ++x)
    {
        for (y = 0; y < n; ++y)
            std::cout << (y ? " " : "") << M[x][y];
        std::cout << std::endl;
    }

    return 0;
}