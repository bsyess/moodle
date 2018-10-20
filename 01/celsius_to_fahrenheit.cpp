#include <iostream>

long double toFahrenheit(long double celsius)
{
    return celsius * 1.8 + 32.0;
}

int main()
{
    long double celsius;

    std::cin >> celsius;

    std::cout << "Fahrenheit temperature is " << toFahrenheit(celsius) << " degree";

    return 0;
}
