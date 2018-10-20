#include <cctype>
#include <iostream>

int main()
{
    char string[64];
    size_t space = 0, capital = 0, lowercase = 0, number = 0;

    std::cin.getline(string, 64);

    for (char const* p = string; *p; ++p)
    {
        if (*p == ' ')
            ++space;
        else if (std::isupper(*p))
            ++capital;
        else if (std::islower(*p))
            ++lowercase;
    	else if (std::isdigit(*p))
            ++number;
    }

    std::cout << "space: " << space << "\ncapital: " << capital << "\nlowercase: " << lowercase << "\nnumber: " << number;

    return 0;
}
