#include <iostream>

bool lamp[1001];

int main()
{
    int n, k;

    std::cin >> n >> k;

    for (int i = 2; i <= k; ++i)
        for (int j = i; j <= n; j += i)
            lamp[j] = !lamp[j];

    for (int i = 1; i <= n; ++i)
        if (!lamp[i])
            std::cout << i << ' ';

    return 0;
}