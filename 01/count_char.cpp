#include <cstdlib>
#include <iostream>

int main()
{
    int digit = 0, alpha = 0, space = 0;

    while (std::cin)
    {
        char c = std::cin.get();

        if (isdigit(c))
            ++digit;
        else if (isalpha(c))
            ++alpha;
        else if (c == ' ')
            ++space;
    }

    std::cout << digit << ' ' << alpha << ' ' << space;

    return 0;
}