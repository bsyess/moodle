#include <iostream>

int main()
{
    char choice;

    std::cin >> choice;

    std::cout << "                              1.Input" << std::endl;
    std::cout << "                              2.Output" << std::endl;
    std::cout << "                              3.Order" << std::endl;
    std::cout << "                              4.Quit" << std::endl;
    if(choice == 'i')
        std::cout << "You are trying to Input info";
    else if(choice == 'o')
        std::cout << "You are trying to Output info";
    else if(choice == 'm')
        std::cout << "You are trying to Make things ordered";
    else if(choice == 'q')
        std::cout << "You are about to Quit";
    else
        std::cout << "Wrong input";

    return 0;
}