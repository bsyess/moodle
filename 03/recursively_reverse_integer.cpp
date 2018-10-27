#include <iostream>

size_t reverse(size_t number, size_t temp = 0)
{
    return number ? reverse(number / 10, temp * 10 + number % 10) : temp;
}

int main()
{
    size_t number;
    std::cin >> number;
    std::cout << reverse(number);
    return 0;
}
