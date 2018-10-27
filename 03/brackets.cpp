#include <iostream>

int main()
{
    char S[10000] = {0}, s;
    size_t p = 0;

    while (std::cin >> s)
    {
        if (s == '(' || s == '[')
        {
            S[p++] = s;
        }
        else if (!p || S[p - 1] == '(' && s == ']' || S[p - 1] == '[' && s == ')')
        {
            std::cout << "No";
            return 0;
        }
        else
        {
            --p;
        }
    }
    std::cout << (p ? "No" : "Yes");
    return 0;
}
