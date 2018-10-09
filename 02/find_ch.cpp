#include <iostream>

int main()
{
    char string[17], ch;

    std::cin.getline(string, 17);
    std::cin >> ch;

    for (size_t i = 0; string[i]; ++i)
        if (string[i] == ch)
        {
            std::cout << i + 1;
            return 0;
        }
    std::cout << 0;

    return 0;
}