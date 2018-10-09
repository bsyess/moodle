#include <iostream>

int main()
{
    int arr[9];
    size_t i = 0;

    while (i < 8)
        std::cin >> arr[++i];

    while (i)
        std::cout << arr[i--] << ' ';

    return 0;
}