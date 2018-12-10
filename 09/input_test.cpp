#include <iostream>
#include <sstream>

template<typename UnformattedInput>
std::string wtf(UnformattedInput& ui)
{
    std::string str;

    for (char ch; ui.get(ch);)
        if (ch != '\r')
            str += ch;

    return str;
}

int main()
{
    std::istringstream cin(wtf(std::cin));
    std::string str;

    for (int i = 0; i < 2; ++i)
    {
        cin >> str;
        std::cout << str << std::endl;
    }
    std::getline(cin, str);
    for (int i = 0; i < 2; ++i)
    {
        std::getline(cin, str);
        std::cout << str << std::endl;
    }

    return 0;
}
