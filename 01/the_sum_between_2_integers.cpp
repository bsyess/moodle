#include <iostream>

int main()
{
    int first, last;

    std::cin >> first >> last;

    std::cout << (first + last) * (last + 1 - first) / 2;

    return 0;
}