#include <iostream>

int main()
{
    int n, inner = 0;

    std::cin >> n;

    int A[n];

    for (int i = 0; i < n; ++i)
        std::cin >> A[i];
    for (int a, i = 0; i < n; ++i)
    {
        std::cin >> a;
        inner += A[i] * a;
    }

    std::cout << inner;

    return 0;
}