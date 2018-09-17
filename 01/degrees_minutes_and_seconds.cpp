#include <iostream>

int main()
{
    int degree, minute, second;

    std::cin >> degree >> minute >> second;

    std::cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = " << second / 3600.0L + minute / 60.0L + degree << " degrees";

    return 0;
}