#include <iostream>

int main()
{
    char a[15], b[15];
    size_t i = 0;

    std::cin.getline(a, 15);
    std::cin.getline(b, 15);

    while (a[i] && b[i])
    {
        if (a[i] != b[i])
        {
            std::cout << i + 1;
            return 0;
        }
        ++i;
    }
    std::cout << (a[i] || b[i] ? i + 1 : 0);

    return 0;
}