#include <cstring>
#include <iostream>

std::string& toupper(std::string& str)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        str[i] = std::toupper(str[i]);
    }
    return str;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    std::cout << toupper(str);
    return 0;
}
