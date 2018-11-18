#include <iostream>

int main()
{
    int mod_three, mod_five, mod_seven;

    std::cin >> mod_three >> mod_five >> mod_seven;

    std::cout << (mod_three * 70 + mod_five * 21 + mod_seven * 15) % 105;

    return 0;
}
