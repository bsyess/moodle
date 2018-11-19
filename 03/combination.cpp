#include <iostream>

void C(int n, int r, int c = 0)
{
    if (r)
    {
        C(n - 1, r - 1, c * 10 + n);
        if (r < n)
            C(n - 1, r, c);
    }
    else
        std::cout << c << std::endl;
}

int main()
{
    unsigned short n, r;
    std::cin >> n >> r;
    C(n, r);
    return 0;
}
