#include <iostream>

int A[3][3], B[3][3];

int main()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            std::cin >> A[i][j];

    for (int i = 0; i < 3; ++i)
        for (int a, j = 0; j < 3; ++j)
        {
            std::cin >> a;
            for (int k = 0; k < 3; ++k)
                B[k][j] += A[k][i] * a;
        }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            std::cout << (j ? " " : "") << B[i][j];
        std::cout << std::endl;
    }

    return 0;
}