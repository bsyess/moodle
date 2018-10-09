#include <cstring>
#include <iostream>

int main()
{
    char string[17];
    size_t count = 0;

    std::cin.getline(string, 17);

    while (string[count])
        ++count;

    std::cout << count - 1;

    return 0;
}