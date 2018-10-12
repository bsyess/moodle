#include <iomanip>
#include <iostream>

int id[4] = {10001, 10002, 10003};
int cl[4] = {11, 12, 11};
long double g1[4] = {99.5, 77.9, 92.5};
long double g2[4] = {88.5, 56.5, 99.0};
long double g3[4] = {89.5, 87.5, 60.5};

int main()
{
    std::cin >> id[3] >> cl[3] >> g1[3] >> g2[3] >> g3[3];

    if (id[3] >= 10001 && id[3] <= 10003)
        id[3] = 10000;
    for (int i = 3; i; --i)
        for (int j = 0; j < i; ++j)
            if (cl[j] == cl[j + 1] && g1[j] + g2[j] + g3[j] < g1[j + 1] + g2[j + 1] + g3[j + 1] || cl[j] > cl[j + 1])
            {
                int iT;
                long double fT;

                iT = id[j], id[j] = id[j + 1], id[j + 1] = iT;
                iT = cl[j], cl[j] = cl[j + 1], cl[j + 1] = iT;
                fT = g1[j], g1[j] = g1[j + 1], g1[j + 1] = fT;
                fT = g2[j], g2[j] = g2[j + 1], g2[j + 1] = fT;
                fT = g3[j], g3[j] = g3[j + 1], g3[j + 1] = fT;
            }

    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
    for (int i = 0; i < 4; ++i)
    {
        std::cout << id[i] << ' ' << cl[i] << ' ' << g1[i] << ' ' << g2[i] << ' ' << g3[i];
        if (id[i] < 10001 || id[i] > 10003)
            std::cout << " inserted";
        std::cout << '\n';
    }

    return 0;
}