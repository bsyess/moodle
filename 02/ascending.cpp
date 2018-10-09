#include <iostream>

int main()
{
    long double arr[10], num;
    size_t pos;

    for (size_t i = 0; (pos = i++) < 10; arr[pos] = num)
        for (std::cin >> num; pos > 0 && num < arr[pos - 1]; --pos)
            arr[pos] = arr[pos - 1];

    for (pos = 0; pos < 10; ++pos)
        std::cout << arr[pos] << ' ';

    return 0;
}