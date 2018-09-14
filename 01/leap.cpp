#include <iostream>

int main()
{
    int year;
    char output;

    std::cin >> year;

    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        output = 'Y';
    else
        output = 'N';

    std::cout << output;

    return 0;
}
