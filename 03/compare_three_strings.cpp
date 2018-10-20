#include <iostream>

char const* max(char const* x, char const* y)
{
    char const* a = x;
    for (char const* b = y; *a && *b; ++a, ++b)
        if (*a != *b)
            return *a < *b ? y : x;
    return *a ? x : y;
}

int main()
{
    char a[16], b[16], c[16];

    std::cin.getline(a, 16);
    std::cin.getline(b, 16);
    std::cin.getline(c, 16);

    std::cout << max(a, max(b, c));

    return 0;
}
